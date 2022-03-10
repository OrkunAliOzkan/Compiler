#ifndef ast_assign_hpp
#define ast_assign_hpp

#include <string>
#include <iostream>
#include <cmath>

class AssignOperator
    : public Expression
{
protected:
    ExpressionPtr exprL;
    std::string op;
    ExpressionPtr exprR;
public:
    AssignOperator(ExpressionPtr _exprL, std::string _op, ExpressionPtr _exprR)
        : exprL(_exprL)
        , op(_op)
        , exprR(_exprR)
    {}

    virtual ~AssignOperator()
    {
        delete exprL;
        delete exprR;
    }
};

#endif
