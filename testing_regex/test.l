%option noyywrap
%{
#include <stdio.h>
%}
Integer     [0-9]
character   [A-z]
Decimal     {Integer}+"."{Integer}*
%%
(-?{Integer}+|(-?{Integer}+"/"{Integer}+))	{	printf("Integer:%s\n",yytext);	}
(-?{Decimal}|(-?{Decimal}"/"{Decimal}))		{	printf("Decimal:%s\n",yytext);	}
{character}+					{	printf("Word:%s\n",yytext);	}
\n						{	printf("Newline");		}
.						{	printf("Error!");		}
%%
int main()
{
    yylex();
}
