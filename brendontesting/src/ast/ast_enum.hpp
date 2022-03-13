#ifndef ast_enum_hpp
#define ast_enum_hpp

#include <string>
#include <iostream>
#include <cmath>

class EnumSpecifier
    : public Expression
{
protected:
    int Type;
    std::string text;
    ExpressionPtr expr;
public:
    EnumSpecifier(int _Type, std::string _text, ExpressionPtr _expr)
        : Type(_Type)
        , text(_text)
        , expr(_expr)
    {}
    EnumSpecifier(int _Type, std::string _text)
        : Type(_Type)
        , text(_text)
    {}

    virtual std::string Compile( std::string current_func, int mem, std::map<std::string, std::string> g_Var, std::map<std::string, bool> reg_available, std::string type_check ) override
    {
        return "EnumSpecifier";
    }

    virtual ~EnumSpecifier() { delete expr; }
};

class EnumeratorList
    : public Expression
{
protected:
    ExpressionPtr exprL;
    ExpressionPtr exprR;
public:
    EnumeratorList(ExpressionPtr _exprL, ExpressionPtr _exprR)
        : exprL(_exprL)
        , exprR(_exprR)
    {}

    virtual std::string Compile( std::string current_func, int mem, std::map<std::string, std::string> g_Var, std::map<std::string, bool> reg_available, std::string type_check ) override
    {
        return "EnumeratorList";
    }

    virtual ~EnumeratorList() { delete exprL; delete exprR; }
};

class Enumerator
    : public Expression
{
protected:
    std::string ident;
    ExpressionPtr expr;
public:
    Enumerator(std::string _ident, ExpressionPtr _expr)
        : ident(_ident)
        , expr(_expr)
    {}

    Enumerator(std::string _ident)
        : ident(_ident)
    {}

    virtual std::string Compile( std::string current_func, int mem, std::map<std::string, std::string> g_Var, std::map<std::string, bool> reg_available, std::string type_check ) override
    {
        return "Enumerator";
    }

    virtual ~Enumerator() { delete expr; }
};

#endif