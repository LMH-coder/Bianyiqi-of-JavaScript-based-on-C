#ifndef PARSER_DRIVER_H
#define PARSER_DRIVER_H

#include <stdio.h>
#include <stdint.h>
#include <stddef.h>

typedef struct {
  const char *filename;
  const char *buf;      // input buffer
  size_t      len;
  size_t      pos;

  int line;
  int col;

  int has_line_terminator; // set by lexer when a LineTerminator occurred between tokens

  // for error reporting
  int err_line;
  int err_col;
  char err_msg[256];
} ParserDriver;

// API
int parse_buffer(ParserDriver *drv);
int parse_file(const char *path);

#endif
