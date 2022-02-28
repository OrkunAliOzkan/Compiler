%option noyywrap

%{
#include <stdio.h>
#include <string.h>
%}

Integer     	[0-9]
Decimal         {Integer}+"."?{Integer}*
character   	[A-Z]|[a-z]
Hexadecimal     [0-9]|[A-F]|[a-f]
SciNotation     {Decimal}{"E"|"e"}{Integer}

%%

"int"               {return(DATATYPE_INT);  }
"char"              {return(DATATYPE_CHAR); }
"float"             {return(DATATYPE_FLOAT);}
"long"              {return(DATATYPE_LONG); }
"short"             {return(DATATYPE_SHORT);}
"void"              {return(DATATYPE_VOID); }

"if"                {return(IF);            }
"else"              {return(ELSE);          }
"break"             {return(BREAK);         }

"do"                {return(DO);            }
"while"             {return(WHILE);         }
"for"               {return(FOR);           }
"continue"          {return(CONTINUE);      }
"goto"              {return(GOTO);          }

"signed"            {return(SIGNED);        }
"unsigned"          {return(UNSIGNED);      }

"<"                 {return(CONDITIONAL_<); }
"<="                {return(CONDITIONAL_<=);}
">"                 {return(CONDITIONAL_>); }
">="                {return(CONDITIONAL_>=);}
"=="                {return(CONDITIONAL_==);}

"+"                {return(ARITHMETIC_+);   }
"-"                {return(ARITHMETIC_-);   }
"/"                {return(ARITHMETIC_/);   }
"="                {return(ARITHMETIC_=);   }

"*"                {return(*);              }
"&"                {return(&);              }

.                   {/*Undesired/Undefined*/}
