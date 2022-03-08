#ifndef ast_operators_hpp
#define ast_operators_hpp

#include <string>
#include <iostream>
#include <cmath>
#include <memory>
#include <initializer_list>
#include <vector>
#include <map>

struct Operator;
typedef std::shared_ptr<Operator> OperatorPtr;

struct Operator
{
    Tree(std::string _type, OperatorPtr _left, OperatorPtr _right)
        : type(_type)
        , left(_left)
        , right(_right)
    {}

    std::string type;
    OperatorPtr left;
    OperatorPtr right;

    virtual ~Operator()
    {
        delete left;
        delete right;
    }
};
inline OperatorPtr Add(OperatorPtr left, OperatorPtr right)
{ return std::make_shared<Tree>("Add", left, right); }

inline OperatorPtr Sub(OperatorPtr left, OperatorPtr right)
{ return std::make_shared<Tree>("Sub", left, right); }

inline OperatorPtr LessThan(OperatorPtr left, OperatorPtr right)
{ return std::make_shared<Tree>("LessThan", left, right); }

inline OperatorPtr Mul(OperatorPtr left, OperatorPtr right)
{ return std::make_shared<Tree>("Multiplication", left, right); }

inline OperatorPtr Div(OperatorPtr left, OperatorPtr right)
{ return std::make_shared<Tree>("Division", left, right); }
////////////////////////////////////////////////////////////////////////////////////////////

#endif
