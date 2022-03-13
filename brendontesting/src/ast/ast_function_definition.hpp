#ifndef ast_function_definition_hpp
#define ast_function_definition_hpp

#include <string>
#include <iostream>
#include <cmath>

class FunctionDefinition
    : public Expression
{
protected:
    ExpressionPtr expr1;
    ExpressionPtr expr2;
    ExpressionPtr expr3;
    ExpressionPtr expr4;
public:
    FunctionDefinition(ExpressionPtr _expr1, ExpressionPtr _expr2, ExpressionPtr _expr3, ExpressionPtr _expr4)
        : expr1(_expr1)
        , expr2(_expr2)
        , expr3(_expr3)
        , expr4(_expr4)
    {}
    FunctionDefinition(ExpressionPtr _expr1, ExpressionPtr _expr2, ExpressionPtr _expr3)
        : expr1(_expr1)
        , expr2(_expr2)
        , expr3(_expr3)
    {}
    FunctionDefinition(ExpressionPtr _expr1, ExpressionPtr _expr2)
        : expr1(_expr1)
        , expr2(_expr2)
    {}

    virtual ~FunctionDefinition()
    { delete expr1; delete expr2; delete expr3; delete expr4; }
};

#endif
