%code requires{
  #include "ast.hpp"

  #include <cassert>

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
%type <expr> EXPR TERM UNARY FACTOR CONDITION ITERATE EVALUATE DECLARE
%type <number> T_NUMBER
%type <string> T_VARIABLE T_LOG T_EXP T_SQRT FUNCTION_NAME

%start ROOT

%%

ROOT : EXPR { g_root = $1; };

EXPR  : TERM              { $$ = $1; }
      | EXPR T_PLUS TERM  { $$ = new AddOperator($1 , $3); }    
      | EXPR T_MINUS TERM  { $$ = new SubOperator($1 , $3); }    
      ;

TERM  : UNARY     { $$ = $1; }
      | TERM T_DIVIDE UNARY    { $$ = new DivOperator($1 , $3); }
      | TERM T_TIMES UNARY    { $$ = new MulOperator($1 , $3); } 
      ;

UNARY : FACTOR        { $$ = $1; }
      | T_MINUS UNARY { $$ = new NegOperator( $2 ); }
      | T_PLUS UNARY { $$ = $2; }
      ;

FACTOR : T_NUMBER     { $$ = new Number( $1 ); }
       | T_VARIABLE     { $$ = new Variable( *$1 ); } 
       | T_LBRACKET EXPR T_RBRACKET { $$ = $2; }       
       | FACTOR T_EXPONENT UNARY    { $$ = new ExpOperator($1 , $3); }             
       | T_LOG T_LBRACKET EXPR T_RBRACKET { $$ = new LogFunction( $3 ); }         
       | T_EXP T_LBRACKET EXPR T_RBRACKET { $$ = new ExpFunction( $3 ); }      
       | T_SQRT T_LBRACKET EXPR T_RBRACKET { $$ = new SqrtFunction( $3 ); }
       ;

// Any type of expression that could go in if statements or loops?
EVALUATE : EXPR SEMICOLON {}
         | SEMICOLON {}
         ;

DECLARE : DATATYPE_INT T_VARIABLE SEMICOLON {}
        | UNSIGNED DATATYPE_INT T_VARIABLE SEMICOLON {}
        | SIGNED DATATYPE_INT T_VARIABLE SEMICOLON {}

        | DATATYPE_CHAR T_VARIABLE SEMICOLON {}

        | DATATYPE_FLOAT T_VARIABLE SEMICOLON {}
        | UNSIGNED DATATYPE_FLOAT T_VARIABLE SEMICOLON {}
        | SIGNED DATATYPE_FLOAT T_VARIABLE SEMICOLON {}

        | DATATYPE_LONG T_VARIABLE SEMICOLON {}
        | DATATYPE_SHORT T_VARIABLE SEMICOLON {}

        | DATATYPE_VOID T_VARIABLE SEMICOLON {}
        ;

//JUST STARTING;
CONDITION : IF T_LBRACKET EXPR T_RBRACKET EVALUATE {}
          | IF T_LBRACKET EXPR T_RBRACKET EVALUATE ELSE EVALUATE {}
          ;

// Required??
FUNCTION_NAME : T_LOG  { $$ = new std::string("log"); }
              | T_EXP  { $$ = new std::string("exp"); }  
              | T_SQRT { $$ = new std::string("sqrt"); }
              ;

%%

const Expression *g_root; // Definition of variable (to match declaration earlier)

const Expression *parseAST()
{
  g_root=0;
  yyparse();
  return g_root;
}
