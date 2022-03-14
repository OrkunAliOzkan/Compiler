#ifndef ast_translation_hpp
#define ast_translation_hpp

#include <string>
#include <iostream>
#include <cmath>

class Translation_Unit
    : public Expression
{
protected:
    ExpressionPtr exprL = NULL;
    ExpressionPtr exprR = NULL;
public:
    Translation_Unit(ExpressionPtr _exprL, ExpressionPtr _exprR)
        : exprL(_exprL)
        , exprR(_exprR)
    {}
    
    Translation_Unit(ExpressionPtr _exprL)
        : exprL(_exprL)
    {}

    virtual std::string Compile( std::string current_func, int mem, std::map<std::string, std::string> g_Var, std::map<std::string, bool> reg_available, std::string type_check ) override
    {
        if (exprR == NULL)  { return exprL->Compile(current_func, mem, g_Var, reg_available, type_check); }
        else                { std::cout << "Not implemented yet" << std::endl; return "Not implemented."; }
    }

    virtual void AtLocation() override { std::cout << "Hello in Translation_Unit!" << std::endl; }

    virtual ~Translation_Unit()
    {
        delete exprL;
        delete exprR;
    }
};

#endif