%union {char *string; char ident; int number;}

%token IF RETURN ELSE
%token<ident> IDENT
%token<number> NUMBER

%start line

%type<string> stmt open_stmt closed_stmt expr
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
  open_stmt
| closed_stmt
;

open_stmt:
  IF '(' expr ')' stmt {
                 char *buffer = malloc(100);
                 sprintf(buffer, "if (%s) { %s }", $3, $5);
		 $$ = buffer; }
| IF '(' expr ')' closed_stmt ELSE open_stmt  {
                 char *buffer = malloc(100);
                 sprintf(buffer, "if (%s) { %s } else { %s }", $3, $5, $7);
		 $$ = buffer; } 
;

closed_stmt :
  IF '(' expr ')' closed_stmt ELSE closed_stmt {
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
