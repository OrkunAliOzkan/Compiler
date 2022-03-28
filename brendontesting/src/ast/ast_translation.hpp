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

    virtual std::string Compile( int &mem, std::map<std::string, std::pair<std::string, int>> g_Var, std::map<std::string, std::pair<std::string, int>> &loc_Var, std::string type_check , bool &isConstant, bool isLocal, std::vector<int> func_call) override
    {
        if (exprR == NULL)  { return exprL->Compile(mem, g_Var, loc_Var, type_check, isConstant, isLocal, func_call); }
        else                { return exprL->Compile(mem, g_Var, loc_Var, type_check, isConstant, isLocal, func_call) + exprR->Compile(mem, g_Var, loc_Var, type_check, isConstant, isLocal, func_call); }
    }

    virtual void AtLocation() override { std::cout << "Hello in Translation_Unit!" << std::endl; }

    virtual ~Translation_Unit()
    {
        delete exprL;
        delete exprR;
    }
};

#endif