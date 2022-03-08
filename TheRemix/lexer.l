%option noyywrap

%{
// Avoid error "error: `fileno' was not declared in this scope"
extern "C" int fileno(FILE *stream);

#include "maths_parser.tab.hpp"
%}

Integer     	[0-9]
Decimal       (Integer)+"."?(Integer)*
character   	[A-Z]|[a-z]
Hexadecimal     [0-9]|[A-F]|[a-f]
SciNotation     (Decimal)("E"|"e")(Integer)
AcceptedNum     {Decimal}|{Hexadecimal}|{Integer}{SciNotation}
FS			(f|F|l|L)
IS			(u|U|l|L)*

%%

Integer             { return T_INT; }

{character}({character}|{Integer})* {return(VAR_NAME);}
\"(\\.|[^"\\])*\"   { return(STRING); }

"int"               { return(DATATYPE_INT);  	    }
"char"              { return(DATATYPE_CHAR); 	    }
"float"             { return(DATATYPE_FLOAT);	    }
"long"              { return(DATATYPE_LONG); 	    }
"short"             { return(DATATYPE_SHORT);	    }
"void"              { return(DATATYPE_VOID); 	    }
"auto"			        { return(DATATYPE_AUTO);      }
"typedef"		        { return(DATATYPE_TYPEDEF);   }
"struct"		        { return(DATATYPE_STRUCT);    }
"enum"			        { return(DATATYPE_ENUM);      }
"register"	        { return(DATATYPE_REGISTER);  }
"double"	          { return(DATATYPE_DOUBLE);    }

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

"("					        { return(L_BRACKET);		      }
")"					        { return(R_BRACKET);		      }
("["|"<:")		      { return(L_SQBRACKET);        }
("]"|":>")		      { return(R_SQBRACKET);        }
("{"|"<%")		      { return(L_CURBRACKET);       }
("}"|"%>")		      { return(R_CURBRACKET);       }

"."                 { return DOT; }

"+"                	{ return(ARITHMETIC_PLUS);	  }
"-"                	{ return(ARITHMETIC_DEDUCT);	}
"/"                	{ return(ARITHMETIC_DASH);	  }
"="                	{ return(ARITHMETIC_E);		    }

"*"                	{ return(TYPE_STAR);			    }
"&"                	{ return(TYPE_AMPERSAND);		  }
"return"           	{ return(RETURN);             }
";"                	{ return(SEMICOLON);          }
"/*"			          { return(L_COMMENT_ML)        }
"*/"			          { return(R_COMMENT_ML)        }

"default"		        { return(DEFAULT);            }
"extern"		        { return(EXTERN);             }
"sizeof"		        { return(SIZEOF);             }
"static"		        { return(STATIC);             }
"union"			        { return(UNION);              }
"volatile"		      { return(VOLATILE);           }

"..."			          { return(ELLIPSIS);           }
">>="			          { return(RIGHT_ASSIGN);       }
"<<="			          { return(LEFT_ASSIGN);        }
"+="			          { return(ADD_ASSIGN);         }
"-="			          { return(SUB_ASSIGN);         }
"*="			          { return(MUL_ASSIGN);         }
"/="			          { return(DIV_ASSIGN);         }
"%="			          { return(MOD_ASSIGN);         }
"&="			          { return(AND_ASSIGN);         }
"^="			          { return(XOR_ASSIGN);         }
"|="			          { return(OR_ASSIGN);          }
">>"			          { return(RIGHT_OP);           }
"<<"			          { return(LEFT_OP);            }
"++"			          { return(INC_OP);             }
"--"			          { return(DEC_OP);             }
"->"			          { return(PTR_OP);             }
"&&"			          { return(AND_OP);             }
"||"			          { return(OR_OP);              }
"!="			          { return(NE_OP);              }


[ \t\v\n\f]		   	  {}

.                   { fprintf(stderr, "Invalid token\n"); exit(1); }

%%

void yyerror (char const *s)
{
  fprintf (stderr, "Parse error : %s\n", s);
  exit(1);
}


/*
{L}({L}|{D})*		{ return(check_type()); }

0[xX]{H}+{IS}?		{ return(CONSTANT); }
0{D}+{IS}?		{ return(CONSTANT); }
{D}+{IS}?		{ return(CONSTANT); }
L?'(\\.|[^\\'])+'	{ return(CONSTANT); }

{D}+{E}{FS}?		{ return(CONSTANT); }
{D}*"."{D}+({E})?{FS}?	{ return(CONSTANT); }
{D}+"."{D}*({E})?{FS}?	{ return(CONSTANT); }

L?\"(\\.|[^\\"])*\"	{ return(STRING_LITERAL); }

"..."			{ return(ELLIPSIS); }
">>="			{ return(RIGHT_ASSIGN); }
"<<="			{ return(LEFT_ASSIGN); }
"+="			{ return(ADD_ASSIGN); }
"-="			{ return(SUB_ASSIGN); }
"*="			{ return(MUL_ASSIGN); }
"/="			{ return(DIV_ASSIGN); }
"%="			{ return(MOD_ASSIGN); }
"&="			{ return(AND_ASSIGN); }
"^="			{ return(XOR_ASSIGN); }
"|="			{ return(OR_ASSIGN); }
">>"			{ return(RIGHT_OP); }
"<<"			{ return(LEFT_OP); }
"++"			{ return(INC_OP); }
"--"			{ return(DEC_OP); }
"->"			{ return(PTR_OP); }
"&&"			{ return(AND_OP); }
"||"			{ return(OR_OP); }
"<="			{ return(LE_OP); }
">="			{ return(GE_OP); }
"=="			{ return(EQ_OP); }
"!="			{ return(NE_OP); }
";"			{ return(';'); }
("{"|"<%")		{ return('{'); }
("}"|"%>")		{ return('}'); }
","			{ return(','); }
":"			{ return(':'); }
"="			{ return('='); }
"("			{ return('('); }
")"			{ return(')'); }
("["|"<:")		{ return('['); }
("]"|":>")		{ return(']'); }
"."			{ return('.'); }
"&"			{ return('&'); }
"!"			{ return('!'); }
"~"			{ return('~'); }
"-"			{ return('-'); }
"+"			{ return('+'); }
"*"			{ return('*'); }
"/"			{ return('/'); }
"%"			{ return('%'); }
"<"			{ return('<'); }
">"			{ return('>'); }
"^"			{ return('^'); }
"|"			{ return('|'); }
"?"			{ return('?'); }

[ \t\v\n\f]		{ }
.			{ }


*/