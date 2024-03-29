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
//	Expression
	/*Expression*/
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

	/*Unary Expression*/
		class Unary_Expression : public Expression{
			Expression* expression = NULL;  //  Expression we shall evaluate
			std::string expression_type;    //  Type of expression so we know HOW to evaluate it
		public:
			~Unary_Expression()	{delete expression; delete expression_type;	}
			UnaryExpression(Expression* exp,std::string ExpType): expression(exp), expression_type(ExpType)
			const Expression *getNext() const 																{};
			std::string getType() const 																	{};
		};

	/*Binary Expression*/ /*Loop Expression*/
		class Binary_Expression : public Expression{
			Expression* Left = NULL;  		//  Operand #1
			Expression* Right = NULL;  		//  Operand #2
			std::string OperatorType;    	//  Op type
		public:
			BinaryExpression(Expression* exp1, Expression* exp2,std::string ExpType): Left(exp1), Right(exp2), OperatorType(ExpType)
			const Expression *getLeft() const																							{};
			const Expression *getRight() const																							{};
			std::string getOperator() const																								{};
		};

	/*Assign Expression*/
		class Assignment_Op : public Expression{
			std::string value;    	//  Value
		public:
			Assign_Expression(std::string val): value(val) 	{}
			std::string getValue() const					{};
		}

	/*conditional Expression*/
		class Conditonal_Expression : public Expression{
			Expression* Cond = NULL;  		//  Condition #1
			Expression* Bod = NULL;  		//  Body of code #2
		public:
			Conditonal_Expression(Expression* conditon, Expression* body): Cond(conditon), Bod(body)
			const Expression *getLeft() const;
			const Expression *getRight() const;
		};

//	Declarations
	class Declaration : public Node{
		public:
			virtual const Expression *getLeft() const {};
			virtual const Expression *getRight() const {};
			virtual std::string getType() const;
	}

//	Statements
	/*Statement*/
		class Statement : public Node{
		public:
			virtual const Statement *getLeft() const {};
			virtual const Statement *getRight() const {};
			virtual const Statement *getNext() const {};
			virtual std::string getType() const;

			//virtual std::string getName() const {}
		    //  Used in constant / variable declaration
				virtual int getConstant() const {};
		    //  Used in determining operaition to use during code generation
				virtual std::string getOperator() const {};
		};

};
