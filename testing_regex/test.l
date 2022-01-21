%option noyywrap
%{
#include <stdio.h>
%}
Integer     [0-9]
character   [A-z]
Num         {Integer}+(.{Integer}*)?
%%
(-?{Num}|(-?{Num}"/"{Num}))
{
   printf("Number:%s\n",yytext); 
}
{character}+
{
   printf("Word:%s\n",yytext);
}
\n
{
   printf("Newline");
}
.
{
   printf("Error!");
}
%%
int main()
{
    yylex();
}
