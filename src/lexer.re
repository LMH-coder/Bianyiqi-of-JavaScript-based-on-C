/*
 * re2c-based lexer for a JS subset (LALR 版本，三参 yylex)
 * - Tracks line/col and LineTerminator presence between tokens (for ASI).
 * - Skips whitespace/comments; sets drv->has_line_terminator when a line break is seen before the next token.
 * - Skips UTF-8 BOM (EF BB BF) at file start or between tokens.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "tokens.h"
#include "parser_driver.h"
#include "parser.h"  /* for T_* token macros */

typedef struct {
  const char *cursor;
  const char *limit;
  const char *marker;
  const char *tok_start;
} YYCTX;

static void advance_line(ParserDriver *drv) { drv->line++; drv->col = 1; }
static void advance_cols(ParserDriver *drv, int n) { drv->col += n; }

static int kw(const char *s, int len) {
  #define KW(x, tok) if (len==(int)sizeof(x)-1 && memcmp(s,x,len)==0) return tok
  KW("var", T_K_VAR);
  KW("let", T_K_LET);
  KW("const", T_K_CONST);
  KW("function", T_K_FUNCTION);
  KW("return", T_K_RETURN);
  KW("if", T_K_IF);
  KW("else", T_K_ELSE);
  KW("while", T_K_WHILE);
  KW("do", T_K_DO);
  KW("for", T_K_FOR);
  KW("break", T_K_BREAK);
  KW("continue", T_K_CONTINUE);
  KW("throw", T_K_THROW);
  KW("try", T_K_TRY);
  KW("catch", T_K_CATCH);
  KW("finally", T_K_FINALLY);
  KW("true", T_K_TRUE);
  KW("false", T_K_FALSE);
  KW("null", T_K_NULL);
  KW("new", T_K_NEW);
  KW("this", T_K_THIS);
  KW("typeof", T_K_TYPEOF);
  KW("void", T_K_VOID);
  KW("delete", T_K_DELETE);
  KW("in", T_K_IN);
  KW("instanceof", T_K_INSTANCEOF);
  KW("switch", T_K_SWITCH);
  KW("case", T_K_CASE);
  KW("default", T_K_DEFAULT);
  KW("debugger", T_K_DEBUGGER);
  KW("of", T_K_OF);
  #undef KW
  return 0;
}

/* LALR 下 bison 调 yylex(YYSTYPE*, scanner, drv)：三参版本 */
int yylex(int *yylval, void *scanner, ParserDriver *drv) {
  (void)yylval; (void)scanner;
  YYCTX ctx;
  ctx.cursor = drv->buf + drv->pos;
  ctx.limit  = drv->buf + drv->len;
  ctx.marker = ctx.cursor;

  int saw_line = 0;

  // Skip whitespace and comments; record if any LineTerminator encountered
  for (;;) {
    if (ctx.cursor >= ctx.limit) break;
    unsigned char c = (unsigned char)*ctx.cursor;

    // UTF-8 BOM (EF BB BF) treated as whitespace; keep column unchanged
    if (c==0xEF && (ctx.cursor+2)<ctx.limit &&
        (unsigned char)ctx.cursor[1]==0xBB &&
        (unsigned char)ctx.cursor[2]==0xBF) {
      ctx.cursor += 3;
      drv->pos   += 3;
      continue;
    }

    // spaces and tabs and other non-LT whitespace
    if (c==' ' || c=='\t' || c=='\r' || c=='\f' || c==0x0b) {
      ctx.cursor++; drv->pos++; advance_cols(drv, 1); continue;
    }
    // newline as line terminator
    if (c=='\n') {
      ctx.cursor++; drv->pos++; advance_line(drv); saw_line = 1; continue;
    }
    // single-line comment //
    if (c=='/' && (ctx.cursor+1)<ctx.limit && ctx.cursor[1]=='/') {
      ctx.cursor += 2; drv->pos += 2; advance_cols(drv, 2);
      while (ctx.cursor < ctx.limit && *ctx.cursor != '\n') {
        ctx.cursor++; drv->pos++; advance_cols(drv, 1);
      }
      continue;
    }
    // multi-line comment /* ... */
    if (c=='/' && (ctx.cursor+1)<ctx.limit && ctx.cursor[1]=='*') {
      ctx.cursor += 2; drv->pos += 2; advance_cols(drv, 2);
      while (ctx.cursor < ctx.limit) {
        unsigned char d = (unsigned char)*ctx.cursor;
        if (d == '\n') { ctx.cursor++; drv->pos++; advance_line(drv); saw_line = 1; continue; }
        if (d=='*' && (ctx.cursor+1)<ctx.limit && ctx.cursor[1]=='/') {
          ctx.cursor += 2; drv->pos += 2; advance_cols(drv, 2);
          break;
        }
        ctx.cursor++; drv->pos++; advance_cols(drv, 1);
      }
      continue;
    }
    break;
  }

  drv->has_line_terminator = saw_line ? 1 : 0;

  if (ctx.cursor >= ctx.limit) {
    drv->pos = (size_t)(ctx.cursor - drv->buf);
    return 0; /* EOF */
  }

  drv->pos = (size_t)(ctx.cursor - drv->buf);
  ctx.tok_start = ctx.cursor;

  /*!re2c
    re2c:define:YYCTYPE = "unsigned char";
    re2c:define:YYCURSOR = ctx.cursor;
    re2c:define:YYLIMIT = ctx.limit;
    re2c:define:YYMARKER = ctx.marker;
    re2c:yyfill:enable = 0;

    IDENT_START  = [_$A-Za-z];
    IDENT_PART   = [_$A-Za-z0-9];
    DEC_DIGIT    = [0-9];
    HEX_DIGIT    = [0-9A-Fa-f];

    STR_SQ      = "'" ( [^'\\\n] | "\\" . )* "'";
    STR_DQ      = "\"" ( [^"\\\n] | "\\" . )* "\"";

    NUM_DEC     = [0-9]+ ("." [0-9]+)?;
    NUM_HEX     = "0x" HEX_DIGIT+;
    NUM_BIN     = "0b" [01]+;
    NUM_OCT     = "0o" [0-7]+;

    "==="      { drv->pos += 3; advance_cols(drv,3); return T_STRICT_EQ; }
    "!=="      { drv->pos += 4; advance_cols(drv,4); return T_STRICT_NEQ; }
    ">>>"      { drv->pos += 3; advance_cols(drv,3); return T_USHR; }
    ">>="      { drv->pos += 3; advance_cols(drv,3); return T_SHR_ASSIGN; }
    "<<="      { drv->pos += 3; advance_cols(drv,3); return T_SHL_ASSIGN; }
    ">>>="     { drv->pos += 4; advance_cols(drv,4); return T_USHR_ASSIGN; }
    "&&"       { drv->pos += 2; advance_cols(drv,2); return T_AND; }
    "||"       { drv->pos += 2; advance_cols(drv,2); return T_OR;  }
    "=="       { drv->pos += 2; advance_cols(drv,2); return T_EQ; }
    "!="       { drv->pos += 2; advance_cols(drv,2); return T_NEQ; }
    "<="       { drv->pos += 2; advance_cols(drv,2); return T_LTE; }
    ">="       { drv->pos += 2; advance_cols(drv,2); return T_GTE; }
    "++"       { drv->pos += 2; advance_cols(drv,2); return T_INC; }
    "--"       { drv->pos += 2; advance_cols(drv,2); return T_DEC; }
    "+="       { drv->pos += 2; advance_cols(drv,2); return T_ADD_ASSIGN; }
    "-="       { drv->pos += 2; advance_cols(drv,2); return T_SUB_ASSIGN; }
    "*="       { drv->pos += 2; advance_cols(drv,2); return T_MUL_ASSIGN; }
    "/="       { drv->pos += 2; advance_cols(drv,2); return T_DIV_ASSIGN; }
    "%="       { drv->pos += 2; advance_cols(drv,2); return T_MOD_ASSIGN; }
    "&="       { drv->pos += 2; advance_cols(drv,2); return T_AND_ASSIGN; }
    "|="       { drv->pos += 2; advance_cols(drv,2); return T_OR_ASSIGN; }
    "^="       { drv->pos += 2; advance_cols(drv,2); return T_XOR_ASSIGN; }
    "<<"       { drv->pos += 2; advance_cols(drv,2); return T_SHL; }
    ">>"       { drv->pos += 2; advance_cols(drv,2); return T_SHR; }
    "!"        { drv->pos += 1; advance_cols(drv,1); return T_NOT; }
    "~"        { drv->pos += 1; advance_cols(drv,1); return T_BIT_NOT; }
    "&"        { drv->pos += 1; advance_cols(drv,1); return T_BIT_AND; }
    "|"        { drv->pos += 1; advance_cols(drv,1); return T_BIT_OR; }
    "^"        { drv->pos += 1; advance_cols(drv,1); return T_BIT_XOR; }
    "="        { drv->pos += 1; advance_cols(drv,1); return T_ASSIGN; }
    "<"        { drv->pos += 1; advance_cols(drv,1); return T_LT; }
    ">"        { drv->pos += 1; advance_cols(drv,1); return T_GT; }
    "+"        { drv->pos += 1; advance_cols(drv,1); return T_PLUS; }
    "-"        { drv->pos += 1; advance_cols(drv,1); return T_MINUS; }
    "*"        { drv->pos += 1; advance_cols(drv,1); return T_MUL; }
    "/"        { drv->pos += 1; advance_cols(drv,1); return T_DIV; }
    "%"        { drv->pos += 1; advance_cols(drv,1); return T_MOD; }
    "."        { drv->pos += 1; advance_cols(drv,1); return T_DOT; }
    ";"        { drv->pos += 1; advance_cols(drv,1); return T_SEMI; }
    ","        { drv->pos += 1; advance_cols(drv,1); return T_COMMA; }
    ":"        { drv->pos += 1; advance_cols(drv,1); return T_COLON; }
    "?"        { drv->pos += 1; advance_cols(drv,1); return T_QMARK; }
    "("        { drv->pos += 1; advance_cols(drv,1); return T_LPAREN; }
    ")"        { drv->pos += 1; advance_cols(drv,1); return T_RPAREN; }
    "{"        { drv->pos += 1; advance_cols(drv,1); return T_LBRACE; }
    "}"        { drv->pos += 1; advance_cols(drv,1); return T_RBRACE; }
    "["        { drv->pos += 1; advance_cols(drv,1); return T_LBRACK; }
    "]"        { drv->pos += 1; advance_cols(drv,1); return T_RBRACK; }

    STR_SQ     { size_t l = ctx.cursor - ctx.tok_start; drv->pos += l; advance_cols(drv, (int)l); return T_STRING; }
    STR_DQ     { size_t l = ctx.cursor - ctx.tok_start; drv->pos += l; advance_cols(drv, (int)l); return T_STRING; }

    NUM_HEX    { size_t l = ctx.cursor - ctx.tok_start; drv->pos += l; advance_cols(drv,(int)l); return T_NUMERIC; }
    NUM_BIN    { size_t l = ctx.cursor - ctx.tok_start; drv->pos += l; advance_cols(drv,(int)l); return T_NUMERIC; }
    NUM_OCT    { size_t l = ctx.cursor - ctx.tok_start; drv->pos += l; advance_cols(drv,(int)l); return T_NUMERIC; }
    NUM_DEC    { size_t l = ctx.cursor - ctx.tok_start; drv->pos += l; advance_cols(drv,(int)l); return T_NUMERIC; }

    [_$A-Za-z] [_$A-Za-z0-9]* {
      int len = (int)(ctx.cursor - ctx.tok_start);
      int tok = kw((const char*)ctx.tok_start, len);
      drv->pos += len; advance_cols(drv, len);
      if (tok) return tok;
      return T_IDENTIFIER;
    }

    * {
      drv->pos += 1; advance_cols(drv, 1);
      return *(unsigned char*)ctx.tok_start;
    }
  */
  return 0;
}

/* Peek next token kind and whether a LineTerminator appeared before it. */
int yypeek_token(void *scanner, ParserDriver *drv, int *tok_out, int *lt_out) {
  ParserDriver tmp = *drv; /* copy driver state */
  int dummy = 0;
  int tok = yylex(&dummy, scanner, &tmp);
  *tok_out = tok;
  *lt_out = tmp.has_line_terminator;
  return 0;
}

/* stubs */
int yylex_init_extra(ParserDriver *drv, void **scanner) { (void)drv; *scanner = (void*)0x1; return 0; }
int yylex_destroy(void *scanner) { (void)scanner; return 0; }
int yy_scan_bytes(const char *bytes, size_t len, void *scanner) { (void)bytes; (void)len; (void)scanner; return 0; }
void yyset_in(FILE *in_str, void *scanner) { (void)in_str; (void)scanner; }
