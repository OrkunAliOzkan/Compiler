%code requires{
  #include "ast.hpp"

  #include <cassert>
  #include <iostream>
  #include <iomanip>

  extern Expression *g_root; // A way of getting the AST out

  //! This is to fix problems when generating C++
  // We are declaring the functions provided by Flex, so
  // that Bison generated code can call them.
  int yylex(void);
  void yyerror(const char *);
}

%union{
	Expression *expr;
	int int_num;
	double double_num;
	float float_num;
	std::string *string;
}

%token<int_num> CONSTANT
%token<string> IDENTIFIER

%token STRING_LITERAL SIZEOF
%token PTR_OP INC_OP DEC_OP LEFT_OP RIGHT_OP LE_OP GE_OP EQ_OP NE_OP
%token AND_OP OR_OP    
%token TYPE_NAME

%token TYPEDEF EXTERN STATIC AUTO REGISTER
%token CHAR SHORT INT LONG SIGNED UNSIGNED FLOAT DOUBLE CONST VOLATILE VOID
%token STRUCT UNION ENUM ELLIPSIS

%token CASE DEFAULT IF ELSE SWITCH WHILE DO FOR GOTO CONTINUE BREAK RETURN

%token<string> MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN ADD_ASSIGN SUB_ASSIGN LEFT_ASSIGN RIGHT_ASSIGN AND_ASSIGN XOR_ASSIGN OR_ASSIGN


%type<expr> primary_expression postfix_expression argument_expression_list unary_expression cast_expression multiplicative_expression additive_expression shift_expression 
relational_expression equality_expression and_expression exclusive_or_expression inclusive_or_expression logical_and_expression logical_or_expression conditional_expression
assignment_expression expression constant_expression declaration declaration_specifiers init_declarator_list init_declarator storage_class_specifier type_specifier
struct_or_union_specifier struct_or_union struct_declaration_list struct_declaration specifier_qualifier_list struct_declarator_list struct_declarator enum_specifier
enumerator_list enumerator type_qualifier declarator direct_declarator pointer type_qualifier_list parameter_type_list parameter_list parameter_declaration identifier_list
type_name abstract_declarator direct_abstract_declarator initializer initializer_list statement labeled_statement compound_statement declaration_list statement_list
expression_statement selection_statement iteration_statement jump_statement translation_unit external_declaration function_definition

%type<string> assignment_operator

// Possibly this for lists? 
//%type <exprList> STATEMENT_LIST PARAMETER_LIST TRANSLATION_UNIT DECLARATION_LIST ARGUMENT_EXPRESSION_LIST IDENTIFIER_LIST INIT_DECLARATOR_LIST PARAMETER_TYPE_LIST
//TYPE_QUALIFIER_LIST INITIALIZER_LIST


%start translation_unit
%%

primary_expression
	: IDENTIFIER				{ std::cout<< "primary_expression -> IDENTIFIER " << std::endl; $$ = new Variable(*$1); }
	| CONSTANT					{ std::cout<< "primary_expression -> CONSTANT " << std::endl; $$ = new Integer($1); }
	| STRING_LITERAL			{ std::cout<< "primary_expression -> STRING_LITERAL" <<std::endl; }
	| '(' expression ')'		{ std::cout<< "primary_expression -> ( expression )" <<std::endl; }
	;

postfix_expression
	: primary_expression										{ std::cout<< "postfix_expression -> primary_expression" << std::endl; $$ = $1;}
	| postfix_expression '[' expression ']'						{ std::cout<< "postfix_expression -> postfix_expression '[' expression ']'	" << std::endl; }
	| postfix_expression '(' ')'								{ std::cout<< "postfix_expression -> postfix_expression '(' ')'" << std::endl; }
	| postfix_expression '(' argument_expression_list ')'		{ std::cout<< "postfix_expression -> postfix_expression '(' argument_expression_list ')'" << std::endl; }
	| postfix_expression '.' IDENTIFIER							{ std::cout<< "postfix_expression -> postfix_expression '.' IDENTIFIER" << std::endl; }
	| postfix_expression PTR_OP IDENTIFIER						{ std::cout<< "postfix_expression -> postfix_expression PTR_OP IDENTIFIER" << std::endl; }
	| postfix_expression INC_OP									{ std::cout<< "postfix_expression -> postfix_expression INC_OP" << std::endl; }
	| postfix_expression DEC_OP									{ std::cout<< "postfix_expression -> postfix_expression DEC_OP" << std::endl; }
	;

argument_expression_list
	: assignment_expression										{ std::cout<< "argument_expression_list -> assignment_expression" << std::endl; }
	| argument_expression_list ',' assignment_expression		{ std::cout<< "argument_expression_list -> argument_expression_list ',' assignment_expression" << std::endl; }
	;

unary_expression
	: postfix_expression				{ std::cout<< "unary_expression -> postfix_expression" << std::endl; $$ = $1; }
	| INC_OP unary_expression			{ std::cout<< "unary_expression -> INC_OP unary_expression" << std::endl; }
	| DEC_OP unary_expression			{ std::cout<< "unary_expression -> DEC_OP unary_expression" << std::endl; }
	| unary_operator cast_expression	{ std::cout<< "unary_expression -> unary_operator cast_expression" << std::endl; }
	| SIZEOF unary_expression			{ std::cout<< "unary_expression -> SIZEOF unary_expression" << std::endl; }
	| SIZEOF '(' type_name ')'			{ std::cout<< "unary_expression -> SIZEOF '(' type_name ')'" << std::endl; }
	;

unary_operator
	: '&'			{ std::cout<< "unary_operator -> &" << std::endl; }
	| '*'			{ std::cout<< "unary_operator -> *" << std::endl; }
	| '+'			{ std::cout<< "unary_operator -> +" << std::endl; }
	| '-'			{ std::cout<< "unary_operator -> -" << std::endl; }
	| '~'			{ std::cout<< "unary_operator -> ~" << std::endl; }
	| '!'			{ std::cout<< "unary_operator -> !" << std::endl; }
	;

cast_expression
	: unary_expression						{ std::cout<< "cast_expression -> unary_expression" << std::endl; $$=$1; }
	| '(' type_name ')' cast_expression		{ std::cout<< "cast_expression -> '(' type_name ')' cast_expression" << std::endl; }
	;

multiplicative_expression
	: cast_expression										{ std::cout<<"multiplicative_expression -> cast_expression"<<std::endl; $$ = $1; }
	| multiplicative_expression '*' cast_expression			{ std::cout<<"multiplicative_expression -> multiplicative_expression '*' cast_expression"<<std::endl; $$ = new MulOperator($1, $3); }
	| multiplicative_expression '/' cast_expression			{ std::cout<<"multiplicative_expression -> multiplicative_expression '/' cast_expression"<<std::endl; $$ = new DivOperator($1, $3); }
	| multiplicative_expression '%' cast_expression			{ std::cout<<"multiplicative_expression -> multiplicative_expression '%' cast_expression"<<std::endl; $$ = new ModOperator($1, $3); }
	;

additive_expression
	: multiplicative_expression								{ std::cout<<"additive_expression -> multiplicative_expression"<<std::endl; $$ = $1; }
	| additive_expression '+' multiplicative_expression 	{ std::cout<<"additive_expression -> additive_expression '+' multiplicative_expression"<<std::endl; $$ = new AddOperator($1, $3); }
	| additive_expression '-' multiplicative_expression 	{ std::cout<<"additive_expression -> additive_expression '-' multiplicative_expression"<<std::endl; $$ = new SubOperator($1, $3); }
	;

shift_expression
	: additive_expression									{ std::cout<<"shift_expression -> additive_expression"<<std::endl; $$ = $1; }
	| shift_expression LEFT_OP additive_expression			{ std::cout<<"shift_expression -> shift_expression LEFT_OP additive_expression"<<std::endl; $$ = new AShiftLeftOperator($1, $3); }
	| shift_expression RIGHT_OP additive_expression			{ std::cout<<"shift_expression -> shift_expression RIGHT_OP additive_expression"<<std::endl; $$ = new AShiftRightOperator($1, $3); }
	;

relational_expression
	: shift_expression										{ std::cout<<"relational_expression -> shift_expression"<<std::endl; $$ = $1; }
	| relational_expression '<' shift_expression			{ std::cout<<"relational_expression -> relational_expression '<' shift_expression"<<std::endl; $$ = new LTOperator($1, $3); }
	| relational_expression '>' shift_expression			{ std::cout<<"relational_expression -> relational_expression '>' shift_expression"<<std::endl; $$ = new GTOperator($1, $3); }
	| relational_expression LE_OP shift_expression			{ std::cout<<"relational_expression -> relational_expression LE_OP shift_expression"<<std::endl; $$ = new LEOperator($1, $3); }
	| relational_expression GE_OP shift_expression			{ std::cout<<"relational_expression -> relational_expression GE_OP shift_expression"<<std::endl; $$ = new GEOperator($1, $3); }
	;

equality_expression
	: relational_expression									{ std::cout<<"equality_expression -> relational_expression"<<std::endl; $$ = $1; }
	| equality_expression EQ_OP relational_expression		{ std::cout<<"equality_expression -> equality_expression EQ_OP relational_expression"<<std::endl; $$ = new EqOperator($1, $3); }
	| equality_expression NE_OP relational_expression		{ std::cout<<"equality_expression -> equality_expression NE_OP relational_expression"<<std::endl; $$ = new NeqOperator($1, $3); }
	;

and_expression
	: equality_expression									{ std::cout<<"and_expression -> equality_expression"<<std::endl; $$ = $1; }
	| and_expression '&' equality_expression				{ std::cout<<"and_expression -> and_expression '&' equality_expression"<<std::endl; $$ = new bAndOperator($1, $3); }
	;

exclusive_or_expression
	: and_expression										{ std::cout<<"exclusive_or_expression -> and_expression"<<std::endl; $$ = $1; }
	| exclusive_or_expression '^' and_expression			{ std::cout<<"exclusive_or_expression -> exclusive_or_expression '^' and_expression"<<std::endl; $$ = new xorOperator($1, $3); }
	;

inclusive_or_expression
	: exclusive_or_expression								{ std::cout<<"inclusive_or_expression -> exclusive_or_expression"<<std::endl; $$ = $1; }
	| inclusive_or_expression '|' exclusive_or_expression	{ std::cout<<"inclusive_or_expression -> inclusive_or_expression '|' exclusive_or_expression"<<std::endl; $$ = new bOrOperator($1, $3); }
	;

logical_and_expression
	: inclusive_or_expression								{ std::cout<<"logical_and_expression -> inclusive_or_expression"<<std::endl; $$ = $1; }
	| logical_and_expression AND_OP inclusive_or_expression	{ std::cout<<"logical_and_expression -> logical_and_expression AND_OP inclusive_or_expression"<<std::endl; $$ = new AndOperator($1, $3); }
	;

logical_or_expression
	: logical_and_expression								{ std::cout<<"logical_or_expression -> logical_and_expression"<<std::endl; $$ = $1; }
	| logical_or_expression OR_OP logical_and_expression	{ std::cout<<"logical_or_expression -> logical_or_expression OR_OP logical_and_expression"<<std::endl; $$ = new OrOperator($1, $3); }
	;

conditional_expression
	: logical_or_expression												{ std::cout<<"conditional_expression -> logical_or_expression"<<std::endl; $$ = $1; }
	| logical_or_expression '?' expression ':' conditional_expression	{ std::cout<<"conditional_expression -> logical_or_expression '?' expression ':' conditional_expression"<<std::endl; }
	;

assignment_expression
	: conditional_expression										{ std::cout << "assignment_expression -> conditional_expression" << std::endl; $$ = $1; }
	| unary_expression assignment_operator assignment_expression	{ std::cout << "assignment_expression -> unary_expression assignment_operator assignment_expression" << std::endl; }
	;

assignment_operator
	: '='					{ std::cout << "assignment_operator: =" << std::endl; }
	| MUL_ASSIGN			{ std::cout << "assignment_operator: *=" << std::endl; }
	| DIV_ASSIGN			{ std::cout << "assignment_operator: /=" << std::endl; }
	| MOD_ASSIGN			{ std::cout << "assignment_operator: %=" << std::endl; }
	| ADD_ASSIGN			{ std::cout << "assignment_operator: +=" << std::endl; }
	| SUB_ASSIGN			{ std::cout << "assignment_operator: -=" << std::endl; }
	| LEFT_ASSIGN			{ std::cout << "assignment_operator: <<=" << std::endl; }
	| RIGHT_ASSIGN			{ std::cout << "assignment_operator: >>=" << std::endl; }
	| AND_ASSIGN			{ std::cout << "assignment_operator: &=" << std::endl; }
	| XOR_ASSIGN			{ std::cout << "assignment_operator: ^=" << std::endl; }
	| OR_ASSIGN				{ std::cout << "assignment_operator: |=" << std::endl; }
	;

expression
	: assignment_expression						{ std::cout<<"expression -> assignment_expression" << std::endl; }
	| expression ',' assignment_expression		{ std::cout<<"expression -> expression ',' assignment_expression" << std::endl; }
	;

constant_expression
	: conditional_expression					{ std::cout<<"constant_expression -> conditional_expression" << std::endl; }
	;

declaration
	: declaration_specifiers ';'							{ std::cout<<"declaration -> declaration_specifiers ;" << std::endl; }
	| declaration_specifiers init_declarator_list ';'		{ std::cout<<"declaration -> declaration_specifiers init_declarator_list ;" << std::endl; }
	;

declaration_specifiers
	: storage_class_specifier								{ std::cout<<"declaration_specifiers -> storage_class_specifier"<<std::endl; }
	| storage_class_specifier declaration_specifiers		{ std::cout<<"declaration_specifiers -> storage_class_specifier declaration_specifiers"<<std::endl; }
	| type_specifier										{ std::cout<<"declaration_specifiers -> type_specifier"<<std::endl; }
	| type_specifier declaration_specifiers					{ std::cout<<"declaration_specifiers -> type_specifier declaration_specifiers"<<std::endl; }
	| type_qualifier										{ std::cout<<"declaration_specifiers -> type_qualifier"<<std::endl; }
	| type_qualifier declaration_specifiers					{ std::cout<<"declaration_specifiers -> type_qualifier declaration_specifiers"<<std::endl; }
	;

init_declarator_list
	: init_declarator								{ std::cout<<"init_declarator_list -> init_declarator"<<std::endl; }
	| init_declarator_list ',' init_declarator		{ std::cout<<"init_declarator_list -> init_declarator_list ',' init_declarator"<<std::endl; }
	;

init_declarator
	: declarator									{ std::cout<<"init_declarator -> declarator"<<std::endl; }
	| declarator '=' initializer					{ std::cout<<"init_declarator -> declarator '=' initializer"<<std::endl; $$ = new AssignOperator($1, $3);}
	;

storage_class_specifier
	: TYPEDEF				{ std::cout<<"storage_class_specifier -> TYPEDEF"<<std::endl; }
	| EXTERN				{ std::cout<<"storage_class_specifier -> EXTERN"<<std::endl; }
	| STATIC				{ std::cout<<"storage_class_specifier -> STATIC"<<std::endl; }
	| AUTO					{ std::cout<<"storage_class_specifier -> AUTO"<<std::endl; }
	| REGISTER				{ std::cout<<"storage_class_specifier -> REGISTER"<<std::endl; }
	;

type_specifier
	: VOID								{ std::cout<<"type_specifier -> VOID"<<std::endl; }
	| CHAR								{ std::cout<<"type_specifier -> CHAR"<<std::endl; }
	| SHORT								{ std::cout<<"type_specifier -> SHORT"<<std::endl; }
	| INT								{ std::cout<<"type_specifier -> INT"<<std::endl; }
	| LONG								{ std::cout<<"type_specifier -> LONG"<<std::endl; }
	| FLOAT								{ std::cout<<"type_specifier -> FLOAT"<<std::endl; }
	| DOUBLE							{ std::cout<<"type_specifier -> DOUBLE"<<std::endl; }
	| SIGNED							{ std::cout<<"type_specifier -> SIGNED"<<std::endl; }
	| UNSIGNED							{ std::cout<<"type_specifier -> UNSIGNED"<<std::endl; }
	| struct_or_union_specifier			{ std::cout<<"type_specifier -> struct_or_union_specifier"<<std::endl; }
	| enum_specifier					{ std::cout<<"type_specifier -> enum_specifier"<<std::endl; }
	| TYPE_NAME							{ std::cout<<"type_specifier -> TYPE_NAME"<<std::endl; }
	;

struct_or_union_specifier
	: struct_or_union IDENTIFIER '{' struct_declaration_list '}'		{ std::cout<<"struct_or_union_specifier -> struct_or_union IDENTIFIER '{' struct_declaration_list '}'"<<std::endl; }
	| struct_or_union '{' struct_declaration_list '}'					{ std::cout<<"struct_or_union_specifier -> struct_or_union '{' struct_declaration_list '}'"<<std::endl; }
	| struct_or_union IDENTIFIER										{ std::cout<<"struct_or_union_specifier -> struct_or_union IDENTIFIER"<<std::endl; }
	;

struct_or_union
	: STRUCT			{ std::cout<<"struct_or_union -> STRUCT"<<std::endl; }
	| UNION				{ std::cout<<"struct_or_union -> UNION"<<std::endl; }
	;

struct_declaration_list
	: struct_declaration								{ std::cout<<"struct_declaration_list -> struct_declaration"<<std::endl; }
	| struct_declaration_list struct_declaration		{ std::cout<<"struct_declaration_list -> struct_declaration_list struct_declaration"<<std::endl; }
	;

struct_declaration
	: specifier_qualifier_list struct_declarator_list ';'	{ std::cout<<"struct_declaration -> specifier_qualifier_list struct_declarator_list"<<std::endl; }
	;

specifier_qualifier_list
	: type_specifier specifier_qualifier_list		{ std::cout<<"specifier_qualifier_list -> type_specifier specifier_qualifier_list"<<std::endl; }
	| type_specifier								{ std::cout<<"specifier_qualifier_list -> type_specifier"<<std::endl; }
	| type_qualifier specifier_qualifier_list		{ std::cout<<"specifier_qualifier_list -> type_qualifier specifier_qualifier_list"<<std::endl; }
	| type_qualifier								{ std::cout<<"specifier_qualifier_list -> type_qualifier"<<std::endl; }
	;

struct_declarator_list
	: struct_declarator									{ std::cout<<"struct_declarator_list -> struct_declarator"<<std::endl; }
	| struct_declarator_list ',' struct_declarator		{ std::cout<<"struct_declarator_list -> struct_declarator_list ',' struct_declarator"<<std::endl; }
	;

struct_declarator
	: declarator								{ std::cout<<"struct_declarator -> declarator"<<std::endl; }
	| ':' constant_expression					{ std::cout<<"struct_declarator -> ':' constant_expression" <<std::endl; }
	| declarator ':' constant_expression		{ std::cout<<"struct_declarator -> declarator ':' constant_expression"<<std::endl; }
	;

enum_specifier
	: ENUM '{' enumerator_list '}'				{ std::cout << "enum_specifier -> ENUM '{' enumerator_list '}'" << std::endl; }
	| ENUM IDENTIFIER '{' enumerator_list '}'	{ std::cout << "enum_specifier -> ENUM IDENTIFIER '{' enumerator_list '}'" << std::endl; }
	| ENUM IDENTIFIER							{ std::cout << "enum_specifier -> ENUM IDENTIFIER" << std::endl; }
	;

enumerator_list
	: enumerator								{ std::cout << "enumerator_list -> enumerator" << std::endl; }
	| enumerator_list ',' enumerator			{ std::cout << "enumerator_list -> enumerator_list ',' enumerator" << std::endl; }
	;

enumerator
	: IDENTIFIER								{ std::cout << "enumerator -> IDENTIFIER" << std::endl; }
	| IDENTIFIER '=' constant_expression		{ std::cout << "enumerator -> IDENTIFIER '=' constant_expression" << std::endl; }
	;

type_qualifier
	: CONST			{ std::cout << "type_qualifier -> CONST" << std::endl; }						
	| VOLATILE		{ std::cout << "type_qualifier -> VOLATILE" << std::endl; }
	;

declarator
	: pointer direct_declarator			{ std::cout << "declarator -> pointer direct_declarator" << std::endl; $$ = new Declarator($1, $2); }
	| direct_declarator					{ std::cout << "declarator -> direct_declarator" << std::endl; $$ = new Declarator(NULL, $1); }
	;

direct_declarator
	: IDENTIFIER												{ std::cout << "direct_declarator -> IDENTIFIER" << std::endl; $$ = new Variable(*$1); }
	| '(' declarator ')'										{ std::cout << "direct_declarator -> '(' declarator ')'" << std::endl; $$ = $2; }
	| direct_declarator '[' constant_expression ']'				{ std::cout << "direct_declarator -> direct_declarator '[' constant_expression ']'" << std::endl; }
	| direct_declarator '[' ']'									{ std::cout << "direct_declarator -> direct_declarator '[' ']'" << std::endl; }
	| direct_declarator '(' parameter_type_list ')'				{ std::cout << "direct_declarator -> direct_declarator '(' parameter_type_list ')'" << std::endl; }
	| direct_declarator '(' identifier_list ')'					{ std::cout << "direct_declarator -> direct_declarator '(' identifier_list ')'" << std::endl; }
	| direct_declarator '(' ')'									{ std::cout << "direct_declarator -> direct_declarator '(' ')'" << std::endl; }
	;

pointer
	: '*'									{ std::cout << "pointer -> '*'" << std::endl; }
	| '*' type_qualifier_list				{ std::cout << "pointer -> '*' type_qualifier_list" << std::endl; }
	| '*' pointer							{ std::cout << "pointer -> '*' pointer" << std::endl; }
	| '*' type_qualifier_list pointer		{ std::cout << "pointer -> '*' type_qualifier_list pointer" << std::endl; }
	;

type_qualifier_list
	: type_qualifier							
	| type_qualifier_list type_qualifier
	;


parameter_type_list
	: parameter_list
	| parameter_list ',' ELLIPSIS
	;

parameter_list
	: parameter_declaration
	| parameter_list ',' parameter_declaration
	;

parameter_declaration
	: declaration_specifiers declarator
	| declaration_specifiers abstract_declarator
	| declaration_specifiers
	;

identifier_list
	: IDENTIFIER
	| identifier_list ',' IDENTIFIER
	;

type_name
	: specifier_qualifier_list									{ std::cout << "type_name -> specifier_qualifier_list" << std::endl; }
	| specifier_qualifier_list abstract_declarator				{ std::cout << "type_name -> specifier_qualifier_list abstract_declarator" << std::endl; }
	;

abstract_declarator
	: pointer													
	| direct_abstract_declarator
	| pointer direct_abstract_declarator
	;

direct_abstract_declarator
	: '(' abstract_declarator ')'
	| '[' ']'
	| '[' constant_expression ']'
	| direct_abstract_declarator '[' ']'
	| direct_abstract_declarator '[' constant_expression ']'
	| '(' ')'
	| '(' parameter_type_list ')'
	| direct_abstract_declarator '(' ')'
	| direct_abstract_declarator '(' parameter_type_list ')'
	;

initializer
	: assignment_expression					{ std::cout << "initializer -> assignment_expression" << std::endl; }		
	| '{' initializer_list '}'				{ std::cout << "initializer -> '{' initializer_list '}'" << std::endl; }
	| '{' initializer_list ',' '}'			{ std::cout << "initializer -> '{' initializer_list ',' '}'" << std::endl; }
	;

initializer_list
	: initializer							{ std::cout << "initializer_list -> initializer" << std::endl; }
	| initializer_list ',' initializer		{ std::cout << "initializer_list -> initializer_list ',' initializer" << std::endl; }
	;

statement
	: labeled_statement						{ std::cout << "statement -> labeled_statement" << std::endl; }
	| compound_statement					{ std::cout << "statement -> compound_statement" << std::endl; }
	| expression_statement					{ std::cout << "statement -> expression_statement" << std::endl; }
	| selection_statement					{ std::cout << "statement -> selection_statement" << std::endl; }
	| iteration_statement					{ std::cout << "statement -> iteration_statement" << std::endl; }
	| jump_statement						{ std::cout << "statement -> jump_statement" << std::endl; }
	;

labeled_statement
	: IDENTIFIER ':' statement
	| CASE constant_expression ':' statement
	| DEFAULT ':' statement
	;

compound_statement
	: '{' '}'
	| '{' statement_list '}'
	| '{' declaration_list '}'
	| '{' declaration_list statement_list '}'
	;

declaration_list
	: declaration
	| declaration_list declaration
	;

statement_list
	: statement
	| statement_list statement
	;

expression_statement
	: ';'							{ std::cout << "expression_statement -> ';'" << std::endl; }
	| expression ';'				{ std::cout << "expression_statement -> expression ';'" << std::endl; }
	;

selection_statement
	: IF '(' expression ')' statement
	| IF '(' expression ')' statement ELSE statement
	| SWITCH '(' expression ')' statement
	;

iteration_statement
	: WHILE '(' expression ')' statement
	| DO statement WHILE '(' expression ')' ';'
	| FOR '(' expression_statement expression_statement ')' statement
	| FOR '(' expression_statement expression_statement expression ')' statement
	;

jump_statement
	: GOTO IDENTIFIER ';'
	| CONTINUE ';'
	| BREAK ';'
	| RETURN ';'
	| RETURN expression ';'			{ std::cout<<"jump_statement -> RETURN expression ;"<<std::endl; }
	;

translation_unit
	: external_declaration						{ std::cout<<"translation_unit -> external_declaration"<<std::endl; /* Put the function in here?*/}
	| translation_unit external_declaration		{ std::cout<<"translation_unit -> translation_unit external_declaration"<<std::endl; /* Put the function in here?*/}
	;

external_declaration
	: function_definition			{ std::cout<<"external_declaration -> function_definition"<<std::endl; }
	| declaration					{ std::cout<<"external_declaration -> declaration"<<std::endl; }
	;

function_definition
	: declaration_specifiers declarator declaration_list compound_statement			{ std::cout<<"function_definition -> declaration_specifiers declarator declaration_list compound_statement"<<std::endl; }
	| declaration_specifiers declarator compound_statement							{ std::cout<<"function_definition -> declaration_specifiers declarator compound_statement"<<std::endl; }
	| declarator declaration_list compound_statement								{ std::cout<<"function_definition -> declarator declaration_list compound_statement"<<std::endl; }
	| declarator compound_statement													{ std::cout<<"function_definition -> declarator compound_statement	"<<std::endl; }
	;

%%

#include "lex.yy.c"

void yyerror (char const *s) {
    fprintf(stderr, "%s\n", s);
    exit(1);
}

//int main() {
//    yyparse(); // parse user input
//}

Expression *g_root; // Definition of variable (to match declaration earlier)

Expression *parseAST()
{
  g_root=0;
  yyparse();
  return g_root;
}

int main()
{
// Parse the AST
    Expression *ast=parseAST();
//Compile AST? Need function in the class

	std::string current_func;
	std::map<std::string, std::string> g_Var;
	std::map<std::string, bool> reg_available;
	std::string type_check;
	int initial_memory = 0;
	
	std::string MIPS;
	//MIPS += ast->Compile( current_func, initial_memory, g_Var, reg_available, type_check );
	//std::cout<<"MIPS: " << ast-> <<std::endl;
    return 0;
}