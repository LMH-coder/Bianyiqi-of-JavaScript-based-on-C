%{
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
%}

/* LALR 设置 */
%define api.pure full
%define api.push-pull pull
%define api.value.type {int}
%define parse.error verbose

%parse-param { void *scanner }
%parse-param { ParserDriver *drv }
%lex-param   { void *scanner }
%lex-param   { ParserDriver *drv }

/* 悬空 else 消冲突 */
%nonassoc T_K_ELSE
/* 让 ++/-- 在冲突时优先移进；引入一个人为优先级给“无后缀”降一档 */
%left T_INC T_DEC
%nonassoc PREC_NOPOST

%code requires {
  #include "parser_driver.h"
}

/* tokens */
%token T_IDENTIFIER T_NUMERIC T_STRING
%token T_K_VAR T_K_LET T_K_CONST T_K_FUNCTION T_K_RETURN T_K_IF T_K_ELSE
%token T_K_WHILE T_K_DO T_K_FOR T_K_BREAK T_K_CONTINUE T_K_THROW
%token T_K_TRY T_K_CATCH T_K_FINALLY T_K_TRUE T_K_FALSE T_K_NULL
%token T_K_NEW T_K_THIS T_K_TYPEOF T_K_VOID T_K_DELETE T_K_IN T_K_INSTANCEOF
%token T_K_SWITCH T_K_CASE T_K_DEFAULT T_K_DEBUGGER T_K_OF

%token T_LPAREN T_RPAREN T_LBRACE T_RBRACE T_LBRACK T_RBRACK
%token T_DOT T_SEMI T_COMMA T_COLON T_QMARK
%token T_PLUS T_MINUS T_MUL T_DIV T_MOD
%token T_INC T_DEC
%token T_ASSIGN T_ADD_ASSIGN T_SUB_ASSIGN T_MUL_ASSIGN T_DIV_ASSIGN T_MOD_ASSIGN
%token T_EQ T_NEQ T_STRICT_EQ T_STRICT_NEQ
%token T_LT T_LTE T_GT T_GTE
%token T_AND T_OR T_NOT
%token T_BIT_AND T_BIT_OR T_BIT_XOR T_BIT_NOT
%token T_SHL T_SHR T_USHR
%token T_AND_ASSIGN T_OR_ASSIGN T_XOR_ASSIGN
%token T_SHL_ASSIGN T_SHR_ASSIGN T_USHR_ASSIGN

%start program

%%

program
  : statement_list_opt
  ;

statement_list_opt
  : %empty
  | statement_list_opt statement
  ;

statement
  : block
  | variable_statement
  | empty_statement
  | expression_statement
  | if_statement
  | iteration_statement
  | continue_statement
  | break_statement
  | return_statement
  | throw_statement
  | function_declaration
  | try_statement
  | switch_statement
  | labelled_statement
  | debugger_statement
  ;

/* Blocks and empty */
block
  : T_LBRACE statement_list_opt T_RBRACE
  ;

empty_statement
  : T_SEMI
  ;

/* Variable statements */
variable_statement
  : var_kind var_binding_list semi_opt
  ;

var_kind
  : T_K_VAR
  | T_K_LET
  | T_K_CONST
  ;

var_binding_list
  : var_binding
  | var_binding_list T_COMMA var_binding
  ;

var_binding
  : T_IDENTIFIER
  | T_IDENTIFIER T_ASSIGN assignment_expression
  ;

/* 表达式语句：使用“禁止以 { 开头”的 nb_expression，避免把 Block 误当 ObjectLiteral */
expression_statement
  : nb_expression semi_opt
  ;

/* If / Iteration */
if_statement
  : T_K_IF T_LPAREN expression T_RPAREN statement %prec T_K_ELSE
  | T_K_IF T_LPAREN expression T_RPAREN statement T_K_ELSE statement
  ;

iteration_statement
  : T_K_WHILE T_LPAREN expression T_RPAREN statement
  | T_K_DO statement T_K_WHILE T_LPAREN expression T_RPAREN semi_opt
  | T_K_FOR T_LPAREN for_init_opt T_SEMI for_test_opt T_SEMI for_update_opt T_RPAREN statement
  | T_K_FOR T_LPAREN var_binding T_K_IN expression T_RPAREN statement
  | T_K_FOR T_LPAREN left_hand_side T_K_IN expression T_RPAREN statement
  | T_K_FOR T_LPAREN var_binding T_K_OF expression T_RPAREN statement
  | T_K_FOR T_LPAREN left_hand_side T_K_OF expression T_RPAREN statement
  ;

for_init_opt
  : %empty
  | var_kind var_binding_list
  | expression
  ;

for_test_opt
  : %empty
  | expression
  ;

for_update_opt
  : %empty
  | expression
  ;

/* Switch */
switch_statement
  : T_K_SWITCH T_LPAREN expression T_RPAREN T_LBRACE case_block_opt T_RBRACE
  ;

case_block_opt
  : %empty
  | case_block
  ;

case_block
  : case_clauses_opt default_clause_opt case_clauses_opt
  ;

case_clauses_opt
  : %empty
  | case_clauses
  ;

case_clauses
  : case_clause
  | case_clauses case_clause
  ;

case_clause
  : T_K_CASE expression T_COLON statement_list_opt
  ;

default_clause_opt
  : %empty
  | T_K_DEFAULT T_COLON statement_list_opt
  ;

/* Labels & debugger */
labelled_statement
  : T_IDENTIFIER T_COLON statement
  ;

debugger_statement
  : T_K_DEBUGGER semi_opt
  ;

/* Control transfer with ASI + noLT guards */
continue_statement
  : T_K_CONTINUE restricted_semicolon
  | T_K_CONTINUE { GUARD_NO_LINEBREAK(); } T_IDENTIFIER restricted_semicolon
  ;

break_statement
  : T_K_BREAK restricted_semicolon
  | T_K_BREAK { GUARD_NO_LINEBREAK(); } T_IDENTIFIER restricted_semicolon
  ;

return_statement
  : T_K_RETURN restricted_semicolon
  | T_K_RETURN { GUARD_NO_LINEBREAK(); } expression semi_opt
  ;

throw_statement
  : T_K_THROW { GUARD_NO_LINEBREAK(); } expression semi_opt
  ;

/* restricted semicolon: if no explicit ';', allow ASI on LT / '}' / EOF */
restricted_semicolon
  : T_SEMI
  | %empty {
      int la=0, lt=0; (void)yypeek_token(scanner, drv, &la, &lt);
      if (la == 0) /* EOF */ ;
      else if (la == T_RBRACE) ;
      else if (lt) ;
      else YYERROR;
    }
  ;

/* Function declaration (subset) */
function_declaration
  : T_K_FUNCTION T_IDENTIFIER T_LPAREN param_list_opt T_RPAREN block
  ;

param_list_opt
  : %empty
  | param_list
  ;

param_list
  : T_IDENTIFIER
  | param_list T_COMMA T_IDENTIFIER
  ;

/* Try/catch/finally (catch binding optional) */
try_statement
  : T_K_TRY block T_K_CATCH block
  | T_K_TRY block T_K_CATCH T_LPAREN T_IDENTIFIER T_RPAREN block
  | T_K_TRY block T_K_FINALLY block
  | T_K_TRY block T_K_CATCH block T_K_FINALLY block
  | T_K_TRY block T_K_CATCH T_LPAREN T_IDENTIFIER T_RPAREN block T_K_FINALLY block
  ;

/* 通用表达式（允许 ObjectLiteral） */
expression
  : assignment_expression
  | expression T_COMMA assignment_expression
  ;

assignment_expression
  : conditional_expression
  | left_hand_side T_ASSIGN assignment_expression
  | left_hand_side T_ADD_ASSIGN assignment_expression
  | left_hand_side T_SUB_ASSIGN assignment_expression
  | left_hand_side T_MUL_ASSIGN assignment_expression
  | left_hand_side T_DIV_ASSIGN assignment_expression
  | left_hand_side T_MOD_ASSIGN assignment_expression
  | left_hand_side T_AND_ASSIGN assignment_expression
  | left_hand_side T_OR_ASSIGN assignment_expression
  | left_hand_side T_XOR_ASSIGN assignment_expression
  | left_hand_side T_SHL_ASSIGN assignment_expression
  | left_hand_side T_SHR_ASSIGN assignment_expression
  | left_hand_side T_USHR_ASSIGN assignment_expression
  ;

conditional_expression
  : logical_or_expression
  | logical_or_expression T_QMARK assignment_expression T_COLON assignment_expression
  ;

logical_or_expression
  : logical_and_expression
  | logical_or_expression T_OR logical_and_expression
  ;

logical_and_expression
  : bit_or_expression
  | logical_and_expression T_AND bit_or_expression
  ;

bit_or_expression
  : bit_xor_expression
  | bit_or_expression T_BIT_OR bit_xor_expression
  ;

bit_xor_expression
  : bit_and_expression
  | bit_xor_expression T_BIT_XOR bit_and_expression
  ;

bit_and_expression
  : equality_expression
  | bit_and_expression T_BIT_AND equality_expression
  ;

equality_expression
  : relational_expression
  | equality_expression T_EQ relational_expression
  | equality_expression T_NEQ relational_expression
  | equality_expression T_STRICT_EQ relational_expression
  | equality_expression T_STRICT_NEQ relational_expression
  ;

relational_expression
  : shift_expression
  | relational_expression T_LT shift_expression
  | relational_expression T_LTE shift_expression
  | relational_expression T_GT shift_expression
  | relational_expression T_GTE shift_expression
  | relational_expression T_K_INSTANCEOF shift_expression
  | relational_expression T_K_IN shift_expression
  ;

shift_expression
  : additive_expression
  | shift_expression T_SHL additive_expression
  | shift_expression T_SHR additive_expression
  | shift_expression T_USHR additive_expression
  ;

additive_expression
  : multiplicative_expression
  | additive_expression T_PLUS multiplicative_expression
  | additive_expression T_MINUS multiplicative_expression
  ;

multiplicative_expression
  : unary_expression
  | multiplicative_expression T_MUL unary_expression
  | multiplicative_expression T_DIV unary_expression
  | multiplicative_expression T_MOD unary_expression
  ;

unary_expression
  : postfix_expression
  | T_NOT unary_expression
  | T_BIT_NOT unary_expression
  | T_PLUS unary_expression
  | T_MINUS unary_expression
  | T_K_TYPEOF unary_expression
  | T_K_VOID unary_expression
  | T_K_DELETE unary_expression
  | T_INC unary_expression
  | T_DEC unary_expression
  | T_K_NEW unary_expression
  | T_K_THIS
  ;

postfix_expression
  : left_hand_side %prec PREC_NOPOST
  | left_hand_side { GUARD_NO_LINEBREAK(); } T_INC
  | left_hand_side { GUARD_NO_LINEBREAK(); } T_DEC
  ;

left_hand_side
  : member_or_call
  ;

/* trailer-list（成员/调用/索引） */
primary_expression
  : T_IDENTIFIER
  | literal
  | array_literal
  | object_literal
  | T_LPAREN expression T_RPAREN
  | T_K_THIS
  ;

primary_or_new
  : primary_expression
  | T_K_NEW primary_or_new T_LPAREN argument_list_opt T_RPAREN
  ;

trailer
  : T_LPAREN argument_list_opt T_RPAREN
  | T_DOT T_IDENTIFIER
  | T_LBRACK expression T_RBRACK   /* 修正：原来误写成 T_RPAREN */
  ;

trailers_opt
  : %empty
  | trailers_opt trailer
  ;

member_or_call
  : primary_or_new trailers_opt
  ;

argument_list_opt
  : %empty
  | argument_list
  ;

argument_list
  : assignment_expression
  | argument_list T_COMMA assignment_expression
  ;

literal
  : T_NUMERIC
  | T_STRING
  | T_K_TRUE
  | T_K_FALSE
  | T_K_NULL
  ;

array_literal
  : T_LBRACK elements_opt T_RBRACK
  ;

elements_opt
  : %empty
  | element_list
  ;

element_list
  : assignment_expression
  | element_list T_COMMA assignment_expression
  | element_list T_COMMA /* trailing comma */
  ;

object_literal
  : T_LBRACE prop_list_opt T_RBRACE
  ;

prop_list_opt
  : %empty
  | property_list
  ;

property_list
  : property
  | property_list T_COMMA property
  | property_list T_COMMA /* trailing comma */
  ;

property
  : property_name T_COLON assignment_expression
  ;

property_name
  : T_IDENTIFIER
  | T_STRING
  | T_NUMERIC
  ;

/* ASI: ';' 或在 LineTerminator / '}' / EOF 处自动插入 */
semi_opt
  : T_SEMI
  | %empty {
      int la=0, lt=0; (void)yypeek_token(scanner, drv, &la, &lt);
      if (la == 0) /* EOF */ ;
      else if (la == T_RBRACE) ;
      else if (lt) ;
      else YYERROR;
    }
  ;

/* ========== 仅用于 ExpressionStatement 的“非 { 开头”表达式链 (nb_) ========== */

nb_expression
  : nb_assignment_expression
  | nb_expression T_COMMA nb_assignment_expression
  ;

nb_assignment_expression
  : nb_conditional_expression
  | nb_left_hand_side T_ASSIGN nb_assignment_expression
  | nb_left_hand_side T_ADD_ASSIGN nb_assignment_expression
  | nb_left_hand_side T_SUB_ASSIGN nb_assignment_expression
  | nb_left_hand_side T_MUL_ASSIGN nb_assignment_expression
  | nb_left_hand_side T_DIV_ASSIGN nb_assignment_expression
  | nb_left_hand_side T_MOD_ASSIGN nb_assignment_expression
  | nb_left_hand_side T_AND_ASSIGN nb_assignment_expression
  | nb_left_hand_side T_OR_ASSIGN nb_assignment_expression
  | nb_left_hand_side T_XOR_ASSIGN nb_assignment_expression
  | nb_left_hand_side T_SHL_ASSIGN nb_assignment_expression
  | nb_left_hand_side T_SHR_ASSIGN nb_assignment_expression
  | nb_left_hand_side T_USHR_ASSIGN nb_assignment_expression
  ;

nb_conditional_expression
  : nb_logical_or_expression
  | nb_logical_or_expression T_QMARK nb_assignment_expression T_COLON nb_assignment_expression
  ;

nb_logical_or_expression
  : nb_logical_and_expression
  | nb_logical_or_expression T_OR nb_logical_and_expression
  ;

nb_logical_and_expression
  : nb_bit_or_expression
  | nb_logical_and_expression T_AND nb_bit_or_expression
  ;

nb_bit_or_expression
  : nb_bit_xor_expression
  | nb_bit_or_expression T_BIT_OR nb_bit_xor_expression
  ;

nb_bit_xor_expression
  : nb_bit_and_expression
  | nb_bit_xor_expression T_BIT_XOR nb_bit_and_expression
  ;

nb_bit_and_expression
  : nb_equality_expression
  | nb_bit_and_expression T_BIT_AND nb_equality_expression
  ;

nb_equality_expression
  : nb_relational_expression
  | nb_equality_expression T_EQ nb_relational_expression
  | nb_equality_expression T_NEQ nb_relational_expression
  | nb_equality_expression T_STRICT_EQ nb_relational_expression
  | nb_equality_expression T_STRICT_NEQ nb_relational_expression
  ;

nb_relational_expression
  : nb_shift_expression
  | nb_relational_expression T_LT nb_shift_expression
  | nb_relational_expression T_LTE nb_shift_expression
  | nb_relational_expression T_GT nb_shift_expression
  | nb_relational_expression T_GTE nb_shift_expression
  | nb_relational_expression T_K_INSTANCEOF nb_shift_expression
  | nb_relational_expression T_K_IN nb_shift_expression
  ;

nb_shift_expression
  : nb_additive_expression
  | nb_shift_expression T_SHL nb_additive_expression
  | nb_shift_expression T_SHR nb_additive_expression
  | nb_shift_expression T_USHR nb_additive_expression
  ;

nb_additive_expression
  : nb_multiplicative_expression
  | nb_additive_expression T_PLUS nb_multiplicative_expression
  | nb_additive_expression T_MINUS nb_multiplicative_expression
  ;

nb_multiplicative_expression
  : nb_unary_expression
  | nb_multiplicative_expression T_MUL nb_unary_expression
  | nb_multiplicative_expression T_DIV nb_unary_expression
  | nb_multiplicative_expression T_MOD nb_unary_expression
  ;

nb_unary_expression
  : nb_postfix_expression
  | T_NOT nb_unary_expression
  | T_BIT_NOT nb_unary_expression
  | T_PLUS nb_unary_expression
  | T_MINUS nb_unary_expression
  | T_K_TYPEOF nb_unary_expression
  | T_K_VOID nb_unary_expression
  | T_K_DELETE nb_unary_expression
  | T_INC nb_unary_expression
  | T_DEC nb_unary_expression
  | T_K_NEW nb_unary_expression
  | T_K_THIS
  ;

nb_postfix_expression
  : nb_left_hand_side %prec PREC_NOPOST
  | nb_left_hand_side { GUARD_NO_LINEBREAK(); } T_INC
  | nb_left_hand_side { GUARD_NO_LINEBREAK(); } T_DEC
  ;

nb_left_hand_side
  : nb_member_or_call
  ;

/* 不包含 object_literal 的 primary（防止语句以 { 开头） */
nb_primary_expression
  : T_IDENTIFIER
  | literal
  | array_literal
  | T_LPAREN nb_expression T_RPAREN
  | T_K_THIS
  ;

nb_primary_or_new
  : nb_primary_expression
  | T_K_NEW nb_primary_or_new T_LPAREN argument_list_opt T_RPAREN
  ;

nb_trailer
  : T_LPAREN argument_list_opt T_RPAREN
  | T_DOT T_IDENTIFIER
  | T_LBRACK nb_expression T_RBRACK
  ;

nb_trailers_opt
  : %empty
  | nb_trailers_opt nb_trailer
  ;

nb_member_or_call
  : nb_primary_or_new nb_trailers_opt
  ;

%%

void yyerror(void *scanner, ParserDriver *drv, const char *msg) {
  (void)scanner;
  drv->err_line = drv->line;
  drv->err_col = drv->col;
  snprintf(drv->err_msg, sizeof(drv->err_msg), "%s", msg ? msg : "parse error");
}
