%option noyywrap

%{
#include stdio.h
%}
Integer     [0-9]
character   [A-z] /* Check ASCII table for clarity*/
Num         {Integer}+(.{Integer}*)? /* TODO: Check!*/

%%
(-?Num | ({-?Num}"/"{Num}))
{
   fprintf(stderr, "Number : %s\n", yytext); 
   /* TODO: get value out of yytext and into yylval.numberValue */
   return Number;
}

character
{
   fprintf(stderr, "Word : %s\n", yytext);
}


\n
{
   fprintf(stderr, "Newline\n");
}
%%
int main(void)
{
    yylex();
}
