%option noyywrap

Integer     	[0-9]
Decimal         (Integer)+"."?(Integer)*
character   	[A-Z]|[a-z]
Hexadecimal     [0-9]|[A-F]|[a-f]
SciNotation     (Decimal)("E"|"e")(Integer)

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
