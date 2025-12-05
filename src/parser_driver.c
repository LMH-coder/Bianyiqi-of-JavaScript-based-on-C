#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser_driver.h"

/* Bison / scanner interface */
int yyparse(void *scanner, ParserDriver *drv);
int yylex_init_extra(ParserDriver *drv, void **scanner);
int yylex_destroy(void *scanner);
int yy_scan_bytes(const char *bytes, size_t len, void *scanner);
void yyset_in(FILE *in_str, void *scanner);

/* Detect BOM and convert buffer to UTF-8 (ASCII subset) if needed.
   - UTF-8 (with/without BOM): keep as is (strip BOM if present).
   - UTF-16 LE/BE: convert U+0000..U+007F to single byte; others -> '?'.
   Return 0 on success; -1 on IO; -2 on alloc. */
static int load_file_normalized(const char *path, char **out_buf, size_t *out_len) {
  *out_buf = NULL; *out_len = 0;

  FILE *f = fopen(path, "rb");
  if (!f) return -1;

  if (fseek(f, 0, SEEK_END) != 0) { fclose(f); return -1; }
  long sz = ftell(f);
  if (sz < 0) { fclose(f); return -1; }
  if (fseek(f, 0, SEEK_SET) != 0) { fclose(f); return -1; }

  size_t n = (size_t)sz;
  unsigned char *buf = (unsigned char*)malloc(n + 4);
  if (!buf) { fclose(f); return -2; }
  size_t m = fread(buf, 1, n, f);
  fclose(f);
  buf[m] = 0; buf[m+1] = 0; buf[m+2] = 0; buf[m+3] = 0; /* guard */

  /* Detect BOM */
  if (m >= 3 && buf[0] == 0xEF && buf[1] == 0xBB && buf[2] == 0xBF) {
    /* UTF-8 BOM: strip */
    size_t outn = m - 3;
    char *out = (char*)malloc(outn + 2);
    if (!out) { free(buf); return -2; }
    memcpy(out, buf + 3, outn);
    free(buf);
    *out_buf = out;
    *out_len = outn;
    return 0;
  } else if (m >= 2 && buf[0] == 0xFF && buf[1] == 0xFE) {
    /* UTF-16 LE */
    const unsigned char *p = buf + 2;
    size_t u16_len = (m - 2) / 2;
    char *out = (char*)malloc(u16_len + 2);
    if (!out) { free(buf); return -2; }
    size_t oi = 0;
    for (size_t i = 0; i < u16_len; i++) {
      unsigned char lo = p[i*2 + 0];
      unsigned char hi = p[i*2 + 1];
      char ch = '?';
      if (hi == 0) ch = (char)lo;   /* ASCII */
      else if (lo == 0) {
        /* BE-like in LE stream? unlikely; map to '?' */
        ch = '?';
      } else {
        ch = '?';
      }
      out[oi++] = ch;
    }
    free(buf);
    *out_buf = out;
    *out_len = oi;
    return 0;
  } else if (m >= 2 && buf[0] == 0xFE && buf[1] == 0xFF) {
    /* UTF-16 BE */
    const unsigned char *p = buf + 2;
    size_t u16_len = (m - 2) / 2;
    char *out = (char*)malloc(u16_len + 2);
    if (!out) { free(buf); return -2; }
    size_t oi = 0;
    for (size_t i = 0; i < u16_len; i++) {
      unsigned char hi = p[i*2 + 0];
      unsigned char lo = p[i*2 + 1];
      char ch = '?';
      if (lo == 0) ch = (char)hi;   /* ASCII */
      else if (hi == 0) {
        /* LE-like in BE stream? unlikely; map to '?' */
        ch = '?';
      } else {
        ch = '?';
      }
      out[oi++] = ch;
    }
    free(buf);
    *out_buf = out;
    *out_len = oi;
    return 0;
  } else {
    /* Assume UTF-8 (no BOM) */
    char *out = (char*)malloc(m + 2);
    if (!out) { free(buf); return -2; }
    memcpy(out, buf, m);
    free(buf);
    *out_buf = out;
    *out_len = m;
    return 0;
  }
}

/* parse a buffer */
int parse_buffer(ParserDriver *drv) {
  void *scanner = NULL;
  if (yylex_init_extra(drv, &scanner) != 0) return 2;

  /* Our re2c scanner uses drv->buf directly; stubs keep API symmetric. */
  yy_scan_bytes(drv->buf, drv->len, scanner);

  int rc = yyparse(scanner, drv);

  yylex_destroy(scanner);
  if (rc == 0) return 0; /* OK */

  if (drv->err_msg[0] != '\0') {
    fprintf(stderr, "Syntax error at %s:%d:%d: %s\n",
            drv->filename ? drv->filename : "<stdin>",
            drv->line, drv->col, drv->err_msg);
  } else {
    fprintf(stderr, "Syntax error at %s:%d:%d\n",
            drv->filename ? drv->filename : "<stdin>", drv->line, drv->col);
  }
  return 1;
}

/* parse a file (with BOM/UTF-16 handling) */
int parse_file(const char *path) {
  char *raw = NULL; size_t raw_len = 0;
  int lr = load_file_normalized(path, &raw, &raw_len);
  if (lr == -1) { perror("fopen"); return 2; }
  if (lr == -2) { fprintf(stderr, "Out of memory\n"); return 2; }

  /* append a sentinel newline (helps ASI at EOF) and NUL */
  char *buf = (char*)malloc(raw_len + 2);
  if (!buf) { free(raw); return 2; }
  memcpy(buf, raw, raw_len);
  buf[raw_len] = '\n';
  buf[raw_len + 1] = '\0';
  free(raw);

  ParserDriver drv;
  memset(&drv, 0, sizeof(drv));
  drv.filename = path;
  drv.buf = buf;
  drv.len = raw_len + 1; /* do not include NUL */
  drv.pos = 0;
  drv.line = 1;
  drv.col = 1;
  drv.err_line = 1;
  drv.err_col = 1;
  drv.has_line_terminator = 0;

  int rc = parse_buffer(&drv);
  free(buf);
  return rc;
}
