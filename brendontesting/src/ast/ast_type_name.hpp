#ifndef ast_type_name_hpp
#define ast_type_name_hpp

#include <string>
#include <iostream>
#include <cmath>

class TypeName
    : public Expression
{
protected:
    ExpressionPtr exprL;
    ExpressionPtr exprR;
public:
    TypeName(ExpressionPtr _exprL, ExpressionPtr _exprR)
        : exprL(_exprL)
        , exprR(_exprR)
    {}

    virtual std::string Compile( std::string current_func, int mem, std::map<std::string, std::string> g_Var, std::map<std::string, bool> reg_available, std::string type_check ) override
    {
        return "TypeName!\n";
    }

    virtual ~TypeName()
    {
        delete exprL;
        delete exprR;
    }
};

#endif