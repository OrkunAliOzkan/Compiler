#ifndef ast_function_hpp
#define ast_function_hpp

#include <string>
#include <iostream>
#include <cmath>

class Function
    : public Expression
{
protected:
    ExpressionPtr type_inf;
    ExpressionPtr param;
    ExpressionPtr evaluate;
public:
    Function(ExpressionPtr _type, ExpressionPtr _param, ExpressionPtr _evaluate)
        : type_inf(_type)
        , param(_param)
        , evaluate(_evaluate)
    {}

    virtual ~Function()
    {
        delete type_inf;
        delete param;
        delete evaluate;
    }
};

#endif
