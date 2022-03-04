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
FS			(f|F|l|L)
IS			(u|U|l|L)*

%%

character+          { yylval.string=new std::string(yytext);  return T_VARIABLE; }
Decimal		          { yylval.number=strtod(yytext, 0);        return T_NUMBER; }
"int"               { return(DATATYPE_INT);  	}
"char"              { return(DATATYPE_CHAR); 	}
"float"             { return(DATATYPE_FLOAT);	}
"long"              { return(DATATYPE_LONG); 	}
"short"             { return(DATATYPE_SHORT);	}
"void"              { return(DATATYPE_VOID); 	}
"auto"			        { return(DATATYPE_AUTO);      }
"typedef"		        { return(DATATYPE_TYPEDEF);   }
"struct"		        { return(DATATYPE_STRUCT);    }
"enum"			        { return(DATATYPE_ENUM);      }
"register"	        { return(REGISTER);           }

"if"                { return(IF);            	    }
"else"              { return(ELSE);          	    }
"break"             { return(BREAK);         	    }
"switch"		        { return(SWITCH);             }
"case"			        { return(CASE);               }

"do"                { return(DO);            	    }
"while"             { return(WHILE);         	    }
"for"               { return(FOR);           	    }
"continue"          { return(CONTINUE);      	    }

"signed"            { return(SIGNED);        	    }
"unsigned"          { return(UNSIGNED);      	    }

"<"                 { return(CONDITIONAL_LT); 	  }
"<="                { return(CONDITIONAL_LTET);	  }
">"                 { return(CONDITIONAL_GT); 	  }
">="                { return(CONDITIONAL_GTET);	  }
"=="                { return(CONDITIONAL_EE);	    }

"("					        { return(T_LBRACKET);		      }
")"					        { return(T_RBRACKET);		      }

"+"                	{ return(ARITHMETIC_PLUS);	  }
"-"                	{ return(ARITHMETIC_DEDUCT);	}
"/"                	{ return(ARITHMETIC_DASH);	  }
"="                	{ return(ARITHMETIC_E);		    }

"*"                	{ return(TYPE_STAR);			    }
"&"                	{ return(TYPE_AMPERSAND);		  }
"return"           	{ return(RETURN);             }
";"                	{ return(SEMICOLON);          }
"/*"			          { comment(); }


"default"		        { return(DEFAULT);   }
"extern"		        { return(EXTERN);    }
"sizeof"		        { return(SIZEOF);    }
"static"		        { return(STATIC);    }
"union"			        { return(UNION);     }
"volatile"		      { return(VOLATILE);  }
[ \t\v\n\f]		   	  {}
{character}({character}|{Integer})* {return(VAR_NAME);}
//{}|{}|{}|{}|{}|{}{return(CONSTANT);  }
.                   { fprintf(stderr, "Invalid token\n"); exit(1); }

%%

void yyerror (char const *s)
{
  fprintf (stderr, "Parse error : %s\n", s);
  exit(1);
}


/*
{L}({L}|{D})*		{ count(); return(check_type()); }

0[xX]{H}+{IS}?		{ count(); return(CONSTANT); }
0{D}+{IS}?		{ count(); return(CONSTANT); }
{D}+{IS}?		{ count(); return(CONSTANT); }
L?'(\\.|[^\\'])+'	{ count(); return(CONSTANT); }

{D}+{E}{FS}?		{ count(); return(CONSTANT); }
{D}*"."{D}+({E})?{FS}?	{ count(); return(CONSTANT); }
{D}+"."{D}*({E})?{FS}?	{ count(); return(CONSTANT); }

L?\"(\\.|[^\\"])*\"	{ count(); return(STRING_LITERAL); }

"..."			{ count(); return(ELLIPSIS); }
">>="			{ count(); return(RIGHT_ASSIGN); }
"<<="			{ count(); return(LEFT_ASSIGN); }
"+="			{ count(); return(ADD_ASSIGN); }
"-="			{ count(); return(SUB_ASSIGN); }
"*="			{ count(); return(MUL_ASSIGN); }
"/="			{ count(); return(DIV_ASSIGN); }
"%="			{ count(); return(MOD_ASSIGN); }
"&="			{ count(); return(AND_ASSIGN); }
"^="			{ count(); return(XOR_ASSIGN); }
"|="			{ count(); return(OR_ASSIGN); }
">>"			{ count(); return(RIGHT_OP); }
"<<"			{ count(); return(LEFT_OP); }
"++"			{ count(); return(INC_OP); }
"--"			{ count(); return(DEC_OP); }
"->"			{ count(); return(PTR_OP); }
"&&"			{ count(); return(AND_OP); }
"||"			{ count(); return(OR_OP); }
"<="			{ count(); return(LE_OP); }
">="			{ count(); return(GE_OP); }
"=="			{ count(); return(EQ_OP); }
"!="			{ count(); return(NE_OP); }
";"			{ count(); return(';'); }
("{"|"<%")		{ count(); return('{'); }
("}"|"%>")		{ count(); return('}'); }
","			{ count(); return(','); }
":"			{ count(); return(':'); }
"="			{ count(); return('='); }
"("			{ count(); return('('); }
")"			{ count(); return(')'); }
("["|"<:")		{ count(); return('['); }
("]"|":>")		{ count(); return(']'); }
"."			{ count(); return('.'); }
"&"			{ count(); return('&'); }
"!"			{ count(); return('!'); }
"~"			{ count(); return('~'); }
"-"			{ count(); return('-'); }
"+"			{ count(); return('+'); }
"*"			{ count(); return('*'); }
"/"			{ count(); return('/'); }
"%"			{ count(); return('%'); }
"<"			{ count(); return('<'); }
">"			{ count(); return('>'); }
"^"			{ count(); return('^'); }
"|"			{ count(); return('|'); }
"?"			{ count(); return('?'); }

[ \t\v\n\f]		{ count(); }
.			{ }


*/