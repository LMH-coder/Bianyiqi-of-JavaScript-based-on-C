/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 2

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "src/parser.y"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tokens.h"
#include "parser_driver.h"

/* Peek: next token and its preceding LineTerminator flag */
extern int yypeek_token(void *scanner, ParserDriver *drv, int *tok_out, int *lt_out);

/* LALR: 三参 yylex 原型 */
int yylex(int *yylval, void *scanner, ParserDriver *drv);
void yyerror(void *scanner, ParserDriver *drv, const char *msg);

/* no-LineTerminator 守卫：仅用于受限位置（return/throw/break/continue、后缀++/--） */
#define GUARD_NO_LINEBREAK() \
  do { int la_=0, lt_=0; yypeek_token(scanner, drv, &la_, &lt_); if (lt_) YYERROR; } while (0)

#line 90 "src/parser.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_PREC_NOPOST = 3,                /* PREC_NOPOST  */
  YYSYMBOL_T_IDENTIFIER = 4,               /* T_IDENTIFIER  */
  YYSYMBOL_T_NUMERIC = 5,                  /* T_NUMERIC  */
  YYSYMBOL_T_STRING = 6,                   /* T_STRING  */
  YYSYMBOL_T_K_VAR = 7,                    /* T_K_VAR  */
  YYSYMBOL_T_K_LET = 8,                    /* T_K_LET  */
  YYSYMBOL_T_K_CONST = 9,                  /* T_K_CONST  */
  YYSYMBOL_T_K_FUNCTION = 10,              /* T_K_FUNCTION  */
  YYSYMBOL_T_K_RETURN = 11,                /* T_K_RETURN  */
  YYSYMBOL_T_K_IF = 12,                    /* T_K_IF  */
  YYSYMBOL_T_K_ELSE = 13,                  /* T_K_ELSE  */
  YYSYMBOL_T_K_WHILE = 14,                 /* T_K_WHILE  */
  YYSYMBOL_T_K_DO = 15,                    /* T_K_DO  */
  YYSYMBOL_T_K_FOR = 16,                   /* T_K_FOR  */
  YYSYMBOL_T_K_BREAK = 17,                 /* T_K_BREAK  */
  YYSYMBOL_T_K_CONTINUE = 18,              /* T_K_CONTINUE  */
  YYSYMBOL_T_K_THROW = 19,                 /* T_K_THROW  */
  YYSYMBOL_T_K_TRY = 20,                   /* T_K_TRY  */
  YYSYMBOL_T_K_CATCH = 21,                 /* T_K_CATCH  */
  YYSYMBOL_T_K_FINALLY = 22,               /* T_K_FINALLY  */
  YYSYMBOL_T_K_TRUE = 23,                  /* T_K_TRUE  */
  YYSYMBOL_T_K_FALSE = 24,                 /* T_K_FALSE  */
  YYSYMBOL_T_K_NULL = 25,                  /* T_K_NULL  */
  YYSYMBOL_T_K_NEW = 26,                   /* T_K_NEW  */
  YYSYMBOL_T_K_THIS = 27,                  /* T_K_THIS  */
  YYSYMBOL_T_K_TYPEOF = 28,                /* T_K_TYPEOF  */
  YYSYMBOL_T_K_VOID = 29,                  /* T_K_VOID  */
  YYSYMBOL_T_K_DELETE = 30,                /* T_K_DELETE  */
  YYSYMBOL_T_K_IN = 31,                    /* T_K_IN  */
  YYSYMBOL_T_K_INSTANCEOF = 32,            /* T_K_INSTANCEOF  */
  YYSYMBOL_T_K_SWITCH = 33,                /* T_K_SWITCH  */
  YYSYMBOL_T_K_CASE = 34,                  /* T_K_CASE  */
  YYSYMBOL_T_K_DEFAULT = 35,               /* T_K_DEFAULT  */
  YYSYMBOL_T_K_DEBUGGER = 36,              /* T_K_DEBUGGER  */
  YYSYMBOL_T_K_OF = 37,                    /* T_K_OF  */
  YYSYMBOL_T_LPAREN = 38,                  /* T_LPAREN  */
  YYSYMBOL_T_RPAREN = 39,                  /* T_RPAREN  */
  YYSYMBOL_T_LBRACE = 40,                  /* T_LBRACE  */
  YYSYMBOL_T_RBRACE = 41,                  /* T_RBRACE  */
  YYSYMBOL_T_LBRACK = 42,                  /* T_LBRACK  */
  YYSYMBOL_T_RBRACK = 43,                  /* T_RBRACK  */
  YYSYMBOL_T_DOT = 44,                     /* T_DOT  */
  YYSYMBOL_T_SEMI = 45,                    /* T_SEMI  */
  YYSYMBOL_T_COMMA = 46,                   /* T_COMMA  */
  YYSYMBOL_T_COLON = 47,                   /* T_COLON  */
  YYSYMBOL_T_QMARK = 48,                   /* T_QMARK  */
  YYSYMBOL_T_PLUS = 49,                    /* T_PLUS  */
  YYSYMBOL_T_MINUS = 50,                   /* T_MINUS  */
  YYSYMBOL_T_MUL = 51,                     /* T_MUL  */
  YYSYMBOL_T_DIV = 52,                     /* T_DIV  */
  YYSYMBOL_T_MOD = 53,                     /* T_MOD  */
  YYSYMBOL_T_INC = 54,                     /* T_INC  */
  YYSYMBOL_T_DEC = 55,                     /* T_DEC  */
  YYSYMBOL_T_ASSIGN = 56,                  /* T_ASSIGN  */
  YYSYMBOL_T_ADD_ASSIGN = 57,              /* T_ADD_ASSIGN  */
  YYSYMBOL_T_SUB_ASSIGN = 58,              /* T_SUB_ASSIGN  */
  YYSYMBOL_T_MUL_ASSIGN = 59,              /* T_MUL_ASSIGN  */
  YYSYMBOL_T_DIV_ASSIGN = 60,              /* T_DIV_ASSIGN  */
  YYSYMBOL_T_MOD_ASSIGN = 61,              /* T_MOD_ASSIGN  */
  YYSYMBOL_T_EQ = 62,                      /* T_EQ  */
  YYSYMBOL_T_NEQ = 63,                     /* T_NEQ  */
  YYSYMBOL_T_STRICT_EQ = 64,               /* T_STRICT_EQ  */
  YYSYMBOL_T_STRICT_NEQ = 65,              /* T_STRICT_NEQ  */
  YYSYMBOL_T_LT = 66,                      /* T_LT  */
  YYSYMBOL_T_LTE = 67,                     /* T_LTE  */
  YYSYMBOL_T_GT = 68,                      /* T_GT  */
  YYSYMBOL_T_GTE = 69,                     /* T_GTE  */
  YYSYMBOL_T_AND = 70,                     /* T_AND  */
  YYSYMBOL_T_OR = 71,                      /* T_OR  */
  YYSYMBOL_T_NOT = 72,                     /* T_NOT  */
  YYSYMBOL_T_BIT_AND = 73,                 /* T_BIT_AND  */
  YYSYMBOL_T_BIT_OR = 74,                  /* T_BIT_OR  */
  YYSYMBOL_T_BIT_XOR = 75,                 /* T_BIT_XOR  */
  YYSYMBOL_T_BIT_NOT = 76,                 /* T_BIT_NOT  */
  YYSYMBOL_T_SHL = 77,                     /* T_SHL  */
  YYSYMBOL_T_SHR = 78,                     /* T_SHR  */
  YYSYMBOL_T_USHR = 79,                    /* T_USHR  */
  YYSYMBOL_T_AND_ASSIGN = 80,              /* T_AND_ASSIGN  */
  YYSYMBOL_T_OR_ASSIGN = 81,               /* T_OR_ASSIGN  */
  YYSYMBOL_T_XOR_ASSIGN = 82,              /* T_XOR_ASSIGN  */
  YYSYMBOL_T_SHL_ASSIGN = 83,              /* T_SHL_ASSIGN  */
  YYSYMBOL_T_SHR_ASSIGN = 84,              /* T_SHR_ASSIGN  */
  YYSYMBOL_T_USHR_ASSIGN = 85,             /* T_USHR_ASSIGN  */
  YYSYMBOL_YYACCEPT = 86,                  /* $accept  */
  YYSYMBOL_program = 87,                   /* program  */
  YYSYMBOL_statement_list_opt = 88,        /* statement_list_opt  */
  YYSYMBOL_statement = 89,                 /* statement  */
  YYSYMBOL_block = 90,                     /* block  */
  YYSYMBOL_empty_statement = 91,           /* empty_statement  */
  YYSYMBOL_variable_statement = 92,        /* variable_statement  */
  YYSYMBOL_var_kind = 93,                  /* var_kind  */
  YYSYMBOL_var_binding_list = 94,          /* var_binding_list  */
  YYSYMBOL_var_binding = 95,               /* var_binding  */
  YYSYMBOL_expression_statement = 96,      /* expression_statement  */
  YYSYMBOL_if_statement = 97,              /* if_statement  */
  YYSYMBOL_iteration_statement = 98,       /* iteration_statement  */
  YYSYMBOL_for_init_opt = 99,              /* for_init_opt  */
  YYSYMBOL_for_test_opt = 100,             /* for_test_opt  */
  YYSYMBOL_for_update_opt = 101,           /* for_update_opt  */
  YYSYMBOL_switch_statement = 102,         /* switch_statement  */
  YYSYMBOL_case_block_opt = 103,           /* case_block_opt  */
  YYSYMBOL_case_block = 104,               /* case_block  */
  YYSYMBOL_case_clauses_opt = 105,         /* case_clauses_opt  */
  YYSYMBOL_case_clauses = 106,             /* case_clauses  */
  YYSYMBOL_case_clause = 107,              /* case_clause  */
  YYSYMBOL_default_clause_opt = 108,       /* default_clause_opt  */
  YYSYMBOL_labelled_statement = 109,       /* labelled_statement  */
  YYSYMBOL_debugger_statement = 110,       /* debugger_statement  */
  YYSYMBOL_continue_statement = 111,       /* continue_statement  */
  YYSYMBOL_112_1 = 112,                    /* $@1  */
  YYSYMBOL_break_statement = 113,          /* break_statement  */
  YYSYMBOL_114_2 = 114,                    /* $@2  */
  YYSYMBOL_return_statement = 115,         /* return_statement  */
  YYSYMBOL_116_3 = 116,                    /* $@3  */
  YYSYMBOL_throw_statement = 117,          /* throw_statement  */
  YYSYMBOL_118_4 = 118,                    /* $@4  */
  YYSYMBOL_restricted_semicolon = 119,     /* restricted_semicolon  */
  YYSYMBOL_function_declaration = 120,     /* function_declaration  */
  YYSYMBOL_param_list_opt = 121,           /* param_list_opt  */
  YYSYMBOL_param_list = 122,               /* param_list  */
  YYSYMBOL_try_statement = 123,            /* try_statement  */
  YYSYMBOL_expression = 124,               /* expression  */
  YYSYMBOL_assignment_expression = 125,    /* assignment_expression  */
  YYSYMBOL_conditional_expression = 126,   /* conditional_expression  */
  YYSYMBOL_logical_or_expression = 127,    /* logical_or_expression  */
  YYSYMBOL_logical_and_expression = 128,   /* logical_and_expression  */
  YYSYMBOL_bit_or_expression = 129,        /* bit_or_expression  */
  YYSYMBOL_bit_xor_expression = 130,       /* bit_xor_expression  */
  YYSYMBOL_bit_and_expression = 131,       /* bit_and_expression  */
  YYSYMBOL_equality_expression = 132,      /* equality_expression  */
  YYSYMBOL_relational_expression = 133,    /* relational_expression  */
  YYSYMBOL_shift_expression = 134,         /* shift_expression  */
  YYSYMBOL_additive_expression = 135,      /* additive_expression  */
  YYSYMBOL_multiplicative_expression = 136, /* multiplicative_expression  */
  YYSYMBOL_unary_expression = 137,         /* unary_expression  */
  YYSYMBOL_postfix_expression = 138,       /* postfix_expression  */
  YYSYMBOL_139_5 = 139,                    /* $@5  */
  YYSYMBOL_140_6 = 140,                    /* $@6  */
  YYSYMBOL_left_hand_side = 141,           /* left_hand_side  */
  YYSYMBOL_primary_expression = 142,       /* primary_expression  */
  YYSYMBOL_primary_or_new = 143,           /* primary_or_new  */
  YYSYMBOL_trailer = 144,                  /* trailer  */
  YYSYMBOL_trailers_opt = 145,             /* trailers_opt  */
  YYSYMBOL_member_or_call = 146,           /* member_or_call  */
  YYSYMBOL_argument_list_opt = 147,        /* argument_list_opt  */
  YYSYMBOL_argument_list = 148,            /* argument_list  */
  YYSYMBOL_literal = 149,                  /* literal  */
  YYSYMBOL_array_literal = 150,            /* array_literal  */
  YYSYMBOL_elements_opt = 151,             /* elements_opt  */
  YYSYMBOL_element_list = 152,             /* element_list  */
  YYSYMBOL_object_literal = 153,           /* object_literal  */
  YYSYMBOL_prop_list_opt = 154,            /* prop_list_opt  */
  YYSYMBOL_property_list = 155,            /* property_list  */
  YYSYMBOL_property = 156,                 /* property  */
  YYSYMBOL_property_name = 157,            /* property_name  */
  YYSYMBOL_semi_opt = 158,                 /* semi_opt  */
  YYSYMBOL_nb_expression = 159,            /* nb_expression  */
  YYSYMBOL_nb_assignment_expression = 160, /* nb_assignment_expression  */
  YYSYMBOL_nb_conditional_expression = 161, /* nb_conditional_expression  */
  YYSYMBOL_nb_logical_or_expression = 162, /* nb_logical_or_expression  */
  YYSYMBOL_nb_logical_and_expression = 163, /* nb_logical_and_expression  */
  YYSYMBOL_nb_bit_or_expression = 164,     /* nb_bit_or_expression  */
  YYSYMBOL_nb_bit_xor_expression = 165,    /* nb_bit_xor_expression  */
  YYSYMBOL_nb_bit_and_expression = 166,    /* nb_bit_and_expression  */
  YYSYMBOL_nb_equality_expression = 167,   /* nb_equality_expression  */
  YYSYMBOL_nb_relational_expression = 168, /* nb_relational_expression  */
  YYSYMBOL_nb_shift_expression = 169,      /* nb_shift_expression  */
  YYSYMBOL_nb_additive_expression = 170,   /* nb_additive_expression  */
  YYSYMBOL_nb_multiplicative_expression = 171, /* nb_multiplicative_expression  */
  YYSYMBOL_nb_unary_expression = 172,      /* nb_unary_expression  */
  YYSYMBOL_nb_postfix_expression = 173,    /* nb_postfix_expression  */
  YYSYMBOL_174_7 = 174,                    /* $@7  */
  YYSYMBOL_175_8 = 175,                    /* $@8  */
  YYSYMBOL_nb_left_hand_side = 176,        /* nb_left_hand_side  */
  YYSYMBOL_nb_primary_expression = 177,    /* nb_primary_expression  */
  YYSYMBOL_nb_primary_or_new = 178,        /* nb_primary_or_new  */
  YYSYMBOL_nb_trailer = 179,               /* nb_trailer  */
  YYSYMBOL_nb_trailers_opt = 180,          /* nb_trailers_opt  */
  YYSYMBOL_nb_member_or_call = 181         /* nb_member_or_call  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if 1

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   887

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  86
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  96
/* YYNRULES -- Number of rules.  */
#define YYNRULES  272
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  469

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   340


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    67,    67,    71,    72,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      95,    99,   104,   108,   109,   110,   114,   115,   119,   120,
     125,   130,   131,   135,   136,   137,   138,   139,   140,   141,
     145,   146,   147,   151,   152,   156,   157,   162,   166,   167,
     171,   175,   176,   180,   181,   185,   189,   190,   195,   199,
     204,   205,   205,   209,   210,   210,   214,   215,   215,   219,
     219,   224,   225,   236,   240,   241,   245,   246,   251,   252,
     253,   254,   255,   260,   261,   265,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   281,   282,
     286,   287,   291,   292,   296,   297,   301,   302,   306,   307,
     311,   312,   313,   314,   315,   319,   320,   321,   322,   323,
     324,   325,   329,   330,   331,   332,   336,   337,   338,   342,
     343,   344,   345,   349,   350,   351,   352,   353,   354,   355,
     356,   357,   358,   359,   360,   364,   365,   365,   366,   366,
     370,   375,   376,   377,   378,   379,   380,   384,   385,   389,
     390,   391,   395,   396,   400,   404,   405,   409,   410,   414,
     415,   416,   417,   418,   422,   426,   427,   431,   432,   433,
     437,   441,   442,   446,   447,   448,   452,   456,   457,   458,
     463,   464,   476,   477,   481,   482,   483,   484,   485,   486,
     487,   488,   489,   490,   491,   492,   493,   497,   498,   502,
     503,   507,   508,   512,   513,   517,   518,   522,   523,   527,
     528,   529,   530,   531,   535,   536,   537,   538,   539,   540,
     541,   545,   546,   547,   548,   552,   553,   554,   558,   559,
     560,   561,   565,   566,   567,   568,   569,   570,   571,   572,
     573,   574,   575,   576,   580,   581,   581,   582,   582,   586,
     591,   592,   593,   594,   595,   599,   600,   604,   605,   606,
     610,   611,   615
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "PREC_NOPOST",
  "T_IDENTIFIER", "T_NUMERIC", "T_STRING", "T_K_VAR", "T_K_LET",
  "T_K_CONST", "T_K_FUNCTION", "T_K_RETURN", "T_K_IF", "T_K_ELSE",
  "T_K_WHILE", "T_K_DO", "T_K_FOR", "T_K_BREAK", "T_K_CONTINUE",
  "T_K_THROW", "T_K_TRY", "T_K_CATCH", "T_K_FINALLY", "T_K_TRUE",
  "T_K_FALSE", "T_K_NULL", "T_K_NEW", "T_K_THIS", "T_K_TYPEOF", "T_K_VOID",
  "T_K_DELETE", "T_K_IN", "T_K_INSTANCEOF", "T_K_SWITCH", "T_K_CASE",
  "T_K_DEFAULT", "T_K_DEBUGGER", "T_K_OF", "T_LPAREN", "T_RPAREN",
  "T_LBRACE", "T_RBRACE", "T_LBRACK", "T_RBRACK", "T_DOT", "T_SEMI",
  "T_COMMA", "T_COLON", "T_QMARK", "T_PLUS", "T_MINUS", "T_MUL", "T_DIV",
  "T_MOD", "T_INC", "T_DEC", "T_ASSIGN", "T_ADD_ASSIGN", "T_SUB_ASSIGN",
  "T_MUL_ASSIGN", "T_DIV_ASSIGN", "T_MOD_ASSIGN", "T_EQ", "T_NEQ",
  "T_STRICT_EQ", "T_STRICT_NEQ", "T_LT", "T_LTE", "T_GT", "T_GTE", "T_AND",
  "T_OR", "T_NOT", "T_BIT_AND", "T_BIT_OR", "T_BIT_XOR", "T_BIT_NOT",
  "T_SHL", "T_SHR", "T_USHR", "T_AND_ASSIGN", "T_OR_ASSIGN",
  "T_XOR_ASSIGN", "T_SHL_ASSIGN", "T_SHR_ASSIGN", "T_USHR_ASSIGN",
  "$accept", "program", "statement_list_opt", "statement", "block",
  "empty_statement", "variable_statement", "var_kind", "var_binding_list",
  "var_binding", "expression_statement", "if_statement",
  "iteration_statement", "for_init_opt", "for_test_opt", "for_update_opt",
  "switch_statement", "case_block_opt", "case_block", "case_clauses_opt",
  "case_clauses", "case_clause", "default_clause_opt",
  "labelled_statement", "debugger_statement", "continue_statement", "$@1",
  "break_statement", "$@2", "return_statement", "$@3", "throw_statement",
  "$@4", "restricted_semicolon", "function_declaration", "param_list_opt",
  "param_list", "try_statement", "expression", "assignment_expression",
  "conditional_expression", "logical_or_expression",
  "logical_and_expression", "bit_or_expression", "bit_xor_expression",
  "bit_and_expression", "equality_expression", "relational_expression",
  "shift_expression", "additive_expression", "multiplicative_expression",
  "unary_expression", "postfix_expression", "$@5", "$@6", "left_hand_side",
  "primary_expression", "primary_or_new", "trailer", "trailers_opt",
  "member_or_call", "argument_list_opt", "argument_list", "literal",
  "array_literal", "elements_opt", "element_list", "object_literal",
  "prop_list_opt", "property_list", "property", "property_name",
  "semi_opt", "nb_expression", "nb_assignment_expression",
  "nb_conditional_expression", "nb_logical_or_expression",
  "nb_logical_and_expression", "nb_bit_or_expression",
  "nb_bit_xor_expression", "nb_bit_and_expression",
  "nb_equality_expression", "nb_relational_expression",
  "nb_shift_expression", "nb_additive_expression",
  "nb_multiplicative_expression", "nb_unary_expression",
  "nb_postfix_expression", "$@7", "$@8", "nb_left_hand_side",
  "nb_primary_expression", "nb_primary_or_new", "nb_trailer",
  "nb_trailers_opt", "nb_member_or_call", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-303)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-265)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -303,    48,   628,  -303,   -29,  -303,  -303,  -303,  -303,  -303,
      57,   586,    -9,    26,   628,    36,    10,    13,  -303,   -18,
    -303,  -303,  -303,   765,   663,   765,   765,   765,    51,   198,
     765,  -303,   726,  -303,   765,   765,   765,   765,   765,   765,
    -303,  -303,  -303,  -303,   140,  -303,  -303,  -303,  -303,  -303,
    -303,  -303,  -303,  -303,  -303,  -303,  -303,  -303,  -303,   142,
    -303,  -303,   -32,   202,    27,   189,   234,   175,    56,   -69,
     143,   251,  -303,  -303,   772,  -303,  -303,  -303,   628,   288,
    -303,   726,  -303,   726,   726,   333,   687,   345,  -303,   346,
    -303,   726,   266,  -303,  -303,  -303,   314,  -303,  -303,  -303,
     726,  -303,  -303,   -20,   535,  -303,   726,   766,   726,   726,
     726,   726,   306,   726,   726,   726,   726,   726,   726,  -303,
    -303,    19,   283,   280,   284,   285,   194,    62,   236,   268,
     270,  -303,  -303,   802,  -303,  -303,  -303,  -303,  -303,   313,
     316,  -303,  -303,  -303,  -303,  -303,  -303,  -303,   304,   290,
    -303,   765,  -303,   765,   765,   765,   765,   765,   765,   765,
     765,   765,   765,   765,   765,   765,   765,   765,   765,   765,
     765,   765,   765,   765,   765,   765,   765,   765,   765,   765,
     765,   765,   765,   765,   765,   765,   765,   765,   765,   309,
     310,    18,  -303,   360,   292,  -303,    87,    88,   328,    28,
     140,   109,   323,   326,   424,   329,   329,   292,   223,   -18,
     726,    93,  -303,  -303,  -303,  -303,   335,  -303,  -303,  -303,
      96,  -303,  -303,  -303,   334,   331,  -303,   332,  -303,  -303,
    -303,  -303,  -303,  -303,   726,   726,   726,   726,   726,   726,
     726,   726,   726,   726,   726,   726,   726,   726,   726,   726,
     726,   726,   726,   726,   726,   726,   726,   726,   726,   726,
     726,   726,   726,   726,   726,   726,   726,   726,   726,   726,
     324,   327,    53,  -303,   726,   726,   140,  -303,  -303,   337,
     202,    27,   189,   234,   175,    56,    56,    56,    56,   -69,
     -69,   -69,   -69,   -69,   -69,   143,   143,   143,   251,   251,
    -303,  -303,  -303,  -303,  -303,  -303,  -303,  -303,  -303,  -303,
    -303,  -303,  -303,  -303,  -303,  -303,  -303,   726,   765,   381,
    -303,  -303,   347,   342,   726,  -303,   628,   628,   726,   354,
     726,   726,   726,   726,   726,  -303,  -303,  -303,   388,   379,
    -303,  -303,   363,   357,   364,   726,  -303,  -303,   306,   726,
     358,   283,   280,   284,   285,   194,    62,    62,    62,    62,
     236,   236,   236,   236,   236,   236,   268,   268,   268,   270,
     270,  -303,  -303,  -303,  -303,  -303,  -303,  -303,  -303,  -303,
    -303,  -303,  -303,  -303,  -303,  -303,  -303,  -303,   726,   726,
     402,  -303,  -303,  -303,  -303,   765,   382,   -16,  -303,   -18,
     416,  -303,   421,  -303,    97,    99,   102,   384,   326,   203,
     216,   396,   -18,  -303,   726,   305,   397,  -303,  -303,   726,
     400,    29,  -303,  -303,  -303,  -303,  -303,  -303,   198,   628,
     628,   726,   628,   628,   -18,  -303,  -303,   726,   399,  -303,
     406,   408,  -303,  -303,  -303,  -303,  -303,  -303,  -303,  -303,
     404,   326,  -303,  -303,   422,   295,  -303,   401,   408,  -303,
     628,   -18,  -303,  -303,  -303,  -303,  -303,   628,   628
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       3,     0,     2,     1,   260,   169,   170,    23,    24,    25,
       0,    67,     0,     0,     0,     0,    72,    72,    69,     0,
     171,   172,   173,     0,   253,     0,     0,     0,     0,   191,
       0,     3,   175,    21,     0,     0,     0,     0,     0,     0,
       4,     5,     7,     6,     0,     8,     9,    10,    17,    18,
      19,    11,    12,    13,    14,    15,    16,   261,   262,   191,
     192,   194,   207,   209,   211,   213,   215,   217,   219,   224,
     231,   235,   238,   242,   254,   265,   270,   259,     0,     0,
      71,     0,    66,     0,     0,     0,    40,     0,    63,     0,
      60,     0,     0,   260,   252,   254,   270,   247,   248,   249,
       0,   190,    59,     0,     0,   151,     0,   144,     0,     0,
       0,     0,   181,     0,     0,     0,     0,     0,     0,   177,
      85,    98,   100,   102,   104,   106,   108,   110,   115,   122,
     126,   129,   133,   145,   157,   162,   150,   152,   153,     0,
     176,   154,   245,   246,   250,   251,   243,   244,    28,   191,
      26,     0,    30,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   272,    58,    74,   191,    83,     0,     0,     0,   151,
       0,     0,     0,    42,   145,    72,    72,   191,     0,     0,
     165,     0,   263,    20,   143,   145,   162,   138,   139,   140,
       0,   187,   189,   188,     0,   182,   183,     0,   136,   137,
     141,   142,   134,   135,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   164,   174,   179,     0,     0,    22,   193,     0,
     210,   212,   214,   216,   218,   220,   221,   222,   223,   230,
     229,   225,   226,   227,   228,   232,   233,   234,   236,   237,
     239,   240,   241,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   256,   258,   165,     0,     0,
     271,    76,     0,    75,     0,    68,     0,     0,     0,    41,
       0,     0,    43,     0,     0,    65,    62,    70,     0,    78,
      80,   167,     0,   166,     0,   165,   155,   180,   185,     0,
       0,   101,   103,   105,   107,   109,   111,   112,   113,   114,
     121,   120,   116,   117,   118,   119,   123,   124,   125,   127,
     128,   130,   131,   132,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,   147,   149,   165,     0,
       0,   163,   178,    29,    27,     0,     0,     0,   268,     0,
       0,    84,    31,    33,     0,     0,     0,     0,    44,     0,
       0,     0,     0,   266,     0,    48,     0,   184,   186,     0,
       0,     0,   160,   208,   267,   269,    73,    77,   191,     0,
       0,    45,     0,     0,     0,    81,   168,     0,     0,    49,
      56,    52,    53,   158,    99,   159,   161,    34,    36,    38,
       0,    46,    37,    39,    79,     0,    47,     0,    51,    54,
       0,     0,     3,     3,    50,    35,    82,    55,    57
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -303,  -303,   -30,    -7,    25,  -303,  -303,   361,   246,   -81,
    -303,  -303,  -303,  -303,  -303,  -303,  -303,  -303,  -303,    -6,
    -303,     8,  -303,  -303,  -303,  -303,  -303,  -303,  -303,  -303,
    -303,  -303,  -303,    30,  -303,  -303,  -303,  -303,   -80,    31,
    -303,  -303,   219,   215,   220,   218,   221,    39,    22,    78,
      90,   -10,  -303,  -303,  -303,   281,  -303,   356,  -303,  -303,
    -303,  -302,  -303,    -2,    43,  -303,  -303,  -303,  -303,  -303,
     115,  -303,   -57,   -17,   -68,  -303,  -303,   315,   312,   308,
     311,   319,   124,   110,   162,   173,    15,  -303,  -303,  -303,
     230,  -303,   447,  -303,  -303,  -303
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,     2,    40,    41,    42,    43,    44,   149,   150,
      45,    46,    47,   202,   407,   450,    48,   438,   439,   440,
     441,   442,   458,    49,    50,    51,    89,    52,    87,    53,
      81,    54,    91,    82,    55,   322,   323,    56,   194,   195,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   270,   271,   133,   134,   135,   391,   272,
     136,   342,   343,   137,   138,   139,   140,   141,   224,   225,
     226,   227,   102,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,   189,   190,
      95,    75,    76,   320,   191,    77
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      57,   104,   152,   196,   197,   201,   203,    85,   169,   170,
     171,   207,    57,   103,   -64,   396,   153,   -61,    78,   212,
     211,    57,    31,    57,    57,    57,   151,   425,    57,    83,
     151,   220,    57,    57,    57,    57,    57,    57,    94,   154,
      97,    98,    99,   416,    92,    58,    88,    90,     3,   142,
     143,   144,   145,   146,   147,    80,   317,    58,    80,   -28,
     318,    79,   319,   119,    84,   -28,    58,   234,    58,    58,
      58,   192,   446,    58,    86,   324,    57,    58,    58,    58,
      58,    58,    58,   278,   275,   279,   420,   163,   164,   100,
     235,   388,   277,   244,   245,   389,   214,   390,   217,   218,
     219,   156,    57,   228,   229,   230,   231,   232,   233,   303,
     304,   305,   306,   307,   308,   309,   310,   311,   312,   313,
     314,    58,   165,   166,   167,   168,   326,   327,   246,   247,
     248,   249,   344,   324,   324,   346,   428,   325,   429,   324,
     330,   430,   324,   324,   148,   324,   331,    58,   324,    57,
     337,    57,    57,    57,    57,    57,    57,    57,    57,    57,
      57,    57,    57,    57,    57,    57,    57,    57,    57,    57,
      57,    57,    57,    57,    57,    57,    57,    57,    57,    57,
      57,    57,    57,    57,    57,    57,    57,   101,   151,   300,
     301,   302,   172,   173,    58,   394,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    74,   339,   340,   335,   336,   159,   160,   161,
     162,   341,   432,   101,    74,   371,   372,   373,   404,   324,
     405,   406,   408,   409,   410,   433,   240,   241,   242,   243,
      74,   338,   324,    31,   157,   350,   360,   361,   362,   363,
     364,   365,   155,   289,   290,   291,   292,   293,   294,   356,
     357,   358,   359,   285,   286,   287,   288,   208,   209,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   397,   174,   175,   176,   392,   393,   158,    74,   421,
     221,   222,   223,   250,   251,   252,    57,   253,   254,   402,
     403,   255,   256,   257,    57,    57,   193,   423,   366,   367,
     368,   295,   296,   297,    74,   101,   276,   101,   324,   437,
     -51,   324,   462,   369,   370,   298,   299,   198,   341,   205,
     206,   451,   210,   236,   237,   401,   273,   455,   239,   238,
     275,    58,   274,   315,   321,   316,   328,   204,   332,    58,
      58,   447,   324,   345,    80,   347,   341,   348,   386,   349,
     418,    74,   387,    74,   395,   398,   399,   215,   400,   215,
     215,   215,   411,    57,   215,   215,   215,   215,   215,   215,
     276,   412,   413,   414,   415,   419,   422,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,   341,
     427,   424,   448,   449,   426,   452,   453,    57,    57,   431,
      57,    57,   467,   468,  -265,   434,   443,   435,    58,   445,
     456,   457,   437,   460,   461,   436,   329,   200,   463,   459,
     444,   352,   464,   465,   351,   333,   354,   353,    57,   454,
     355,   334,   216,   417,   282,    57,    57,   281,   283,   280,
      96,     0,    58,    58,     0,    58,    58,   284,  -146,  -148,
     258,   259,   260,   261,   262,   263,   466,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    58,   264,   265,   266,   267,   268,   269,
      58,    58,     0,     0,     0,     0,   215,   215,   215,   215,
     215,   215,   215,   215,   215,   215,   215,   215,   215,   215,
     215,   215,   215,   215,   215,   215,   215,   215,   215,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    74,    13,
      14,    15,    16,    17,    18,    19,    74,    74,    20,    21,
      22,    23,    24,    25,    26,    27,     0,     0,    28,     0,
       0,    29,     0,    30,     0,    31,   213,    32,     0,     0,
      33,     0,     0,     0,    34,    35,   -72,     0,     0,    36,
      37,     0,     0,   -72,   -72,   -72,   -72,   -72,   -72,   -72,
     -72,   -72,   -72,   -72,   -72,   -72,   -72,    38,     0,     0,
       0,    39,     0,     0,     0,     0,     0,     0,     0,   -72,
     -72,   -72,   -72,     0,     0,    74,     0,   -72,     0,     0,
       0,    80,     4,     5,     6,     7,     8,     9,    10,    11,
      12,     0,    13,    14,    15,    16,    17,    18,    19,     0,
       0,    20,    21,    22,    23,    24,    25,    26,    27,    74,
      74,    28,    74,    74,    29,     0,    30,     0,    31,     0,
      32,     0,     0,    33,     0,     0,     0,    34,    35,     0,
       0,     0,    36,    37,     0,     0,     0,     0,     0,     0,
      74,   199,     5,     6,     7,     8,     9,    74,    74,     0,
      38,     0,     0,     0,    39,     0,     0,  -264,     0,     0,
      20,    21,    22,   106,   107,   108,   109,   110,     0,  -264,
    -264,  -264,  -264,  -264,  -264,   111,     0,   112,     0,    32,
     105,     5,     6,     0,     0,     0,   113,   114,     0,     0,
       0,   115,   116,  -264,  -264,  -264,  -264,  -264,  -264,    20,
      21,    22,   106,   107,   108,   109,   110,     0,     0,   117,
       0,     0,     0,   118,   111,     0,   112,     0,    32,    93,
       5,     6,     0,     0,     0,   113,   114,     0,     0,     0,
     115,   116,     0,     0,     0,     0,     0,     0,    20,    21,
      22,    23,    24,    25,    26,    27,     0,     0,   117,     0,
       0,     0,   118,    30,     0,     0,     0,    32,     0,     0,
    -156,     0,     0,     0,    34,    35,     0,     0,     0,    36,
      37,     0,  -156,  -156,  -156,  -156,  -156,  -156,   177,   178,
     179,   180,   181,   182,     0,     0,     0,    38,     0,     0,
       0,    39,     0,     0,     0,     0,  -156,  -156,  -156,  -156,
    -156,  -156,   183,   184,   185,   186,   187,   188,   258,   259,
     260,   261,   262,   263,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   264,   265,   266,   267,   268,   269
};

static const yytype_int16 yycheck[] =
{
       2,    31,    59,    83,    84,    86,    86,    14,    77,    78,
      79,    91,    14,    30,     4,   317,    48,     4,    47,    39,
     100,    23,    40,    25,    26,    27,    46,    43,    30,    38,
      46,   111,    34,    35,    36,    37,    38,    39,    23,    71,
      25,    26,    27,   345,    19,     2,    16,    17,     0,    34,
      35,    36,    37,    38,    39,    45,    38,    14,    45,    31,
      42,     4,    44,    32,    38,    37,    23,    48,    25,    26,
      27,    78,    43,    30,    38,    46,    78,    34,    35,    36,
      37,    38,    39,   151,    56,   153,   388,    31,    32,    38,
      71,    38,   149,    31,    32,    42,   106,    44,   108,   109,
     110,    74,   104,   113,   114,   115,   116,   117,   118,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,    78,    66,    67,    68,    69,    39,    39,    66,    67,
      68,    69,    39,    46,    46,    39,    39,   194,    39,    46,
      31,    39,    46,    46,     4,    46,    37,   104,    46,   151,
     207,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,    45,    46,   174,
     175,   176,    49,    50,   151,   276,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,     2,   208,   209,   205,   206,    62,    63,    64,
      65,   210,    39,    45,    14,   255,   256,   257,   328,    46,
     330,   331,   332,   333,   334,    39,    62,    63,    64,    65,
      30,    38,    46,    40,    75,   234,   244,   245,   246,   247,
     248,   249,    70,   163,   164,   165,   166,   167,   168,   240,
     241,   242,   243,   159,   160,   161,   162,    21,    22,   258,
     259,   260,   261,   262,   263,   264,   265,   266,   267,   268,
     269,   318,    51,    52,    53,   274,   275,    73,    78,   389,
       4,     5,     6,    77,    78,    79,   318,    49,    50,   326,
     327,    51,    52,    53,   326,   327,    38,   395,   250,   251,
     252,   169,   170,   171,   104,    45,    46,    45,    46,    34,
      35,    46,    47,   253,   254,   172,   173,    14,   317,     4,
       4,   431,    38,    70,    74,   324,    43,   437,    73,    75,
      56,   318,    46,    54,     4,    55,    38,    86,    45,   326,
     327,   428,    46,    38,    45,    41,   345,    46,    54,    47,
     349,   151,    55,   153,    47,     4,    39,   106,    46,   108,
     109,   110,     4,   395,   113,   114,   115,   116,   117,   118,
      46,    22,    39,    46,    40,    47,     4,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   388,
       4,    39,   429,   430,   399,   432,   433,   429,   430,    45,
     432,   433,   462,   463,    13,    39,    39,   412,   395,    39,
      41,    35,    34,    39,    22,   414,   200,    86,    47,   441,
     419,   236,   458,   460,   235,    31,   238,   237,   460,   434,
     239,    37,   106,   348,   156,   467,   468,   155,   157,   154,
      23,    -1,   429,   430,    -1,   432,   433,   158,    54,    55,
      56,    57,    58,    59,    60,    61,   461,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   460,    80,    81,    82,    83,    84,    85,
     467,   468,    -1,    -1,    -1,    -1,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,     4,
       5,     6,     7,     8,     9,    10,    11,    12,   318,    14,
      15,    16,    17,    18,    19,    20,   326,   327,    23,    24,
      25,    26,    27,    28,    29,    30,    -1,    -1,    33,    -1,
      -1,    36,    -1,    38,    -1,    40,    41,    42,    -1,    -1,
      45,    -1,    -1,    -1,    49,    50,     0,    -1,    -1,    54,
      55,    -1,    -1,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    72,    -1,    -1,
      -1,    76,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    33,
      34,    35,    36,    -1,    -1,   395,    -1,    41,    -1,    -1,
      -1,    45,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    -1,    14,    15,    16,    17,    18,    19,    20,    -1,
      -1,    23,    24,    25,    26,    27,    28,    29,    30,   429,
     430,    33,   432,   433,    36,    -1,    38,    -1,    40,    -1,
      42,    -1,    -1,    45,    -1,    -1,    -1,    49,    50,    -1,
      -1,    -1,    54,    55,    -1,    -1,    -1,    -1,    -1,    -1,
     460,     4,     5,     6,     7,     8,     9,   467,   468,    -1,
      72,    -1,    -1,    -1,    76,    -1,    -1,    44,    -1,    -1,
      23,    24,    25,    26,    27,    28,    29,    30,    -1,    56,
      57,    58,    59,    60,    61,    38,    -1,    40,    -1,    42,
       4,     5,     6,    -1,    -1,    -1,    49,    50,    -1,    -1,
      -1,    54,    55,    80,    81,    82,    83,    84,    85,    23,
      24,    25,    26,    27,    28,    29,    30,    -1,    -1,    72,
      -1,    -1,    -1,    76,    38,    -1,    40,    -1,    42,     4,
       5,     6,    -1,    -1,    -1,    49,    50,    -1,    -1,    -1,
      54,    55,    -1,    -1,    -1,    -1,    -1,    -1,    23,    24,
      25,    26,    27,    28,    29,    30,    -1,    -1,    72,    -1,
      -1,    -1,    76,    38,    -1,    -1,    -1,    42,    -1,    -1,
      44,    -1,    -1,    -1,    49,    50,    -1,    -1,    -1,    54,
      55,    -1,    56,    57,    58,    59,    60,    61,    56,    57,
      58,    59,    60,    61,    -1,    -1,    -1,    72,    -1,    -1,
      -1,    76,    -1,    -1,    -1,    -1,    80,    81,    82,    83,
      84,    85,    80,    81,    82,    83,    84,    85,    56,    57,
      58,    59,    60,    61,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    80,    81,    82,    83,    84,    85
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    87,    88,     0,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    14,    15,    16,    17,    18,    19,    20,
      23,    24,    25,    26,    27,    28,    29,    30,    33,    36,
      38,    40,    42,    45,    49,    50,    54,    55,    72,    76,
      89,    90,    91,    92,    93,    96,    97,    98,   102,   109,
     110,   111,   113,   115,   117,   120,   123,   149,   150,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   176,   177,   178,   181,    47,     4,
      45,   116,   119,    38,    38,    89,    38,   114,   119,   112,
     119,   118,    90,     4,   172,   176,   178,   172,   172,   172,
      38,    45,   158,   159,    88,     4,    26,    27,    28,    29,
      30,    38,    40,    49,    50,    54,    55,    72,    76,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   141,   142,   143,   146,   149,   150,   151,
     152,   153,   172,   172,   172,   172,   172,   172,     4,    94,
      95,    46,   158,    48,    71,    70,    74,    75,    73,    62,
      63,    64,    65,    31,    32,    66,    67,    68,    69,    77,
      78,    79,    49,    50,    51,    52,    53,    56,    57,    58,
      59,    60,    61,    80,    81,    82,    83,    84,    85,   174,
     175,   180,    89,    38,   124,   125,   124,   124,    14,     4,
      93,    95,    99,   124,   141,     4,     4,   124,    21,    22,
      38,   124,    39,    41,   137,   141,   143,   137,   137,   137,
     124,     4,     5,     6,   154,   155,   156,   157,   137,   137,
     137,   137,   137,   137,    48,    71,    70,    74,    75,    73,
      62,    63,    64,    65,    31,    32,    66,    67,    68,    69,
      77,    78,    79,    49,    50,    51,    52,    53,    56,    57,
      58,    59,    60,    61,    80,    81,    82,    83,    84,    85,
     139,   140,   145,    43,    46,    56,    46,   158,   160,   160,
     163,   164,   165,   166,   167,   168,   168,   168,   168,   169,
     169,   169,   169,   169,   169,   170,   170,   170,   171,   171,
     172,   172,   172,   160,   160,   160,   160,   160,   160,   160,
     160,   160,   160,   160,   160,    54,    55,    38,    42,    44,
     179,     4,   121,   122,    46,   158,    39,    39,    38,    94,
      31,    37,    45,    31,    37,   119,   119,   158,    38,    90,
      90,   125,   147,   148,    39,    38,    39,    41,    46,    47,
     125,   128,   129,   130,   131,   132,   133,   133,   133,   133,
     134,   134,   134,   134,   134,   134,   135,   135,   135,   136,
     136,   137,   137,   137,   125,   125,   125,   125,   125,   125,
     125,   125,   125,   125,   125,   125,    54,    55,    38,    42,
      44,   144,   125,   125,    95,    47,   147,   159,     4,    39,
      46,   125,    89,    89,   124,   124,   124,   100,   124,   124,
     124,     4,    22,    39,    46,    40,   147,   156,   125,    47,
     147,   124,     4,   160,    39,    43,    90,     4,    39,    39,
      39,    45,    39,    39,    39,    90,   125,    34,   103,   104,
     105,   106,   107,    39,   125,    39,    43,   158,    89,    89,
     101,   124,    89,    89,    90,   124,    41,    35,   108,   107,
      39,    22,    47,    47,   105,    89,    90,    88,    88
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    86,    87,    88,    88,    89,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    89,    89,    89,    89,    89,
      90,    91,    92,    93,    93,    93,    94,    94,    95,    95,
      96,    97,    97,    98,    98,    98,    98,    98,    98,    98,
      99,    99,    99,   100,   100,   101,   101,   102,   103,   103,
     104,   105,   105,   106,   106,   107,   108,   108,   109,   110,
     111,   112,   111,   113,   114,   113,   115,   116,   115,   118,
     117,   119,   119,   120,   121,   121,   122,   122,   123,   123,
     123,   123,   123,   124,   124,   125,   125,   125,   125,   125,
     125,   125,   125,   125,   125,   125,   125,   125,   126,   126,
     127,   127,   128,   128,   129,   129,   130,   130,   131,   131,
     132,   132,   132,   132,   132,   133,   133,   133,   133,   133,
     133,   133,   134,   134,   134,   134,   135,   135,   135,   136,
     136,   136,   136,   137,   137,   137,   137,   137,   137,   137,
     137,   137,   137,   137,   137,   138,   139,   138,   140,   138,
     141,   142,   142,   142,   142,   142,   142,   143,   143,   144,
     144,   144,   145,   145,   146,   147,   147,   148,   148,   149,
     149,   149,   149,   149,   150,   151,   151,   152,   152,   152,
     153,   154,   154,   155,   155,   155,   156,   157,   157,   157,
     158,   158,   159,   159,   160,   160,   160,   160,   160,   160,
     160,   160,   160,   160,   160,   160,   160,   161,   161,   162,
     162,   163,   163,   164,   164,   165,   165,   166,   166,   167,
     167,   167,   167,   167,   168,   168,   168,   168,   168,   168,
     168,   169,   169,   169,   169,   170,   170,   170,   171,   171,
     171,   171,   172,   172,   172,   172,   172,   172,   172,   172,
     172,   172,   172,   172,   173,   174,   173,   175,   173,   176,
     177,   177,   177,   177,   177,   178,   178,   179,   179,   179,
     180,   180,   181
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     1,     3,     1,     1,     1,     1,     3,     1,     3,
       2,     5,     7,     5,     7,     9,     7,     7,     7,     7,
       0,     2,     1,     0,     1,     0,     1,     7,     0,     1,
       3,     0,     1,     1,     2,     4,     0,     3,     3,     2,
       2,     0,     4,     2,     0,     4,     2,     0,     4,     0,
       4,     1,     0,     6,     0,     1,     1,     3,     4,     7,
       4,     6,     9,     1,     3,     1,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     1,     5,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     3,     3,     3,     3,     1,     3,     3,     3,     3,
       3,     3,     1,     3,     3,     3,     1,     3,     3,     1,
       3,     3,     3,     1,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     1,     1,     0,     3,     0,     3,
       1,     1,     1,     1,     1,     3,     1,     1,     5,     3,
       2,     3,     0,     2,     2,     0,     1,     1,     3,     1,
       1,     1,     1,     1,     3,     0,     1,     1,     3,     2,
       3,     0,     1,     1,     3,     2,     3,     1,     1,     1,
       1,     0,     1,     3,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     1,     5,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     3,     3,     3,     1,     3,     3,     3,     3,     3,
       3,     1,     3,     3,     3,     1,     3,     3,     1,     3,
       3,     3,     1,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     1,     1,     0,     3,     0,     3,     1,
       1,     1,     1,     3,     1,     1,     5,     3,     2,     3,
       0,     2,     2
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (scanner, drv, YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, scanner, drv); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, void *scanner, ParserDriver *drv)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (scanner);
  YY_USE (drv);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, void *scanner, ParserDriver *drv)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep, scanner, drv);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule, void *scanner, ParserDriver *drv)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)], scanner, drv);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule, scanner, drv); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
  if (!yypact_value_is_default (yyn))
    {
      /* Start YYX at -YYN if negative to avoid negative indexes in
         YYCHECK.  In other words, skip the first -YYN actions for
         this state because they are default actions.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;
      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yyx;
      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;
      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, void *scanner, ParserDriver *drv)
{
  YY_USE (yyvaluep);
  YY_USE (scanner);
  YY_USE (drv);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}






/*----------.
| yyparse.  |
`----------*/

int
yyparse (void *scanner, ParserDriver *drv)
{
/* Lookahead token kind.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

    /* Number of syntax errors so far.  */
    int yynerrs = 0;

    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex (&yylval, scanner, drv);
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 61: /* $@1: %empty  */
#line 205 "src/parser.y"
                 { GUARD_NO_LINEBREAK(); }
#line 1989 "src/parser.c"
    break;

  case 64: /* $@2: %empty  */
#line 210 "src/parser.y"
              { GUARD_NO_LINEBREAK(); }
#line 1995 "src/parser.c"
    break;

  case 67: /* $@3: %empty  */
#line 215 "src/parser.y"
               { GUARD_NO_LINEBREAK(); }
#line 2001 "src/parser.c"
    break;

  case 69: /* $@4: %empty  */
#line 219 "src/parser.y"
              { GUARD_NO_LINEBREAK(); }
#line 2007 "src/parser.c"
    break;

  case 72: /* restricted_semicolon: %empty  */
#line 225 "src/parser.y"
           {
      int la=0, lt=0; (void)yypeek_token(scanner, drv, &la, &lt);
      if (la == 0) /* EOF */ ;
      else if (la == T_RBRACE) ;
      else if (lt) ;
      else YYERROR;
    }
#line 2019 "src/parser.c"
    break;

  case 146: /* $@5: %empty  */
#line 365 "src/parser.y"
                   { GUARD_NO_LINEBREAK(); }
#line 2025 "src/parser.c"
    break;

  case 148: /* $@6: %empty  */
#line 366 "src/parser.y"
                   { GUARD_NO_LINEBREAK(); }
#line 2031 "src/parser.c"
    break;

  case 191: /* semi_opt: %empty  */
#line 464 "src/parser.y"
           {
      int la=0, lt=0; (void)yypeek_token(scanner, drv, &la, &lt);
      if (la == 0) /* EOF */ ;
      else if (la == T_RBRACE) ;
      else if (lt) ;
      else YYERROR;
    }
#line 2043 "src/parser.c"
    break;

  case 255: /* $@7: %empty  */
#line 581 "src/parser.y"
                      { GUARD_NO_LINEBREAK(); }
#line 2049 "src/parser.c"
    break;

  case 257: /* $@8: %empty  */
#line 582 "src/parser.y"
                      { GUARD_NO_LINEBREAK(); }
#line 2055 "src/parser.c"
    break;


#line 2059 "src/parser.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (scanner, drv, yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, scanner, drv);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, scanner, drv);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (scanner, drv, YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, scanner, drv);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, scanner, drv);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 618 "src/parser.y"


void yyerror(void *scanner, ParserDriver *drv, const char *msg) {
  (void)scanner;
  drv->err_line = drv->line;
  drv->err_col = drv->col;
  snprintf(drv->err_msg, sizeof(drv->err_msg), "%s", msg ? msg : "parse error");
}
