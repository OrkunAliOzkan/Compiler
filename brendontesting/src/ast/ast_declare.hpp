#ifndef ast_declare_hpp
#define ast_declare_hpp

#include <string>
#include <iostream>
#include <cmath>

class Declarator
    : public Expression
{
protected:
    ExpressionPtr exprL;
    ExpressionPtr exprR;
public:
    Declarator(ExpressionPtr _exprL, ExpressionPtr _exprR)
        : exprL(_exprL)
        , exprR(_exprR)
    {}

    virtual ~Declarator()
    {
        delete exprL;
        delete exprR;
    }

    virtual std::string Compile( std::string current_func, int mem, std::map<std::string, std::string> g_Var, std::map<std::string, bool> reg_available, std::string type_check ) override
    {
        std::string identifier;
        if (exprL == NULL)
        {
            identifier = exprR->Compile( current_func, mem, g_Var, reg_available, type_check);
        }
        else
        {}
        return identifier;
    }
};

class DirectDeclarator
    : public Expression
{
protected:
    std::string identifier;
public:
    DirectDeclarator(std::string _identifier)
        : identifier(_identifier)
    {}

    virtual std::string Compile( std::string current_func, int mem, std::map<std::string, std::string> g_Var, std::map<std::string, bool> reg_available, std::string type_check ) override
    {
        return "hello!";
    }
};

#endif
