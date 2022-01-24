%option noyywrap
%{
    #include <stdio.h>
    #include "histogram.hpp"
    extern "C" int fileno(FILE stream);
%}
Letter [a-z]|[A-Z]
Digit [0-9]
Symbol [!-~]
Decimal {Digit}+"."{Digit}?

/* Add line break functionality to WORDS and NUMBERS. /
/ Add line break functionalsity to WORDS and NUMBERS. /

%%
({Letter}+)|("["({Letter}|{Digit}|{Symbol})"]") {
    fprintf(stderr, "Word: %s", yytext);
    yylval.wordValue = yytext;
    return Word;
    }
(-?{Digit}+|(-?{Digit}+"/"{Digit}+))|(-?{Decimal}|(-?{Decimal}"/"{Decimal})) {
    fprintf(stderr, "Number: %s", yytext);
    yylval.numberValue = std::stod(yytext);
    return Number;
    }
\n {
    fprintf(stderr, "Newline\n");
    }
%%

/ Error handler. This will get called if none of the rules match. */
void yyerror (char const s)
{
  fprintf (stderr, "Flex Error: %s\n", s); / s is the text that wasn't matched */
  exit(1);
}
