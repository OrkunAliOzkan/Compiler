%option noyywrap

%{
/* Now in a section of C that will be embedded
   into the auto-generated code. Flex will not
   try to interpret code surrounded by %{ ... %} */

/* Bring in our declarations for token types and
   the yylval variable. */
#include "histogram.hpp"
#include <stdio.h>


// This is to work around an irritating bug in Flex
// https://stackoverflow.com/questions/46213840/get-rid-of-warning-implicit-declaration-of-function-fileno-in-flex
extern "C" int fileno(FILE *stream);

/* End the embedded code section. */
%}
Integer     	[0-9]
character   	[A-Z]|[a-z]
Decimal     	{Integer}+"."{Integer}*?
Symbol		   [!-~]
%%

(-?{Integer}+|(-?{Integer}+"/"{Integer}+)) | (-?{Decimal}|(-?{Decimal}"/"{Decimal}))
{
   fprintf(stderr, "Number : %s\n", yytext);
   yylval.numberValue = yytext;
   return Number;
}

{character}+|("["({character}|{Integer}|{Symbol})*"]")
{
   fprintf(stderr, "Word (w/o brakets) : %s\n", yytext);
   yylval->wordValue = std::stood(yytext);

   return Word;
}

\n
{
   fprintf(stderr, "Newline\n");
}
%%

/* Error handler. This will get called if none of the rules match. */
void yyerror (char const *s)
{
  fprintf (stderr, "Flex Error: %s\n", s); /* s is the text that wasn't matched */
  exit(1);
}

int main(void)
{

}
