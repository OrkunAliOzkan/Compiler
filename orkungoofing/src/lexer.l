%option noyywrap

%{
// Avoid error "error: `fileno' was not declared in this scope"
extern "C" int fileno(FILE *stream);

#include "maths_parser.tab.hpp"
%}

Integer     	[0-9]
Decimal         (Integer)+"."?(Integer)*
character   	[A-Z]|[a-z]
Hexadecimal     [0-9]|[A-F]|[a-f]
SciNotation     (Decimal)("E"|"e")(Integer)

%%

character+          { yylval.string=new std::string(yytext);  return T_VARIABLE; }
Decimal		          { yylval.number=strtod(yytext, 0);        return T_NUMBER; }
"int"               { return(DATATYPE_INT);  	}
"char"              { return(DATATYPE_CHAR); 	}
"float"             { return(DATATYPE_FLOAT);	}
"long"              { return(DATATYPE_LONG); 	}
"short"             { return(DATATYPE_SHORT);	}
"void"              { return(DATATYPE_VOID); 	}

"if"                { return(IF);            	}
"else"              { return(ELSE);          	}
"break"             { return(BREAK);         	}

"do"                { return(DO);            	}
"while"             { return(WHILE);         	}
"for"               { return(FOR);           	}
"continue"          { return(CONTINUE);      	}
"goto"              { return(GOTO);          	}

"signed"            { return(SIGNED);        	}
"unsigned"          { return(UNSIGNED);      	}

"<"                 { return(CONDITIONAL_LT); 	}
"<="                { return(CONDITIONAL_LTET);	}
">"                 { return(CONDITIONAL_GT); 	}
">="                { return(CONDITIONAL_GTET);	}
"=="                { return(CONDITIONAL_EE);	}

"("					        { return(T_LBRACKET);		  }
")"					        { return(T_RBRACKET);		}

"+"                	{ return(ARITHMETIC_PLUS);	  }
"-"                	{ return(ARITHMETIC_DEDUCT);	}
"/"                	{ return(ARITHMETIC_DASH);	  }
"="                	{ return(ARITHMETIC_E);		    }

"*"                	{ return(TYPE_STAR);			  }
"&"                	{ return(TYPE_AMPERSAND);		}
"return"           	{ return(RETURN);           }
";"                	{ return(SEMICOLON);        }
[ \t\v\n\f]		   	{}

.               { fprintf(stderr, "Invalid token\n"); exit(1); }

%%

void yyerror (char const *s)
{
  fprintf (stderr, "Parse error : %s\n", s);
  exit(1);
}
