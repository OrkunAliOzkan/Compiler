#ifndef ast_hpp
#define ast_hpp

#include <string>
#include <iostream>
#include <memory>
#include <initializer_list>
#include <vector>
#include <map>

#include "ast/ast_expression.hpp"
#include "ast/ast_primitives.hpp"
#include "ast/ast_operators.hpp"
#include "ast/ast_unary.hpp"
#include "ast/ast_functions.hpp"
#include "ast/ast_declare.hpp"


extern const Expression *parseAST();

#endif



#ifndef generic_ast_hpp
#define generic_ast_hpp

#include <string>
#include <iostream>
#include <memory>
#include <initializer_list>
#include <vector>
#include <map>

struct Tree;

typedef std::shared_ptr<Tree> TreePtr;
/*Orkun goofing about*/
#ifndef AST_H
#define	AST_H

#include <iostream>
#include <cstdlib>
#include <string>
#include <map>
#include <vector>
#include <stack>


class mips_stack;

// Base node class for AST
class Node{
public:
	virtual ~Node() {}
};

struct Tree
{
class Expression : public Node{
public:
	virtual const Expression *getLeft() const {}
	virtual const Expression *getRight() const {}
	virtual const Expression *getNext() const {}
	virtual std::string getType() const;

	//virtual std::string getName() const {}
    //  Used in constant / variable declaration
	    virtual int getConstant() const {}
    //  Used in determining operaition to use during code generation
	    virtual std::string getOperator() const {}
};

class Unary_Expression : public Expression{
	Expression* expression = NULL;  //  Expression we shall evaluate
	std::string expression_type;    //  Type of expression so we know HOW to evaluate it
public:
	UnaryExpression(Expression* exp,std::string ExpType): expression(exp), expression_type(ExpType) {}
	const Expression *getNext() const;
	std::string getType() const;
};
