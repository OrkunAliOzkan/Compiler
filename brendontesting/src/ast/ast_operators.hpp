#ifndef ast_operators_hpp
#define ast_operators_hpp

#include <string>
#include <iostream>
#include <cmath>

class Operator
    : public Expression
{
protected:
    ExpressionPtr left;
    ExpressionPtr right;
public:
    Operator(ExpressionPtr _left, ExpressionPtr _right)
        : left(_left)
        , right(_right)
    {}

    virtual ~Operator()
    {
        delete left;
        delete right;
    }
};

class AddOperator
    : public Operator
{
public:
    AddOperator(ExpressionPtr _left, ExpressionPtr _right)
        : Operator(_left, _right)
    {}
};

class SubOperator
    : public Operator
{
public:
    SubOperator(ExpressionPtr _left, ExpressionPtr _right)
        : Operator(_left, _right)
    {}
};


class MulOperator
    : public Operator
{
public:
    MulOperator(ExpressionPtr _left, ExpressionPtr _right)
        : Operator(_left, _right)
    {}
};

class DivOperator
    : public Operator
{
public:
    DivOperator(ExpressionPtr _left, ExpressionPtr _right)
        : Operator(_left, _right)
    {}
};

class ModOperator
    : public Operator
{
public:
    ModOperator(ExpressionPtr _left, ExpressionPtr _right)
        : Operator(_left, _right)
    {}
};

class OrOperator
    : public Operator
{
public:
    OrOperator(ExpressionPtr _left, ExpressionPtr _right)
        : Operator(_left, _right)
    {}
};

class bOrOperator
    : public Operator
{
public:
    bOrOperator(ExpressionPtr _left, ExpressionPtr _right)
        : Operator(_left, _right)
    {}
};

class AndOperator
    : public Operator
{
public:
    AndOperator(ExpressionPtr _left, ExpressionPtr _right)
        : Operator(_left, _right)
    {}
};

class bAndOperator
    : public Operator
{
public:
    bAndOperator(ExpressionPtr _left, ExpressionPtr _right)
        : Operator(_left, _right)
    {}
};

class xorOperator
    : public Operator
{
public:
    xorOperator(ExpressionPtr _left, ExpressionPtr _right)
        : Operator(_left, _right)
    {}
};

class EqOperator
    : public Operator
{
public:
    EqOperator(ExpressionPtr _left, ExpressionPtr _right)
        : Operator(_left, _right)
    {}
};

class NeqOperator
    : public Operator
{
public:
    NeqOperator(ExpressionPtr _left, ExpressionPtr _right)
        : Operator(_left, _right)
    {}
};

class LTOperator
    : public Operator
{
public:
    LTOperator(ExpressionPtr _left, ExpressionPtr _right)
        : Operator(_left, _right)
    {}
};

class GTOperator
    : public Operator
{
public:
    GTOperator(ExpressionPtr _left, ExpressionPtr _right)
        : Operator(_left, _right)
    {}
};

class LEOperator
    : public Operator
{
public:
    LEOperator(ExpressionPtr _left, ExpressionPtr _right)
        : Operator(_left, _right)
    {}
};

class GEOperator
    : public Operator
{
public:
    GEOperator(ExpressionPtr _left, ExpressionPtr _right)
        : Operator(_left, _right)
    {}
};

class AShiftLeftOperator
    : public Operator
{
public:
    AShiftLeftOperator(ExpressionPtr _left, ExpressionPtr _right)
        : Operator(_left, _right)
    {}
};

class AShiftRightOperator
    : public Operator
{
public:
    AShiftRightOperator(ExpressionPtr _left, ExpressionPtr _right)
        : Operator(_left, _right)
    {}
};


#endif
