/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_SRC_PARSER_H_INCLUDED
# define YY_YY_SRC_PARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 37 "src/parser.y"

  #include "parser_driver.h"

#line 53 "src/parser.h"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    PREC_NOPOST = 258,             /* PREC_NOPOST  */
    T_IDENTIFIER = 259,            /* T_IDENTIFIER  */
    T_NUMERIC = 260,               /* T_NUMERIC  */
    T_STRING = 261,                /* T_STRING  */
    T_K_VAR = 262,                 /* T_K_VAR  */
    T_K_LET = 263,                 /* T_K_LET  */
    T_K_CONST = 264,               /* T_K_CONST  */
    T_K_FUNCTION = 265,            /* T_K_FUNCTION  */
    T_K_RETURN = 266,              /* T_K_RETURN  */
    T_K_IF = 267,                  /* T_K_IF  */
    T_K_ELSE = 268,                /* T_K_ELSE  */
    T_K_WHILE = 269,               /* T_K_WHILE  */
    T_K_DO = 270,                  /* T_K_DO  */
    T_K_FOR = 271,                 /* T_K_FOR  */
    T_K_BREAK = 272,               /* T_K_BREAK  */
    T_K_CONTINUE = 273,            /* T_K_CONTINUE  */
    T_K_THROW = 274,               /* T_K_THROW  */
    T_K_TRY = 275,                 /* T_K_TRY  */
    T_K_CATCH = 276,               /* T_K_CATCH  */
    T_K_FINALLY = 277,             /* T_K_FINALLY  */
    T_K_TRUE = 278,                /* T_K_TRUE  */
    T_K_FALSE = 279,               /* T_K_FALSE  */
    T_K_NULL = 280,                /* T_K_NULL  */
    T_K_NEW = 281,                 /* T_K_NEW  */
    T_K_THIS = 282,                /* T_K_THIS  */
    T_K_TYPEOF = 283,              /* T_K_TYPEOF  */
    T_K_VOID = 284,                /* T_K_VOID  */
    T_K_DELETE = 285,              /* T_K_DELETE  */
    T_K_IN = 286,                  /* T_K_IN  */
    T_K_INSTANCEOF = 287,          /* T_K_INSTANCEOF  */
    T_K_SWITCH = 288,              /* T_K_SWITCH  */
    T_K_CASE = 289,                /* T_K_CASE  */
    T_K_DEFAULT = 290,             /* T_K_DEFAULT  */
    T_K_DEBUGGER = 291,            /* T_K_DEBUGGER  */
    T_K_OF = 292,                  /* T_K_OF  */
    T_LPAREN = 293,                /* T_LPAREN  */
    T_RPAREN = 294,                /* T_RPAREN  */
    T_LBRACE = 295,                /* T_LBRACE  */
    T_RBRACE = 296,                /* T_RBRACE  */
    T_LBRACK = 297,                /* T_LBRACK  */
    T_RBRACK = 298,                /* T_RBRACK  */
    T_DOT = 299,                   /* T_DOT  */
    T_SEMI = 300,                  /* T_SEMI  */
    T_COMMA = 301,                 /* T_COMMA  */
    T_COLON = 302,                 /* T_COLON  */
    T_QMARK = 303,                 /* T_QMARK  */
    T_PLUS = 304,                  /* T_PLUS  */
    T_MINUS = 305,                 /* T_MINUS  */
    T_MUL = 306,                   /* T_MUL  */
    T_DIV = 307,                   /* T_DIV  */
    T_MOD = 308,                   /* T_MOD  */
    T_INC = 309,                   /* T_INC  */
    T_DEC = 310,                   /* T_DEC  */
    T_ASSIGN = 311,                /* T_ASSIGN  */
    T_ADD_ASSIGN = 312,            /* T_ADD_ASSIGN  */
    T_SUB_ASSIGN = 313,            /* T_SUB_ASSIGN  */
    T_MUL_ASSIGN = 314,            /* T_MUL_ASSIGN  */
    T_DIV_ASSIGN = 315,            /* T_DIV_ASSIGN  */
    T_MOD_ASSIGN = 316,            /* T_MOD_ASSIGN  */
    T_EQ = 317,                    /* T_EQ  */
    T_NEQ = 318,                   /* T_NEQ  */
    T_STRICT_EQ = 319,             /* T_STRICT_EQ  */
    T_STRICT_NEQ = 320,            /* T_STRICT_NEQ  */
    T_LT = 321,                    /* T_LT  */
    T_LTE = 322,                   /* T_LTE  */
    T_GT = 323,                    /* T_GT  */
    T_GTE = 324,                   /* T_GTE  */
    T_AND = 325,                   /* T_AND  */
    T_OR = 326,                    /* T_OR  */
    T_NOT = 327,                   /* T_NOT  */
    T_BIT_AND = 328,               /* T_BIT_AND  */
    T_BIT_OR = 329,                /* T_BIT_OR  */
    T_BIT_XOR = 330,               /* T_BIT_XOR  */
    T_BIT_NOT = 331,               /* T_BIT_NOT  */
    T_SHL = 332,                   /* T_SHL  */
    T_SHR = 333,                   /* T_SHR  */
    T_USHR = 334,                  /* T_USHR  */
    T_AND_ASSIGN = 335,            /* T_AND_ASSIGN  */
    T_OR_ASSIGN = 336,             /* T_OR_ASSIGN  */
    T_XOR_ASSIGN = 337,            /* T_XOR_ASSIGN  */
    T_SHL_ASSIGN = 338,            /* T_SHL_ASSIGN  */
    T_SHR_ASSIGN = 339,            /* T_SHR_ASSIGN  */
    T_USHR_ASSIGN = 340            /* T_USHR_ASSIGN  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif




int yyparse (void *scanner, ParserDriver *drv);


#endif /* !YY_YY_SRC_PARSER_H_INCLUDED  */
