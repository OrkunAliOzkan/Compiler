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

    virtual std::string Compile( std::string current_func, int mem, std::map<std::string, std::string> g_Var, std::map<std::string, bool> reg_available, std::string type_check ) override
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