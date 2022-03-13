#ifndef ast_selection_statement_hpp
#define ast_selection_statement_hpp

#include <string>
#include <iostream>
#include <cmath>

class SelectionStatement
    : public Expression
{
protected:
    ExpressionPtr statement1;
    ExpressionPtr statement2;
    ExpressionPtr statement3;
public:
    SelectionStatement(ExpressionPtr _statement1, ExpressionPtr _statement2)
        : statement1(_statement1)
        , statement2(_statement2)
    {}

    SelectionStatement(ExpressionPtr _statement1, ExpressionPtr _statement2, ExpressionPtr _statement3)
        : statement1(_statement1)
        , statement2(_statement2)
        , statement3(_statement3)
    {}

    virtual ~SelectionStatement()
    {
        delete statement1;
        delete statement2;
        delete statement3;
    }
};

#endif
