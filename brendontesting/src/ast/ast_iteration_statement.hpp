#ifndef ast_iteration_statement_hpp
#define ast_iteration_statement_hpp

#include <string>
#include <iostream>
#include <cmath>

class IterationStatement
    : public Expression
{
protected:
    int Type;
    ExpressionPtr expr1;
    ExpressionPtr expr2;
    ExpressionPtr expr3;
public:
    IterationStatement(int _Type, ExpressionPtr _expr1, ExpressionPtr _expr2, ExpressionPtr _expr3)
        : Type(_Type)
        , expr1(_expr1)
        , expr2(_expr2)
        , expr3(_expr3)
    {}
    IterationStatement(int _Type, ExpressionPtr _expr1, ExpressionPtr _expr2)
        : Type(_Type)
        , expr1(_expr1)
        , expr2(_expr2)
    {}

    virtual ~IterationStatement()
    {
        delete expr1;
        delete expr2;
        delete expr3;
    }
};

#endif
