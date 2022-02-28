%option noyywrap

%{
#include "histogram.hpp"
#include <stdio.h>
#include <string.h>
%}

Integer     	[0-9]
Decimal         {Integer}+"."?{Integer}*
character   	[A-Z]|[a-z]
Hexadecimal     [0-9]|[A-F]|[a-f]
SciNotation     {Decimal}{"E"|"e"}{Integer}
%%

/*  DataTypes   */
"int"               {return(DATATYPE_INT);  }
"char"              {return(DATATYPE_CHAR); }
"float"             {return(DATATYPE_FLOAT);}
"long"              {return(DATATYPE_LONG); }
"short"             {return(DATATYPE_SHORT);}
"void"              {return(DATATYPE_VOID); }

/*  IF-ELSE     */
"if"                {return(IF);            }
"else"              {return(ELSE);          }
"break"             {return(BREAK);         }

/*  FOR/WHILE   */
"do"                {return(DO);            }
"while"             {return(WHILE);         }
"for"               {return(FOR);           }
"continue"          {return(CONTINUE);      }
"goto"              {return(GOTO);          }

/*  Keywords    */
"signed"            {return(SIGNED);        }
"unsigned"          {return(UNSIGNED);      }

/*  Conditional Operators   */
"<"                 {return(CONDITIONAL_<); }
"<="                {return(CONDITIONAL_<=);}
">"                 {return(CONDITIONAL_>); }
">="                {return(CONDITIONAL_>=);}
"=="                {return(CONDITIONAL_==);}

/*  Arithmetic Operators    */
"+"                {return(ARITHMETIC_+);   }
"-"                {return(ARITHMETIC_-);   }
"/"                {return(ARITHMETIC_/);   }
"="                {return(ARITHMETIC_=);   }

/*  Mathematical Operators  */
"*"                {return(*);              }
"&"                {return(&);              }

/*  Pointer Operators       */

/*  Basic Syntax characters */



.                   {/*Undesired/Undefined*/}

void yyerror (char const *s)
{
  	fprintf (stderr, "Flex Error: %s\n", s); /* s is the text that wasn't matched */
  	exit(1);
}