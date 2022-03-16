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
 
%token IDENTIFIER CONSTANT
%type<string> IDENTIFIER CONSTANT

%token STRING_LITERAL SIZEOF
%token PTR_OP INC_OP DEC_OP LEFT_OP RIGHT_OP LE_OP GE_OP EQ_OP NE_OP
%token AND_OP OR_OP    

%token TYPEDEF EXTERN STATIC AUTO REGISTER
%type<string> TYPEDEF EXTERN STATIC AUTO REGISTER

%token<string> CHAR SHORT INT LONG SIGNED UNSIGNED FLOAT DOUBLE CONST VOLATILE VOID
%token<string> STRUCT UNION ENUM ELLIPSIS

%token<string> CASE DEFAULT IF ELSE SWITCH WHILE DO FOR GOTO CONTINUE BREAK RETURN

%token EQ_ASSIGN MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN ADD_ASSIGN SUB_ASSIGN LEFT_ASSIGN RIGHT_ASSIGN AND_ASSIGN XOR_ASSIGN OR_ASSIGN
%type<string> EQ_ASSIGN MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN ADD_ASSIGN SUB_ASSIGN LEFT_ASSIGN RIGHT_ASSIGN AND_ASSIGN XOR_ASSIGN OR_ASSIGN

%type<expr> primary_expression postfix_expression argument_expression_list unary_expression cast_expression multiplicative_expression additive_expression shift_expression 
relational_expression equality_expression and_expression exclusive_or_expression inclusive_or_expression logical_and_expression logical_or_expression conditional_expression
assignment_expression expression constant_expression declaration declaration_specifiers init_declarator_list init_declarator storage_class_specifier type_specifier
struct_or_union_specifier struct_or_union struct_declaration_list struct_declaration specifier_qualifier_list struct_declarator_list struct_declarator enum_specifier
enumerator_list enumerator type_qualifier declarator direct_declarator pointer type_qualifier_list parameter_type_list parameter_list parameter_declaration identifier_list
type_name abstract_declarator direct_abstract_declarator initializer initializer_list statement labeled_statement compound_statement declaration_list statement_list
expression_statement selection_statement iteration_statement jump_statement translation_unit external_declaration function_definition assignment_operator


// Possibly this for lists? 
//%type <exprList> STATEMENT_LIST PARAMETER_LIST TRANSLATION_UNIT DECLARATION_LIST ARGUMENT_EXPRESSION_LIST IDENTIFIER_LIST INIT_DECLARATOR_LIST PARAMETER_TYPE_LIST
//TYPE_QUALIFIER_LIST INITIALIZER_LIST


%start HeadNODE
%%

HeadNODE : translation_unit { g_root = new HeadNode($1); }

	//	TODO:	These haven't been done yet!
primary_expression
	: IDENTIFIER				{ std::cout<< "primary_expression -> IDENTIFIER " << std::endl; $$ = new Variable(*$1); 	}
	| CONSTANT					{ std::cout<< "primary_expression -> CONSTANT " << std::endl; $$ = new Integer(*$1); 		}
	| STRING_LITERAL			{ std::cout<< "primary_expression -> STRING_LITERAL" <<std::endl; /*$$ = new StringLiteral();*/	}
	| '(' expression ')'		{ std::cout<< "primary_expression -> ( expression )" <<std::endl; /*$$ = new Expression;*/}
	;
	//	TODO:	These haven't been done yet!
postfix_expression
	: primary_expression										{ std::cout<< "postfix_expression -> primary_expression" << std::endl; $$ = $1; }
	| postfix_expression '[' expression ']'						{ std::cout<< "postfix_expression -> postfix_expression '[' expression ']'	" << std::endl; }
	| postfix_expression '(' ')'								{ std::cout<< "postfix_expression -> postfix_expression '(' ')'" << std::endl; }
	| postfix_expression '(' argument_expression_list ')'		{ std::cout<< "postfix_expression -> postfix_expression '(' argument_expression_list ')'" << std::endl; }
	| postfix_expression '.' IDENTIFIER							{ std::cout<< "postfix_expression -> postfix_expression '.' IDENTIFIER" << std::endl; }
	| postfix_expression PTR_OP IDENTIFIER						{ std::cout<< "postfix_expression -> postfix_expression PTR_OP IDENTIFIER" << std::endl; }
	| postfix_expression INC_OP									{ std::cout<< "postfix_expression -> postfix_expression INC_OP" << std::endl; }
	| postfix_expression DEC_OP									{ std::cout<< "postfix_expression -> postfix_expression DEC_OP" << std::endl; }
	;
	//	TODO:	These haven't been done yet!
argument_expression_list
	: assignment_expression										{ std::cout<< "argument_expression_list -> assignment_expression" << std::endl; $$ = $1; }
	| argument_expression_list ',' assignment_expression		{ std::cout<< "argument_expression_list -> argument_expression_list ',' assignment_expression" << std::endl; }
	;
	//	TODO:	These haven't been done yet!
unary_expression
	: postfix_expression				{ std::cout<< "unary_expression -> postfix_expression" << std::endl; $$ = $1; }
	| INC_OP unary_expression			{ std::cout<< "unary_expression -> INC_OP unary_expression" << std::endl; }
	| DEC_OP unary_expression			{ std::cout<< "unary_expression -> DEC_OP unary_expression" << std::endl; }
	| unary_operator cast_expression	{ std::cout<< "unary_expression -> unary_operator cast_expression" << std::endl; }
	| SIZEOF unary_expression			{ std::cout<< "unary_expression -> SIZEOF unary_expression" << std::endl; }
	| SIZEOF '(' type_name ')'			{ std::cout<< "unary_expression -> SIZEOF '(' type_name ')'" << std::endl; }
	;
	//	TODO:	These haven't been done yet!
unary_operator
	: '&'			{ std::cout<< "unary_operator -> &" << std::endl; }
	| '*'			{ std::cout<< "unary_operator -> *" << std::endl; }
	| '+'			{ std::cout<< "unary_operator -> +" << std::endl; }
	| '-'			{ std::cout<< "unary_operator -> -" << std::endl; }
	| '~'			{ std::cout<< "unary_operator -> ~" << std::endl; }
	| '!'			{ std::cout<< "unary_operator -> !" << std::endl; }
	;
	//	TODO:	These haven't been done yet!
cast_expression
	: unary_expression						{ std::cout<< "cast_expression -> unary_expression" << std::endl; $$ = $1; }
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
	| additive_expression '-' multiplicative_expression 	{ std::cout<<"additive_expression -> additive_expression '-' multiplicative_expression"<<std::endl; $$ = new SubOperator($1, $3);}
	;

shift_expression
	: additive_expression									{ std::cout<<"shift_expression -> additive_expression"<<std::endl; $$ = $1; }
	| shift_expression LEFT_OP additive_expression			{ std::cout<<"shift_expression -> shift_expression LEFT_OP additive_expression"<<std::endl; $$ = new LShiftLeftOperator($1, $3);	}
	| shift_expression RIGHT_OP additive_expression			{ std::cout<<"shift_expression -> shift_expression RIGHT_OP additive_expression"<<std::endl; $$ = new LShiftRightOperator($1, $3);	}
	;
	
relational_expression
	: shift_expression										{ std::cout<<"relational_expression -> shift_expression"<<std::endl; $$ = $1; }
	| relational_expression '<' shift_expression			{ std::cout<<"relational_expression -> relational_expression '<' shift_expression"<<std::endl; $$ = new LTOperator($1, $3);}
	| relational_expression '>' shift_expression			{ std::cout<<"relational_expression -> relational_expression '>' shift_expression"<<std::endl; $$ = new GTOperator($1, $3);}
	| relational_expression LE_OP shift_expression			{ std::cout<<"relational_expression -> relational_expression LE_OP shift_expression"<<std::endl; $$ = new LEOperator($1, $3); }
	| relational_expression GE_OP shift_expression			{ std::cout<<"relational_expression -> relational_expression GE_OP shift_expression"<<std::endl; $$ = new GEOperator($1, $3); }
	;

equality_expression
	: relational_expression									{ std::cout<<"equality_expression -> relational_expression"<<std::endl; $$ = $1; }
	| equality_expression EQ_OP relational_expression		{ std::cout<<"equality_expression -> equality_expression EQ_OP relational_expression"<<std::endl; $$ = new EqOperator($1, $3);}
	| equality_expression NE_OP relational_expression		{ std::cout<<"equality_expression -> equality_expression NE_OP relational_expression"<<std::endl; $$ = new NeqOperator($1, $3);}
	;

and_expression
	: equality_expression									{ std::cout<<"and_expression -> equality_expression"<<std::endl;  $$ = $1; }
	| and_expression '&' equality_expression				{ std::cout<<"and_expression -> and_expression '&' equality_expression"<<std::endl; $$ = new bAndOperator($1, $3); }
	;

exclusive_or_expression
	: and_expression										{ std::cout<<"exclusive_or_expression -> and_expression"<<std::endl;  $$ = $1; }
	| exclusive_or_expression '^' and_expression			{ std::cout<<"exclusive_or_expression -> exclusive_or_expression '^' and_expression"<<std::endl; $$ = new xorOperator($1, $3);}
	;

inclusive_or_expression
	: exclusive_or_expression								{ std::cout<<"inclusive_or_expression -> exclusive_or_expression"<<std::endl;  $$ = $1; }
	| inclusive_or_expression '|' exclusive_or_expression	{ std::cout<<"inclusive_or_expression -> inclusive_or_expression '|' exclusive_or_expression"<<std::endl; $$ = new bOrOperator($1, $3);	}
	;

logical_and_expression
	: inclusive_or_expression								{ std::cout<<"logical_and_expression -> inclusive_or_expression"<<std::endl;  $$ = $1; }
	| logical_and_expression AND_OP inclusive_or_expression	{ std::cout<<"logical_and_expression -> logical_and_expression AND_OP inclusive_or_expression"<<std::endl; $$ = new AndOperator($1, $3);}
	;

logical_or_expression
	: logical_and_expression								{ std::cout<<"logical_or_expression -> logical_and_expression"<<std::endl;  $$ = $1; }
	| logical_or_expression OR_OP logical_and_expression	{ std::cout<<"logical_or_expression -> logical_or_expression OR_OP logical_and_expression"<<std::endl; $$ = new OrOperator($1, $3);}
	;

conditional_expression
	: logical_or_expression												{ std::cout<<"conditional_expression -> logical_or_expression"<<std::endl;  $$ = $1; }
	| logical_or_expression '?' expression ':' conditional_expression	{ std::cout<<"conditional_expression -> logical_or_expression '?' expression ':' conditional_expression"<<std::endl; }
	;

assignment_expression
	: conditional_expression										{ std::cout << "assignment_expression -> conditional_expression" << std::endl;  $$ = $1; }
	| unary_expression assignment_operator assignment_expression	{ std::cout << "assignment_expression -> unary_expression assignment_operator assignment_expression" << std::endl; }
	;

assignment_operator
	: EQ_ASSIGN				{ std::cout << "assignment_operator: =" << std::endl;  $$ = new AssignmentOperator(*$1);}
	| MUL_ASSIGN			{ std::cout << "assignment_operator: *=" << std::endl; $$ = new AssignmentOperator(*$1);}
	| DIV_ASSIGN			{ std::cout << "assignment_operator: /=" << std::endl; $$ = new AssignmentOperator(*$1);}
	| MOD_ASSIGN			{ std::cout << "assignment_operator: %=" << std::endl; $$ = new AssignmentOperator(*$1);}
	| ADD_ASSIGN			{ std::cout << "assignment_operator: +=" << std::endl; $$ = new AssignmentOperator(*$1);}
	| SUB_ASSIGN			{ std::cout << "assignment_operator: -=" << std::endl; $$ = new AssignmentOperator(*$1);}
	| LEFT_ASSIGN			{ std::cout << "assignment_operator: <<=" << std::endl;$$ = new AssignmentOperator(*$1);}
	| RIGHT_ASSIGN			{ std::cout << "assignment_operator: >>=" << std::endl;$$ = new AssignmentOperator(*$1);}
	| AND_ASSIGN			{ std::cout << "assignment_operator: &=" << std::endl; $$ = new AssignmentOperator(*$1);}
	| XOR_ASSIGN			{ std::cout << "assignment_operator: ^=" << std::endl; $$ = new AssignmentOperator(*$1);}
	| OR_ASSIGN				{ std::cout << "assignment_operator: |=" << std::endl; $$ = new AssignmentOperator(*$1);}
	;

expression
	: assignment_expression						{ std::cout<<"expression -> assignment_expression" << std::endl; $$ = $1;}
	| expression ',' assignment_expression		{ std::cout<<"expression -> expression ',' assignment_expression" << std::endl; $$ = new a_expr($1, $3); }
	;

constant_expression
	: conditional_expression					{ std::cout<<"constant_expression -> conditional_expression" << std::endl; $$ = $1;	}
	;

declaration
	: declaration_specifiers ';'							{ std::cout<<"declaration -> declaration_specifiers ;" << std::endl; $$ = $1; }
	| declaration_specifiers init_declarator_list ';'		{ std::cout<<"declaration -> declaration_specifiers init_declarator_list ;" << std::endl; $$ = new Declaration($1, $2); }
	;

declaration_specifiers
	: storage_class_specifier								{ std::cout<<"declaration_specifiers -> storage_class_specifier"<<std::endl; 							$$ = new Declaration_Spec("storage", $1); }
	| storage_class_specifier declaration_specifiers		{ std::cout<<"declaration_specifiers -> storage_class_specifier declaration_specifiers"<<std::endl;		$$ = new Declaration_Spec("storage", $1, $2); }
	| type_specifier										{ std::cout<<"declaration_specifiers -> type_specifier"<<std::endl; 									$$ = new Declaration_Spec("specifier", $1); }
	| type_specifier declaration_specifiers					{ std::cout<<"declaration_specifiers -> type_specifier declaration_specifiers"<<std::endl;				$$ = new Declaration_Spec("specifier", $1, $2); }
	| type_qualifier										{ std::cout<<"declaration_specifiers -> type_qualifier"<<std::endl;										$$ = new Declaration_Spec("qualifier", $1); }
	| type_qualifier declaration_specifiers					{ std::cout<<"declaration_specifiers -> type_qualifier declaration_specifiers"<<std::endl; 				$$ = new Declaration_Spec("qualifier", $1, $2); }
	;

init_declarator_list
	: init_declarator								{ $$ = $1; std::cout<<"init_declarator_list -> init_declarator"<<std::endl;  }
	| init_declarator_list ',' init_declarator		{  $$ = new Init_Declarator_List($1, $3); std::cout<<"init_declarator_list -> init_declarator_list ',' init_declarator"<<std::endl; }
	;

init_declarator
	: declarator									{ $$ = new Init_Declarator($1); 	std::cout<<"init_declarator -> declarator"<<std::endl;  /*	$$ = new Init_Declarator($1, NULL); */}
	| declarator EQ_ASSIGN initializer				{ $$ = new Init_Declarator($1, $3); std::cout<<"init_declarator -> declarator '=' initializer"<<std::endl; }
	;

storage_class_specifier
	: EXTERN				{ std::cout<<"storage_class_specifier -> EXTERN"<<std::endl;   $$ = new StorageClassSpecifier(*$1);	}
	| TYPEDEF				{ std::cout<<"storage_class_specifier -> TYPEDEF"<<std::endl;  $$ = new StorageClassSpecifier(*$1);	}
	| STATIC				{ std::cout<<"storage_class_specifier -> STATIC"<<std::endl;   $$ = new StorageClassSpecifier(*$1);	}
	| AUTO					{ std::cout<<"storage_class_specifier -> AUTO"<<std::endl;     $$ = new StorageClassSpecifier(*$1);	}
	| REGISTER				{ std::cout<<"storage_class_specifier -> REGISTER"<<std::endl; $$ = new StorageClassSpecifier(*$1);	}
	;

type_specifier
	: VOID								{ std::cout<<"type_specifier -> VOID"<<std::endl; 								$$  = new TypeSpecifier("void");	}
	| CHAR								{ std::cout<<"type_specifier -> CHAR"<<std::endl; 								$$  = new TypeSpecifier("char");	}
	| SHORT								{ std::cout<<"type_specifier -> SHORT"<<std::endl; 								$$  = new TypeSpecifier("short");	}
	| INT								{ std::cout<<"type_specifier -> INT"<<std::endl;							 	$$  = new TypeSpecifier("int");	}
	| LONG								{ std::cout<<"type_specifier -> LONG"<<std::endl; 								$$  = new TypeSpecifier("long");	}
	| FLOAT								{ std::cout<<"type_specifier -> FLOAT"<<std::endl; 								$$  = new TypeSpecifier("float");	}
	| DOUBLE							{ std::cout<<"type_specifier -> DOUBLE"<<std::endl; 							$$  = new TypeSpecifier("double");	}
	| SIGNED							{ std::cout<<"type_specifier -> SIGNED"<<std::endl; 							$$  = new TypeSpecifier("signed");	}
	| UNSIGNED							{ std::cout<<"type_specifier -> UNSIGNED"<<std::endl; 							$$  = new TypeSpecifier("unsigned");	}
	| struct_or_union_specifier			{ std::cout<<"type_specifier -> struct_or_union_specifier"<<std::endl; 			$$  = $1;						}
	| enum_specifier					{ std::cout<<"type_specifier -> enum_specifier"<<std::endl; 					$$  = $1;						}
	//| TYPE_NAME							{ std::cout<<"type_specifier -> TYPE_NAME"<<std::endl; 							$$  = $1;						}
	;

struct_or_union_specifier
	: struct_or_union IDENTIFIER '{' struct_declaration_list '}'		{ $$ = new Struct_Or_Union_Specifier($1, *$2, $4);	std::cout<<"struct_or_union_specifier -> struct_or_union IDENTIFIER '{' struct_declaration_list '}'"<<std::endl; }
	| struct_or_union '{' struct_declaration_list '}'					{ $$ = new Struct_Or_Union_Specifier($1, $3);		std::cout<<"struct_or_union_specifier -> struct_or_union '{' struct_declaration_list '}'"<<std::endl; }
	| struct_or_union IDENTIFIER										{ $$ = new Struct_Or_Union_Specifier($1, *$2);		std::cout<<"struct_or_union_specifier -> struct_or_union IDENTIFIER"<<std::endl; }
	;

struct_or_union
	: STRUCT			{ std::cout<<"struct_or_union -> STRUCT"<<std::endl; }
	| UNION				{ std::cout<<"struct_or_union -> UNION"<<std::endl;  }
	;

struct_declaration_list
	: struct_declaration								{ std::cout<<"struct_declaration_list -> struct_declaration"<<std::endl; }
	| struct_declaration_list struct_declaration		{ std::cout<<"struct_declaration_list -> struct_declaration_list struct_declaration"<<std::endl; }
	;

struct_declaration
	: specifier_qualifier_list struct_declarator_list ';'	{ std::cout<<"struct_declaration -> specifier_qualifier_list struct_declarator_list"<<std::endl; }
	;

specifier_qualifier_list
	: type_specifier specifier_qualifier_list		{ $$ = new SpecifierQualifierList(0, $1, $2);	std::cout<<"specifier_qualifier_list -> type_specifier specifier_qualifier_list"<<std::endl; }
	| type_specifier								{ $$ = $1;										std::cout<<"specifier_qualifier_list -> type_specifier"<<std::endl; }
	| type_qualifier specifier_qualifier_list		{ $$ = new SpecifierQualifierList(1, $1, $2);	std::cout<<"specifier_qualifier_list -> type_qualifier specifier_qualifier_list"<<std::endl; }
	| type_qualifier								{ $$ = $1;										std::cout<<"specifier_qualifier_list -> type_qualifier"<<std::endl; }
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
	: ENUM '{' enumerator_list '}'				{ $$ = new EnumSpecifier(0, "EMPTY", $3);	std::cout << "enum_specifier -> ENUM '{' enumerator_list '}'" << std::endl; }
	| ENUM IDENTIFIER '{' enumerator_list '}'	{ $$ = new EnumSpecifier(1, *$2, $4);	std::cout << "enum_specifier -> ENUM IDENTIFIER '{' enumerator_list '}'" << std::endl; }
	| ENUM IDENTIFIER							{ $$ = new EnumSpecifier(2, *$2);	std::cout << "enum_specifier -> ENUM IDENTIFIER" << std::endl; }
	;

enumerator_list
	: enumerator								{ $$ = $1;	std::cout << "enumerator_list -> enumerator" << std::endl; }
	| enumerator_list ',' enumerator			{ $$ = new EnumeratorList($1, $3);	std::cout << "enumerator_list -> enumerator_list ',' enumerator" << std::endl; }
	;

enumerator
	: IDENTIFIER								{ $$ = new Enumerator(*$1);; std::cout << "enumerator -> IDENTIFIER" << std::endl; }
	| IDENTIFIER EQ_ASSIGN constant_expression		{ $$ = new Enumerator(*$1, $3);	std::cout << "enumerator -> IDENTIFIER '=' constant_expression" << std::endl; }
	;

type_qualifier
	: CONST			{ std::cout << "type_qualifier -> CONST" << std::endl; }						
	| VOLATILE		{ std::cout << "type_qualifier -> VOLATILE" << std::endl; }
	;

declarator
	: pointer direct_declarator			{ $$ = new Declarator($1, $2);  std::cout << "declarator -> pointer direct_declarator" << std::endl;}
	| direct_declarator					{ $$ = $1; std::cout << "declarator -> direct_declarator" << std::endl;  }
	;

direct_declarator
	: IDENTIFIER												{ $$ = new DirectDeclarator(0, *$1);	std::cout << "direct_declarator -> IDENTIFIER" << std::endl;  /*NOT WORKING*/ }
	| '(' declarator ')'										{ $$ = new DirectDeclarator(1, $2);	std::cout << "direct_declarator -> '(' declarator ')'" << std::endl; }
	| direct_declarator '[' constant_expression ']'				{ $$ = new DirectDeclarator(2, $1, $3);	std::cout << "direct_declarator -> direct_declarator '[' constant_expression ']'" << std::endl; }
	| direct_declarator '[' ']'									{ $$ = new DirectDeclarator(3, $1);	std::cout << "direct_declarator -> direct_declarator '[' ']'" << std::endl; }
	| direct_declarator '(' parameter_type_list ')'				{ $$ = new DirectDeclarator(4, $1, $3);	std::cout << "direct_declarator -> direct_declarator '(' parameter_type_list ')'" << std::endl; }
	| direct_declarator '(' identifier_list ')'					{ $$ = new DirectDeclarator(5, $1, $3);	std::cout << "direct_declarator -> direct_declarator '(' identifier_list ')'" << std::endl; }
	| direct_declarator '(' ')'									{ $$ = new DirectDeclarator(6, $1);	std::cout << "direct_declarator -> direct_declarator '(' ')'" << std::endl; }
	;

pointer
	: '*'									{ $$ = new pointer();	std::cout << "pointer -> '*'" << std::endl; }
	| '*' type_qualifier_list				{ $$ = new pointer($2);   std::cout << "pointer -> '*' type_qualifier_list" << std::endl; }
	| '*' pointer							{ $$ = new pointer($2);	std::cout << "pointer -> '*' pointer" << std::endl; }
	| '*' type_qualifier_list pointer		{ $$ = new pointer($2, $3);   std::cout << "pointer -> '*' type_qualifier_list pointer" << std::endl; }
	;

type_qualifier_list
	: type_qualifier							
	| type_qualifier_list type_qualifier
	;


parameter_type_list
	: parameter_list				{$$ = $1;	}
	| parameter_list ',' ELLIPSIS
	;

parameter_list
	: parameter_declaration			{$$ = $1;	}
	| parameter_list ',' parameter_declaration
	;

parameter_declaration
	: declaration_specifiers declarator { $$ = $1; }
	| declaration_specifiers abstract_declarator
	| declaration_specifiers
	;

identifier_list
	: IDENTIFIER						{ $$ = new IdentifierList(*$1);		}
	| identifier_list ',' IDENTIFIER	{ $$ = new IdentifierList($1, *$3);	}
	;

type_name
	: specifier_qualifier_list									{ $$ = $1;					std::cout << "type_name -> specifier_qualifier_list" << std::endl; }
	| specifier_qualifier_list abstract_declarator				{ $$ = new TypeName($1, $2);	std::cout << "type_name -> specifier_qualifier_list abstract_declarator" << std::endl; }
	;

abstract_declarator
	: pointer									{$$ = $1;	}
	| direct_abstract_declarator				{$$ = $1;	}
	| pointer direct_abstract_declarator		{$$ = new AbstractDeclarator($1, $2);	}
	;

direct_abstract_declarator
	: '(' abstract_declarator ')'								{$$ = $2;										}
	| '[' ']'													{$$ = new DirectAbstractDeclarator(0);			}
	| '[' constant_expression ']'								{$$ = new DirectAbstractDeclarator(1, $2);		}
	| direct_abstract_declarator '[' ']'						{$$ = new DirectAbstractDeclarator(2,$1);		}
	| direct_abstract_declarator '[' constant_expression ']'	{$$ = new DirectAbstractDeclarator(3,$1, $3);	}
	| '(' ')'													{$$ = new DirectAbstractDeclarator(4);			}
	| '(' parameter_type_list ')'								{$$ = new DirectAbstractDeclarator(5, $2);		}
	| direct_abstract_declarator '(' ')'						{$$ = new DirectAbstractDeclarator(6, $1);		}
	| direct_abstract_declarator '(' parameter_type_list ')'	{$$ = new DirectAbstractDeclarator(7, $1, $3);	}
	;

initializer
	: assignment_expression					{ $$ = $1;	std::cout << "initializer -> assignment_expression" << std::endl; $$ = $1;}		
	| '{' initializer_list '}'				{ $$ = new Initializer("EMPTY", $2);	std::cout << "initializer -> '{' initializer_list '}'" << std::endl; }
	| '{' initializer_list ',' '}'			{ $$ = new Initializer("NOTEMPTY", $2);	std::cout << "initializer -> '{' initializer_list ',' '}'" << std::endl; }
	;

initializer_list
	: initializer							{ $$ = $1;	std::cout << "initializer_list -> initializer" << std::endl; }
	| initializer_list ',' initializer		{ $$ = new InitializerList($1, $3);	std::cout << "initializer_list -> initializer_list ',' initializer" << std::endl; }
	;

statement
	: labeled_statement						{ $$ = $1;	std::cout << "statement -> labeled_statement" << std::endl; }
	| compound_statement					{ $$ = $1;	std::cout << "statement -> compound_statement" << std::endl; }
	| expression_statement					{ $$ = $1;	std::cout << "statement -> expression_statement" << std::endl; }
	| selection_statement					{ $$ = $1;	std::cout << "statement -> selection_statement" << std::endl; }
	| iteration_statement					{ $$ = $1;	std::cout << "statement -> iteration_statement" << std::endl; }
	| jump_statement						{ $$ = $1;	std::cout << "statement -> jump_statement" << std::endl; }
	;

labeled_statement
	: IDENTIFIER ':' statement					{$$ = new LabeledStatement(*$1, $3);	}
	| CASE constant_expression ':' statement	{$$ = new LabeledStatement(*$1, $2, $4);	}
	| DEFAULT ':' statement						{$$ = new LabeledStatement(*$1, $3);	}
	;

compound_statement
	: '{' '}'									{											std::cout << "compound_statement -> '{' '}'" << std::endl;   }
	| '{' statement_list '}'					{$$ = $2;									std::cout << "compound_statement -> '{' statement_list '}'" << std::endl;	}
	| '{' declaration_list '}'					{$$ = $2;									std::cout << "compound_statement -> '{' declaration_list '}'" << std::endl; 	}
	| '{' declaration_list statement_list '}'	{$$ = new CompoundStatement($2, $3); 	std::cout << "compound_statement -> '{' declaration_list statement_list '}'" << std::endl;	}
	;

declaration_list
	: declaration								{$$ = $1;									std::cout << "declaration_list -> declaration" << std::endl; }
	| declaration_list declaration				{$$ = new DeclarationList($1, $2);			std::cout << "declaration_list -> declaration_list declaration" << std::endl; }
	;

statement_list
	: statement									{$$ = $1;									std::cout << "statement_list -> statement" << std::endl; }
	| statement_list statement					{$$ = new StatementList($1, $2);			std::cout << "statement_list -> statement_list statement" << std::endl; }
	;

expression_statement
	: ';'										{ $$ = new ExpressionStatement(); std::cout << "expression_statement -> ';'" << std::endl; }
	| expression ';'							{ $$ = new ExpressionStatement($1); std::cout << "expression_statement -> expression ';'" << std::endl; }
	;

selection_statement
	: IF '(' expression ')' statement					{$$ = new SelectionStatement($3, $5);		}
	| IF '(' expression ')' statement ELSE statement	{$$ = new SelectionStatement($3, $5, $7);	}
	| SWITCH '(' expression ')' statement				{$$ = new SelectionStatement($3, $5);		}
	;

iteration_statement
	: WHILE '(' expression ')' statement											{$$ = new IterationStatement(0, $3, $5);	}
	| DO statement WHILE '(' expression ')' ';'										{$$ = new IterationStatement(1, $2, $5);	}
	| FOR '(' expression_statement expression_statement ')' statement				{$$ = new IterationStatement(2, $3, $4, $6);}
	| FOR '(' expression_statement expression_statement expression ')' statement	{$$ = new IterationStatement(3, $3, $5);	}
	;

jump_statement
	: GOTO IDENTIFIER ';'			{$$ = new JumpStatement(1, *$2);	/*	This may or may not work	*/							}
	| CONTINUE ';'					{$$ = new JumpStatement(2); 																	}
	| BREAK ';'						{$$ = new JumpStatement(3); 																	}
	| RETURN ';'					{$$ = new JumpStatement(4); 																	}
	| RETURN expression ';'			{$$ = new JumpStatement(5, $2);  std::cout<<"jump_statement -> RETURN expression ;"<<std::endl; }
	;

translation_unit
	: external_declaration						{ $$ = new Translation_Unit($1);		std::cout<<"translation_unit -> external_declaration"<<std::endl; /* Put the function in here?*/}
	| translation_unit external_declaration		{ $$ = new Translation_Unit($1, $2);	std::cout<<"translation_unit -> translation_unit external_declaration"<<std::endl; /* Put the function in here?*/	}
	;

external_declaration
	: function_definition			{ $$ = $1; /*new ExternalDeclaration("function" , $1); 	*/std::cout<<"external_declaration -> function_definition"<<std::endl; }
	| declaration					{ $$ = $1; /*new ExternalDeclaration("declaration" , $1);*/ std::cout<<"external_declaration -> declaration"<<std::endl; }
	;

function_definition
	: declaration_specifiers declarator declaration_list compound_statement			{ $$ = new FunctionDefinition($1, $2, $3, $4);	std::cout<<"function_definition -> declaration_specifiers declarator declaration_list compound_statement"<<std::endl; }
	| declaration_specifiers declarator compound_statement							{ $$ = new FunctionDefinition($1, $2, $3, 0);		std::cout<<"function_definition -> declaration_specifiers declarator compound_statement"<<std::endl; }
	| declarator declaration_list compound_statement								{ $$ = new FunctionDefinition($1, $2, $3, 1);		std::cout<<"function_definition -> declarator declaration_list compound_statement"<<std::endl; }
	| declarator compound_statement													{ $$ = new FunctionDefinition($1, $2);			std::cout<<"function_definition -> declarator compound_statement	"<<std::endl; }
	;

%%

#include "lex.yy.c"

void yyerror (char const *s) {
    fprintf(stderr, "%s\n", s);
    exit(1);
}

Expression *g_root; // Definition of variable (to match declaration earlier)

Expression *parseAST()
{
  g_root=NULL;
  yyparse();
  return g_root;
}

int main()
{
// Parse the AST
    Expression *ast = parseAST();
//Compile AST? Need function in the class

	std::map< std::string, std::pair < std::string, double > > g_Var; 		//name, <type, mem location>
	std::map< std::string, std::pair < std::string, double > > loc_Var;	//name, <type, mem location>
	std::string type_check;
	int initial_memory = 0;
	bool isConstant;

	std::cout<<"----------------------------------"<<std::endl;
	std::cout<<"----------------------------------"<<std::endl;
	std::cout<<"----------------------------------"<<std::endl;
	std::cout<<"----------------------------------"<<std::endl;

	std::string MIPS;
	MIPS = ast->Compile( initial_memory, g_Var, loc_Var, type_check, isConstant);
	std::cout<<"MIPS: \n" << MIPS <<std::endl;
    return 0;
}