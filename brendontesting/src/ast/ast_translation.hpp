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

    virtual std::string Compile( int &mem, std::map<std::string, std::pair<std::string, double>> g_Var, std::map<std::string, std::pair<std::string, double>> loc_Var, std::string type_check , bool &isConstant) override
    {
        if (exprR == NULL)  { return exprL->Compile(mem, g_Var, loc_Var, type_check, isConstant); }
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