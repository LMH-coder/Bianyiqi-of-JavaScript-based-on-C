#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#ifdef _WIN32
#include <windows.h>
#endif
#include <errno.h>
#include "parser_driver.h"

#ifdef _WIN32
#define PATH_SEP '\\'
#else
#define PATH_SEP '/'
#endif

static int file_exists(const char *p) {
  struct stat st;
  return stat(p, &st) == 0 && (st.st_mode & S_IFREG);
}

static int dir_exists(const char *p) {
  struct stat st;
  return stat(p, &st) == 0 && (st.st_mode & S_IFDIR);
}

static void path_join3(char *out, size_t outsz, const char *a, const char *b, const char *c) {
  // join a/b/c with proper separators
  char tmp[1024];
  size_t n = 0;
  out[0] = 0;
  if (a && *a) {
    n = snprintf(tmp, sizeof(tmp), "%s", a);
  } else {
    tmp[0] = 0; n = 0;
  }
  if (b && *b) {
    if (n && tmp[n-1] != PATH_SEP) tmp[n++] = PATH_SEP, tmp[n] = 0;
    n += (size_t)snprintf(tmp + n, sizeof(tmp) - n, "%s", b);
  }
  if (c && *c) {
    if (n && tmp[n-1] != PATH_SEP) tmp[n++] = PATH_SEP, tmp[n] = 0;
    n += (size_t)snprintf(tmp + n, sizeof(tmp) - n, "%s", c);
  }
  tmp[sizeof(tmp)-1] = 0;
  snprintf(out, outsz, "%s", tmp);
}

static void path_dirname(const char *path, char *out, size_t outsz) {
  size_t len = strlen(path);
  if (len == 0) { out[0] = 0; return; }
  const char *end = path + len;
  const char *p = end - 1;
  while (p >= path && *p != '/' && *p != '\\') p--;
  if (p < path) { out[0] = 0; return; }
  size_t n = (size_t)(p - path);
  if (n >= outsz) n = outsz - 1;
  memcpy(out, path, n);
  out[n] = 0;
}

static void path_parent(const char *path, char *out, size_t outsz) {
  char dir[1024];
  path_dirname(path, dir, sizeof(dir));
  path_dirname(dir, out, outsz);
}

static void get_exe_dir(char *out, size_t outsz, const char *argv0) {
#ifdef _WIN32
  char buf[MAX_PATH];
  DWORD n = GetModuleFileNameA(NULL, buf, (DWORD)sizeof(buf));
  if (n > 0 && n < sizeof(buf)) {
    path_dirname(buf, out, outsz);
    return;
  }
#else
  char buf[1024];
  ssize_t n = readlink("/proc/self/exe", buf, sizeof(buf)-1);
  if (n > 0) {
    buf[n] = 0;
    path_dirname(buf, out, outsz);
    return;
  }
#endif
  // fallback: use argv0's directory (may be relative)
  if (argv0 && *argv0) {
    path_dirname(argv0, out, outsz);
  } else {
    out[0] = 0;
  }
}

static int has_ext(const char *name, const char *ext) {
  const char *dot = strrchr(name, '.');
  if (!dot) return 0;
#ifdef _WIN32
  // case-insensitive on Windows
  return _stricmp(dot, ext) == 0;
#else
  return strcmp(dot, ext) == 0;
#endif
}

#ifdef _WIN32
#include <io.h>
#include <direct.h>

static int run_dir(const char *dir, const char *ext, int expect_ok, int *ok, int *bad) {
  char pattern[1024];
  snprintf(pattern, sizeof(pattern), "%s\\*%s", dir, ext);
  WIN32_FIND_DATAA ffd;
  HANDLE hFind = FindFirstFileA(pattern, &ffd);
  if (hFind == INVALID_HANDLE_VALUE) {
    // no match is not an error; but also could be dir missing
    if (!dir_exists(dir)) return -1; // dir not found
    return 0;
  }
  do {
    if (ffd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) continue;
    char filepath[1024];
    snprintf(filepath, sizeof(filepath), "%s\\%s", dir, ffd.cFileName);
    int rc = parse_file(filepath);
    if (expect_ok) {
      if (rc == 0) (*ok)++;
      else { (*bad)++; fprintf(stderr, "FAIL(valid): %s\n", filepath); }
    } else {
      if (rc != 0) (*ok)++;
      else { (*bad)++; fprintf(stderr, "Unexpected OK: %s\n", filepath); }
    }
  } while (FindNextFileA(hFind, &ffd));
  FindClose(hFind);
  return 0;
}

#else
#include <dirent.h>

static int run_dir(const char *dir, const char *ext, int expect_ok, int *ok, int *bad) {
  DIR *d = opendir(dir);
  if (!d) return -1;
  struct dirent *ent;
  while ((ent = readdir(d)) != NULL) {
    if (ent->d_name[0] == '.') continue;
    char filepath[1024];
    path_join3(filepath, sizeof(filepath), dir, ent->d_name, NULL);
    struct stat st;
    if (stat(filepath, &st) != 0) continue;
#if defined(S_IFREG)
    if (!(st.st_mode & S_IFREG)) continue;
#endif
    if (!has_ext(ent->d_name, ext)) continue;
    int rc = parse_file(filepath);
    if (expect_ok) {
      if (rc == 0) (*ok)++;
      else { (*bad)++; fprintf(stderr, "FAIL(valid): %s\n", filepath); }
    } else {
      if (rc != 0) (*ok)++;
      else { (*bad)++; fprintf(stderr, "Unexpected OK: %s\n", filepath); }
    }
  }
  closedir(d);
  return 0;
}
#endif

static int run_all_tests(const char *argv0) {
  // locate test root: prefer <exe_dir>/../test, fallback to <exe_dir>/test, fallback to ./test, or env JSPARSER_TEST_ROOT
  char exe_dir[1024]; get_exe_dir(exe_dir, sizeof(exe_dir), argv0);

  const char *env = getenv("JSPARSER_TEST_ROOT");
  char env_buf[1024];
  if (env && *env) {
    snprintf(env_buf, sizeof(env_buf), "%s", env);
  }

  // use parent of exe_dir as project root (one level up, not two)
  char root_parent[1024];
  path_dirname(exe_dir, root_parent, sizeof(root_parent)); // FIX: use dirname, not parent-of-parent

  char test1[1024]; path_join3(test1, sizeof(test1), root_parent, "test", NULL); // <root>/test
  char test2[1024]; path_join3(test2, sizeof(test2), exe_dir, "test", NULL);     // <exe_dir>/test

  const char *test_root = NULL;
  if (env && *env && dir_exists(env_buf)) test_root = env_buf;
  else if (dir_exists(test1)) test_root = test1;
  else if (dir_exists(test2)) test_root = test2;
  else if (dir_exists("test")) test_root = "test";
  else {
    fprintf(stderr, "Cannot find test directory. Tried:\n  %s\n  %s\n  ./test\n", test1, test2);
    return 2;
  }

  char valid_dir[1024], invalid_dir[1024], vb_dir[1024];
  path_join3(valid_dir, sizeof(valid_dir), test_root, "js", "valid");
  path_join3(invalid_dir, sizeof(invalid_dir), test_root, "js", "invalid");
  path_join3(vb_dir, sizeof(vb_dir), test_root, "vb", NULL);

  int ok_v=0, bad_v=0, ok_i=0, bad_i=0, ok_vb=0, bad_vb=0;

  printf("== Running tests under: %s ==\n", test_root);

  if (dir_exists(valid_dir)) {
    printf("-- JS valid: %s\n", valid_dir);
    if (run_dir(valid_dir, ".js", 1, &ok_v, &bad_v) < 0) {
      printf("  (no .js files)\n");
    }
  } else {
    printf("-- JS valid dir not found: %s\n", valid_dir);
  }

  if (dir_exists(invalid_dir)) {
    printf("-- JS invalid: %s\n", invalid_dir);
    if (run_dir(invalid_dir, ".js", 0, &ok_i, &bad_i) < 0) {
      printf("  (no .js files)\n");
    }
  } else {
    printf("-- JS invalid dir not found: %s\n", invalid_dir);
  }

  if (dir_exists(vb_dir)) {
    printf("-- VB invalid: %s\n", vb_dir);
#ifdef _WIN32
    // *.vb pattern handled in run_dir by ext filter ".vb"
#endif
    if (run_dir(vb_dir, ".vb", 0, &ok_vb, &bad_vb) < 0) {
      printf("  (no .vb files)\n");
    }
  } else {
    printf("-- VB dir not found: %s (skipped)\n", vb_dir);
  }

  printf("\n== Summary ==\n");
  printf("JS valid  : passed %d, failed %d\n", ok_v, bad_v);
  printf("JS invalid: rejected %d, unexpected OK %d\n", ok_i, bad_i);
  printf("VB        : rejected %d, unexpected OK %d\n", ok_vb, bad_vb);

  int failures = bad_v + bad_i + bad_vb;
  if (failures == 0) {
    printf("\nAll tests passed.\n");
  } else {
    printf("\nThere are %d failing cases.\n", failures);
  }
  return failures ? 1 : 0;
}

// CLI: ./jsparser file.js   or   double-click/no-args -> run tests
int main(int argc, char **argv) {
  if (argc == 2) {
    int rc = parse_file(argv[1]);
    if (rc == 0) {
      printf("OK\n");
      return 0;
    } else if (rc == 1) {
      return 1;
    } else {
      fprintf(stderr, "Internal or IO error.\n");
      return 2;
    }
  }

  int rc = run_all_tests(argc > 0 ? argv[0] : NULL);

#ifdef _WIN32
  // if launched by double-click, keep window open
  printf("\nPress Enter to exit...");
  fflush(stdout);
  getchar();
#endif

  return rc;
}
