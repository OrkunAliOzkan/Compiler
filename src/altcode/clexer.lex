%option noyywrap

%%

"if"     { return IF; }
"else"   { return ELSE; }
"return" { return RETURN; }

[a-z]    { yylval.ident = yytext[0];
           return IDENT; }

[0-9]+    { yylval.number = atoi(yytext);
           return NUMBER; }

[ \t]    { }

.|\n    { return yytext[0]; }
