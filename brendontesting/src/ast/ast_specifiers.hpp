#ifndef ast_specifiers_hpp
#define ast_specifiers_hpp

#include <string>
#include <iostream>
#include <cmath>

class StorageClassSpecifier
    : public Expression
{
protected:
    std::string Operator;
public:
    StorageClassSpecifier(std::string _Operator)
        : Operator(_Operator)
    {}

    virtual std::string Compile( std::string current_func, int mem, std::map<std::string, std::string> g_Var, std::map<std::string, bool> reg_available, std::string type_check ) override
    {
        return "StorageClassSpecifier";
    }
};

class TypeSpecifier
    : public Expression
{
protected:
    std::string Operator;
public:
    TypeSpecifier(std::string _Operator)
        : Operator(_Operator)
    {}

    virtual std::string Compile( std::string current_func, int mem, std::map<std::string, std::string> g_Var, std::map<std::string, bool> reg_available, std::string type_check ) override
    {
        return "TypeSpecifier";
    }
};

class Struct_Or_Union_Specifier
    : public Expression
{
protected:
    ExpressionPtr exprL;
    std::string text;
    ExpressionPtr exprR;
public:
    Struct_Or_Union_Specifier(ExpressionPtr _exprL, std::string _text, ExpressionPtr _exprR)
        : exprL(_exprL)
        , text(_text)
        , exprR(_exprR)
    {}
    Struct_Or_Union_Specifier(ExpressionPtr _exprL, std::string _text)
        : exprL(_exprL)
        , text(_text)
    {}
    Struct_Or_Union_Specifier(ExpressionPtr _exprL, ExpressionPtr _exprR)
        : exprL(_exprL)
        , exprR(_exprR)
    {}

    virtual std::string Compile( std::string current_func, int mem, std::map<std::string, std::string> g_Var, std::map<std::string, bool> reg_available, std::string type_check ) override
    {
        return "Struct_Or_Union_Specifier";
    }

    virtual ~Struct_Or_Union_Specifier()
    {
        delete exprL;
        delete exprR;
    }
};

class SpecifierQualifierList
    : public Expression
{
protected:
    int Type;
    ExpressionPtr exprL;
    ExpressionPtr exprR;
public:
    SpecifierQualifierList(int _Type, ExpressionPtr _exprL, ExpressionPtr _exprR)
        : Type(_Type)
        , exprL(_exprL)
        , exprR(_exprR)
    {}

    virtual std::string Compile( std::string current_func, int mem, std::map<std::string, std::string> g_Var, std::map<std::string, bool> reg_available, std::string type_check ) override
    {
        return "SpecifierQualifierList";
    }

    virtual ~SpecifierQualifierList()
    {
        delete exprL;
        delete exprR;
    }
};

#endif