%code requires{
  #include "ast.hpp"

  #include <cassert>
  #include // TODO: Fuck please make some header files which evaluate this shit!

  extern const Expression *g_root; // A way of getting the AST out

  //! This is to fix problems when generating C++
  // We are declaring the functions provided by Flex, so
  // that Bison generated code can call them.
  int yylex(void);
  void yyerror(const char *);
}

// Represents the value associated with any kind of
// AST node.
%union{
  const Expression *expr;
  double number;
  std::string *string;
}

%token T_TIMES T_DIVIDE T_PLUS T_MINUS T_EXPONENT
%token T_LBRACKET T_RBRACKET
%token T_LOG T_EXP T_SQRT
%token T_NUMBER T_VARIABLE

%token DATATYPE_INT DATATYPE_CHAR DATATYPE_FLOAT DATATYPE_LONG DATATYPE_SHORT DATATYPE_VOID
%token DO WHILE FOR CONTINUE GOTO
%token SIGNED UNSIGNED

%token CONDITIONAL_LT CONDITIONAL_LTET CONDITIONAL_GT CONDITIONAL_GTET CONDITIONAL_EE
%token ARITHMETIC_PLUS ARITHMETIC_DEDUCT ARITHMETIC_DASH ARITHMETIC_E
%token TYPE_AMPERSAND SEMICOLON

%token IF ELSE RETURN BREAK

// Added condition, iterate + evaluate
%type <expr> EVALUATE EXPRESSION DECLARE
%type <number> T_NUMBER
%type <string> T_VARIABLE T_LOG T_EXP T_SQRT FUNCTION_NAME

%start ROOT

%%

ROOT : EVALUATE { g_root = $1; };

// Evaluate expression
EVALUATE : CODE {$$ = $1; }
         ;

//  Code consists of functions and statements
CODE  : STATEMENT {$$ = $1; }
      //| FUNCTION  {$$ = $1; } //  TODO: ONCE Statements is done, build up function

/*
    Statement types:
    1	Labeled Statements
    2	Compound Statements
    3	Expression Statements
    4	Selection Statements
    5	Iteration Statements
    6 Jump Statements

    ref: https://en.wikibooks.org/wiki/C_Programming/Statements
*/
STATEMENT 
        : LABELED_STATEMENT     {$$ = $1;}
        | COMPOUND_STATEMENT    {$$ = $1;}
        | EXPRESSION_STATEMENT  {$$ = $1;}
        | SELECTION_STATEMENT   {$$ = $1;}
        | ITERATION_STATEMENT   {$$ = $1;}
        | JUMP_STATEMENT        {$$ = $1;}
        | DECLARATION_STATEMENT {$$ = $1;}

LABELED_STATEMENT
        :
        |
        |

COMPOUND_STATEMENT
        :
        |
        |

EXPRESSION_STATEMENT
        :
        |
        |

SELECTION_STATEMENT
        :  IF T_LBRACKET EXP T_RBRACKET STATEMENT ELSE STATEMENT  {$$ = new if_statement($3, $5, $7);}
        | SWITCH T_LBRACKET T_EXP T_RBRACKET STATEMENT            {/* Case is a compound statement!*/ 
                                                                    $$ = new switch($3, $5);}

ITERATION_STATEMENT
        :
        |
        |

JUMP_STATEMENT
        :
        |
        |

DECLARATION_STATEMENT
        : DATATYPE_INT T_VARIABLE SEMICOLON                       {$$ = new declare_int($2);}
        | UNSIGNED DATATYPE_INT T_VARIABLE SEMICOLON              {$$ = new}
        | SIGNED DATATYPE_INT T_VARIABLE SEMICOLON                {$$ = new}

        | DATATYPE_CHAR T_VARIABLE SEMICOLON {$$ = new}

        | DATATYPE_FLOAT T_VARIABLE SEMICOLON {$$ = new}
        | UNSIGNED DATATYPE_FLOAT T_VARIABLE SEMICOLON {$$ = new}
        | SIGNED DATATYPE_FLOAT T_VARIABLE SEMICOLON {$$ = new}

        | DATATYPE_LONG T_VARIABLE SEMICOLON {$$ = new}
        | DATATYPE_SHORT T_VARIABLE SEMICOLON {$$ = new}

        | DATATYPE_VOID T_VARIABLE SEMICOLON {$$ = new}
        | CONDITION {$$ = $1; }
        ;

%%

const Expression *g_root; // Definition of variable (to match declaration earlier)

const Expression *parseAST()
{
  g_root=0;
  yyparse();
  return g_root;
}
