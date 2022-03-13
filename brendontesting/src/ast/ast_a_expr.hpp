#ifndef ast_a_expr_hpp
#define ast_a_expr_hpp

#include <string>
#include <iostream>
#include <cmath>

class a_expr
    : public Expression
{
protected:
    ExpressionPtr left;
    ExpressionPtr right;
public:
    a_expr(ExpressionPtr _left, ExpressionPtr _right)
        : left(_left)
        , right(_right)
    {}

    virtual ~a_expr()
    {
        delete left;
        delete right;
    }
};

#endif