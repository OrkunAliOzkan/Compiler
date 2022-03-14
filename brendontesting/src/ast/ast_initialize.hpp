#ifndef ast_initialize_hpp
#define ast_initialize_hpp

#include <string>
#include <iostream>
#include <cmath>

class Initializer
    : public Expression
{
protected:
    std::string Type;
    ExpressionPtr expr = NULL;
public:
    Initializer(std::string _Type, ExpressionPtr _expr)
        : Type(_Type)
        , expr(_expr)
    {}

    virtual std::string Compile( std::string current_func, int mem, std::map<std::string, std::string> g_Var, std::map<std::string, bool> reg_available, std::string type_check ) override
    {
        return "Initializer!\n";
    }

    virtual ~Initializer() { delete expr; }
};

class InitializerList
    : public Expression
{
protected:
    ExpressionPtr exprL = NULL;
    ExpressionPtr exprR = NULL;
public:
    InitializerList(ExpressionPtr _exprL, ExpressionPtr _exprR)
        : exprL(_exprL)
        , exprR(_exprR)
    {}

    virtual std::string Compile( std::string current_func, int mem, std::map<std::string, std::string> g_Var, std::map<std::string, bool> reg_available, std::string type_check ) override
    {
        return "Initializer!\n";
    }

    virtual ~InitializerList() { delete exprL; delete exprR; }
};

#endif