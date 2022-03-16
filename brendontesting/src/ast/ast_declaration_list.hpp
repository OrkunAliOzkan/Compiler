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

    virtual std::string Compile( int &mem, std::map<std::string, std::pair<std::string, double>> g_Var, std::map<std::string, std::pair<std::string, double>> loc_Var, std::string type_check , bool &isConstant) override
    {
        return "DeclarationList";
    }

    virtual ~DeclarationList()
    {
        delete exprL;
        delete exprR;
    }
};

#endif