%code requires{
  //#include "ast.hpp"  //  TODO: Build syntax tree
	#include <string>
	#include <cassert>

  extern const Expression *g_root; // A way of getting the AST out

  //! This is to fix problems when generating C++
  // We are declaring the functions provided by Flex, so
  // that Bison generated code can call them.
  int yylex(void);
  void yyerror(const char *);
}

// Represents the value associated with any kind of
// AST node.
%union{
  const Expression *expr;
  int int_numb;
  double double_num;
  float float_num;
  std::string *string;
}

/*Types*/
%token DATATYPE_INT DATATYPE_CHAR DATATYPE_FLOAT 
 
%token DATATYPE_LONG DATATYPE_SHORT DATATYPE_VOID 
%token DATATYPE_AUTO DATATYPE_TYPEDEF DATATYPE_STRUCT DATATYPE_ENUM DATATYPE_REGISTER
%token SIGNED UNSIGNED DATATYPE_DOUBLE
%token TYPE_NAME CONST ELLIPSIS

/*Conditionals*/
%token IF ELSE BREAK SWITCH CASE

/*Loops*/
%token DO WHILE FOR CONTINUE GOTO

/*Unary operators*/
%token CONDITIONAL_LT CONDITIONAL_LTET CONDITIONAL_GT CONDITIONAL_GTET CONDITIONAL_EE
%token INC_OP DEC_OP PTR_OP AND_OP OR_OP NE_OP

/*Brackets*/
%token<string> LBRACKET RBRACKET L_SQBRACKET R_SQBRACKET L_CURBRACKET R_CURBRACKET

%token DOT

%token LEFT_OP RIGHT_OP 

/*Arithmetic Operators*/
%token ARITHMETIC_PLUS ARITHMETIC_DEDUCT ARITHMETIC_DASH ARITHMETIC_E

/*Assignment Operators*/
%token<string> MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN ADD_ASSIGN SUB_ASSIGN LEFT_ASSIGN RIGHT_ASSIGN AND_ASSIGN XOR_ASSIGN OR_ASSIGN


/*Misc*/
%token TYPE_STAR TYPE_AMPERSAND RETURN SEMICOLON L_COMMENT_ML R_COMMENT_ML
%token DEFAULT EXTERN SIZEOF STATIC UNION VOLATILE

// Added condition, iterate + evaluate
%type<expr> primary_expression postfix_expression unary_expression cast_expression multiplicative_expression additive_expression shift_expression relational_expression
equality_expression and_expression exclusive_or_expression inclusive_or_expression logical_and_expression logical_or_expression conditional_expression assignment_expression
expression initializer
%token<int_numb> T_INT
%token<string> T_VARIABLE STRING

%start ROOT

%%

primary_expression
	: T_VARIABLE
	| T_INT
	| STRING
	| LBRACKET expression RBRACKET
	;

postfix_expression
	: primary_expression
	| postfix_expression L_SQBRACKET expression R_SQBRACKET
	| postfix_expression LBRACKET RBRACKET
	| postfix_expression LBRACKET argument_expression_list RBRACKET
	| postfix_expression DOT T_VARIABLE
	| postfix_expression PTR_OP T_VARIABLE
	| postfix_expression INC_OP
	| postfix_expression DEC_OP
	;

argument_expression_list
	: assignment_expression
	| argument_expression_list ',' assignment_expression
	;

unary_expression
	: postfix_expression
	| INC_OP unary_expression
	| DEC_OP unary_expression
	| unary_operator cast_expression
	| SIZEOF unary_expression
	| SIZEOF LBRACKET type_name RBRACKET
	;

unary_operator
	: TYPE_AMPERSAND
	| TYPE_STAR
	| ARITHMETIC_PLUS
	| ARITHMETIC_DEDUCT
	| '~'
	| '!'
	;

cast_expression
	: unary_expression
	| LBRACKET type_name RBRACKET cast_expression
	;

multiplicative_expression
	: cast_expression
	| multiplicative_expression TYPE_STAR cast_expression
	| multiplicative_expression ARITHMETIC_DASH cast_expression
	| multiplicative_expression '%' cast_expression
	;

additive_expression
	: multiplicative_expression
	| additive_expression ARITHMETIC_PLUS multiplicative_expression
	| additive_expression ARITHMETIC_DEDUCT multiplicative_expression
	;

shift_expression
	: additive_expression
	| shift_expression LEFT_OP additive_expression
	| shift_expression RIGHT_OP additive_expression
	;

relational_expression
	: shift_expression
	| relational_expression CONDITIONAL_LT shift_expression
	| relational_expression CONDITIONAL_GT shift_expression
	| relational_expression CONDITIONAL_LTET shift_expression
	| relational_expression CONDITIONAL_GTET shift_expression
	;

equality_expression
	: relational_expression
	| equality_expression CONDITIONAL_EE relational_expression
	| equality_expression NE_OP relational_expression
	;

and_expression
	: equality_expression
	| and_expression TYPE_AMPERSAND equality_expression
	;

exclusive_or_expression
	: and_expression
	| exclusive_or_expression '^' and_expression
	;

inclusive_or_expression
	: exclusive_or_expression
	| inclusive_or_expression '|' exclusive_or_expression
	;

logical_and_expression
	: inclusive_or_expression
	| logical_and_expression AND_OP inclusive_or_expression
	;

logical_or_expression
	: logical_and_expression
	| logical_or_expression OR_OP logical_and_expression
	;

conditional_expression
	: logical_or_expression
	| logical_or_expression '?' expression ':' conditional_expression
	;

assignment_expression
	: conditional_expression
	| unary_expression assignment_operator assignment_expression
	;

assignment_operator
	: ARITHMETIC_E
	| MUL_ASSIGN
	| DIV_ASSIGN
	| MOD_ASSIGN
	| ADD_ASSIGN
	| SUB_ASSIGN
	| LEFT_ASSIGN
	| RIGHT_ASSIGN
	| AND_ASSIGN
	| XOR_ASSIGN
	| OR_ASSIGN
	;

expression
	: assignment_expression                     {$$ = new Unary_Expression($1, "ASSIGN");   }
	| expression ',' assignment_expression
	;

constant_expression
	: conditional_expression
	;

declaration
	: declaration_specifiers SEMICOLON
	| declaration_specifiers init_declarator_list SEMICOLON
	;

declaration_specifiers
	: storage_class_specifier
	| storage_class_specifier declaration_specifiers
	| type_specifier
	| type_specifier declaration_specifiers
	| type_qualifier
	| type_qualifier declaration_specifiers
	;

init_declarator_list
	: init_declarator
	| init_declarator_list ',' init_declarator
	;

init_declarator
	: declarator
	| declarator ARITHMETIC_E initializer
	;

storage_class_specifier
	: DATATYPE_TYPEDEF
	| EXTERN
	| STATIC
	| DATATYPE_AUTO
	| DATATYPE_REGISTER
	;

type_specifier
	: DATATYPE_VOID
	| DATATYPE_CHAR
	| DATATYPE_SHORT
	| DATATYPE_INT
	| DATATYPE_LONG
	| DATATYPE_FLOAT
	| DATATYPE_DOUBLE
	| SIGNED
	| UNSIGNED
	| struct_or_union_specifier
	| enum_specifier
	| TYPE_NAME
	;

struct_or_union_specifier
	: struct_or_union T_VARIABLE L_CURBRACKET struct_declaration_list R_CURBRACKET
	| struct_or_union L_CURBRACKET struct_declaration_list R_CURBRACKET
	| struct_or_union T_VARIABLE
	;

struct_or_union
	: DATATYPE_STRUCT
	| UNION
	;

struct_declaration_list
	: struct_declaration
	| struct_declaration_list struct_declaration
	;

struct_declaration
	: specifier_qualifier_list struct_declarator_list SEMICOLON
	;

specifier_qualifier_list
	: type_specifier specifier_qualifier_list
	| type_specifier
	| type_qualifier specifier_qualifier_list
	| type_qualifier
	;

struct_declarator_list
	: struct_declarator
	| struct_declarator_list ',' struct_declarator
	;

struct_declarator
	: declarator
	| ':' constant_expression
	| declarator ':' constant_expression
	;

enum_specifier
	: DATATYPE_ENUM L_CURBRACKET enumerator_list R_CURBRACKET
	| DATATYPE_ENUM T_VARIABLE L_CURBRACKET enumerator_list R_CURBRACKET
	| DATATYPE_ENUM T_VARIABLE
	;

enumerator_list
	: enumerator
	| enumerator_list ',' enumerator
	;

enumerator
	: T_VARIABLE
	| T_VARIABLE ARITHMETIC_E constant_expression
	;

type_qualifier
	: CONST
	| VOLATILE
	;

declarator
	: pointer direct_declarator
	| direct_declarator
	;

direct_declarator
	: T_VARIABLE
	| LBRACKET declarator RBRACKET
	| direct_declarator L_SQBRACKET constant_expression R_SQBRACKET
	| direct_declarator L_SQBRACKET R_SQBRACKET
	| direct_declarator LBRACKET parameter_type_list RBRACKET
	| direct_declarator LBRACKET identifier_list RBRACKET
	| direct_declarator LBRACKET RBRACKET
	;

pointer
	: TYPE_STAR
	| TYPE_STAR type_qualifier_list
	| TYPE_STAR pointer
	| TYPE_STAR type_qualifier_list pointer
	;

type_qualifier_list
	: type_qualifier
	| type_qualifier_list type_qualifier
	;


parameter_type_list
	: parameter_list
	| parameter_list ',' ELLIPSIS
	;

parameter_list
	: parameter_declaration
	| parameter_list ',' parameter_declaration
	;

parameter_declaration
	: declaration_specifiers declarator
	| declaration_specifiers abstract_declarator
	| declaration_specifiers
	;

identifier_list
	: T_VARIABLE
	| identifier_list ',' T_VARIABLE
	;

type_name
	: specifier_qualifier_list
	| specifier_qualifier_list abstract_declarator
	;

abstract_declarator
	: pointer
	| direct_abstract_declarator
	| pointer direct_abstract_declarator
	;

direct_abstract_declarator
	: LBRACKET abstract_declarator RBRACKET
	| L_SQBRACKET R_SQBRACKET
	| L_SQBRACKET constant_expression R_SQBRACKET
	| direct_abstract_declarator L_SQBRACKET R_SQBRACKET
	| direct_abstract_declarator L_SQBRACKET constant_expression R_SQBRACKET
	| LBRACKET RBRACKET
	| LBRACKET parameter_type_list RBRACKET
	| direct_abstract_declarator LBRACKET RBRACKET
	| direct_abstract_declarator LBRACKET parameter_type_list RBRACKET
	;

initializer
	: assignment_expression
	| L_CURBRACKET initializer_list R_CURBRACKET
	| L_CURBRACKET initializer_list ',' R_CURBRACKET
	;

initializer_list
	: initializer
	| initializer_list ',' initializer
	;

statement
	: labeled_statement
	| compound_statement
	| expression_statement
	| selection_statement
	| iteration_statement
	| jump_statement
	;

labeled_statement
	: T_VARIABLE ':' statement
	| CASE constant_expression ':' statement
	| DEFAULT ':' statement
	;

compound_statement
	: L_CURBRACKET R_CURBRACKET
	| L_CURBRACKET statement_list R_CURBRACKET
	| L_CURBRACKET declaration_list R_CURBRACKET
	| L_CURBRACKET declaration_list statement_list R_CURBRACKET
	;

declaration_list
	: declaration
	| declaration_list declaration
	;

statement_list
	: statement
	| statement_list statement
	;

expression_statement
	: SEMICOLON
	| expression SEMICOLON
	;

selection_statement
	: IF LBRACKET expression RBRACKET statement
	| IF LBRACKET expression RBRACKET statement ELSE statement
	| SWITCH LBRACKET expression RBRACKET statement
	;

iteration_statement
	: WHILE LBRACKET expression RBRACKET statement
	| DO statement WHILE LBRACKET expression RBRACKET SEMICOLON
	| FOR LBRACKET expression_statement expression_statement RBRACKET statement
	| FOR LBRACKET expression_statement expression_statement expression RBRACKET statement
	;

jump_statement
	: GOTO T_VARIABLE SEMICOLON
	| CONTINUE SEMICOLON
	| BREAK SEMICOLON
	| RETURN SEMICOLON
	| RETURN expression SEMICOLON
	;

ROOT
	: external_declaration
	| ROOT external_declaration
	;

external_declaration
	: function_definition
	| declaration
	;

function_definition
	: declaration_specifiers declarator declaration_list compound_statement
	| declaration_specifiers declarator compound_statement
	| declarator declaration_list compound_statement
	| declarator compound_statement
	;

%%
#include <stdio.h>

extern char yytext[];
extern int column;

yyerror(s)
char *s;
{
	fflush(stdout);
	printf("\n%*s\n%*s\n", column, "^", column, s);
}