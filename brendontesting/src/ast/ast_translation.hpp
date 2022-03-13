#ifndef ast_translation_hpp
#define ast_translation_hpp

#include <string>
#include <iostream>
#include <cmath>

class Translation_Unit
    : public Expression
{
protected:
    ExpressionPtr exprL;
    ExpressionPtr exprR;
public:
    Translation_Unit(ExpressionPtr _exprL, ExpressionPtr _exprR)
        : exprL(_exprL)
        , exprR(_exprR)
    {}

    virtual std::string Compile( std::string current_func, int mem, std::map<std::string, std::string> g_Var, std::map<std::string, bool> reg_available, std::string type_check ) override
    {
        return "Translation_Unit!\n";
    }

    virtual ~Translation_Unit()
    {
        delete exprL;
        delete exprR;
    }
};

#endif