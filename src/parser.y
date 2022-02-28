%union {char *string; char ident; int number;}

%token DATATYPE_INT DATATYPE_CHAR DATATYPE_FLOAT DATATYPE_LONG DATATYPE_SHORT DATATYPE_VOID
%token DO WHILE FOR CONTINUE GOTO
%token SIGNED UNSIGNED

%token CONDITIONAL_LT CONDITIONAL_LTET CONDITIONAL_GT CONDITIONAL_GTET CONDITIONAL_EE
%token ARITHMETIC_PLUS ARITHMETIC_DEDUCT ARITHMETIC_DASH ARITHMETIC_E
%token TYPE_STAR TYPE_AMPERSAND

%token IF ELSE RETURN BREAK

%token<ident> IDENT
%token<number> NUMBER

%start line

%type<string> stmt expr
%type<number> line

%{
  #include <stdio.h>
%}

%%

line :
  stmt '\n'    { printf ("\nParsed as:\n%s\n\n", $1); return 0; }
;

expr :
  IDENT '>' NUMBER {
                 char *buffer = malloc(100);
                 sprintf(buffer, "%c > %d", $1, $3);
		 $$ = buffer; }
;

stmt :
  IF '(' expr ')' stmt {
                 char *buffer = malloc(100);
                 sprintf(buffer, "if (%s) { %s }", $3, $5);
		 $$ = buffer; }
| IF '(' expr ')' stmt ELSE stmt {
                 char *buffer = malloc(100);
                 sprintf(buffer, "if (%s) { %s } else { %s }", $3, $5, $7);
		 $$ = buffer; }
| RETURN NUMBER ';' {
                 char *buffer = malloc(100);
                 sprintf(buffer, "return %d;", $2);
		 $$ = buffer; }
;

%%

#include "lex.yy.c"

int main() {
  yyparse(); // parse user input
}

int yyerror (char *s) {
  fprintf (stderr, "%s\n", s);
  exit(1);
}