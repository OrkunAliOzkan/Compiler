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
    ExpressionPtr exprR;
public:
    AssignOperator(ExpressionPtr _exprL, ExpressionPtr _exprR)
        : exprL(_exprL)
        , exprR(_exprR)
    {}

    virtual ~AssignOperator()
    {
        delete exprL;
        delete exprR;
    }

    virtual std::string Compile( std::string current_func, int mem, std::map<std::string, std::string> g_Var, std::map<std::string, bool> reg_available, std::string type_check ) override
    {
        exprL->Compile( current_func, mem, g_Var, reg_available, type_check );
        exprR->Compile( current_func, mem, g_Var, reg_available, type_check );
        return "add 1 2 3";
    }
};

#endif
