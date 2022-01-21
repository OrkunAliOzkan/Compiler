%option noyywrap

%{
#include stdio.h
%}
Integer     [0-9]
character   [A-z] /* Check ASCII table for clarity*/
Num         {-}?{Decimal}+( {.}{Decimal}* )? /* TODO: Check!*/
%%
/*  yylex() */
Num | {Num}{/}?{Num}
{
   fprintf(stderr, "Number : %s\n", yytext); 
   /* TODO: get value out of yytext and into yylval.numberValue */
   return Number;
}

l+
{
   fprintf(stderr, "Word : %s\n", yytext);
   /* TODO: get value out of yytext and into yylval.wordValue */
   return Word;
}

L+
{
   fprintf(stderr, "Word : %s\n", yytext);
   /* TODO: get value out of yytext and into yylval.wordValue */
   return Word;
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