#ifndef ast_declaration_list_hpp
#define ast_declaration_list_hpp

#include <string>
#include <iostream>
#include <cmath>

class DeclarationList
    : public Expression
{
protected:
    ExpressionPtr exprL = NULL;
    ExpressionPtr exprR = NULL;
public:
    DeclarationList(ExpressionPtr _exprL, ExpressionPtr _exprR)
        : exprL(_exprL)
        , exprR(_exprR)
    {}

    virtual std::string Compile( int &mem, std::map<std::string, std::pair<std::string, int>> g_Var, std::map<std::string, std::pair<std::string, int>> loc_Var, std::string type_check , bool &isConstant, bool isLocal) override
    {
        std::string L = exprL->Compile(mem, g_Var, loc_Var, type_check, isConstant, isLocal);
        std::string R = exprR->Compile(mem, g_Var, loc_Var, type_check, isConstant, isLocal);
        return L + R;
    }

    virtual ~DeclarationList()
    {
        delete exprL;
        delete exprR;
    }
};

#endif