%option noyywrap
%{
#include <stdio.h>
%}
Integer     	[0-9]
character   	[A-Z]|[a-z]
Decimal     	{Integer}+"."{Integer}*
Symbol		[!-~]
%%
(-?{Integer}+|(-?{Integer}+"/"{Integer}+))	{	printf("Integer:%s\n",yytext);			}
(-?{Decimal}|(-?{Decimal}"/"{Decimal}))		{	printf("Decimal:%s\n",yytext);			}
{character}+					{	printf("Word:%s\n",yytext);			}
("["({character}|{Integer}|{Symbol})*"]") 	{	printf("Text with brackets: %s", yytext);	}
\n						{	printf("Newline");				}
.						{	printf("Error!");				}
%%
int main()
{
    yylex();
}
