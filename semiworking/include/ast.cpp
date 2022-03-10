#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <stack>
#include "ast.hpp"

//  Unary
    const Expression* Unary_Expression::getNext() const                        {return expression;			}
	std::string Unary_Expression::getType() const                              {return expression_type;	    }

//  Binary
			const Expression* Binary_Expression::getLeft() const               {return Left;			    }
			const Expression* Binary_Expression::getRight() const              {return Right;			    }
			std::string Binary_Expression::getOperator() const                 {return OperatorType;	    }

//  Assignment Operator
			std::string Assignment_Op::getValue() const                     	{return value;	            }

//conditional Expression
			const Expression *getLeft() const                                   {return Left;               }
			const Expression *getRight() const                                  {return Right;              }
		};

//	Declarations
	class Declaration : public Node{
		public:
			virtual const Expression *getLeft() const {}
			virtual const Expression *getRight() const {}
			virtual std::string getType() const;
	}

//	Statements
	/*Statement*/
		class Statement : public Node{
		public:
			virtual const Statement *getLeft() const {}
			virtual const Statement *getRight() const {}
			virtual const Statement *getNext() const {}
			virtual std::string getType() const;

			//virtual std::string getName() const {}
		    //  Used in constant / variable declaration
			    virtual int getConstant() const {}
		    //  Used in determining operaition to use during code generation
			    virtual std::string getOperator() const {}
		};


//  Identifier

//  Constant

//  Bracket Expresion
