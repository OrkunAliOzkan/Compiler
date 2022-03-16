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

    virtual std::string Compile( int &mem, std::map<std::string, std::pair<std::string, int>> g_Var, std::map<std::string, std::pair<std::string, int>> loc_Var, std::string type_check , bool &isConstant, bool isLocal) override
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

    virtual std::string Compile( int &mem, std::map<std::string, std::pair<std::string, int>> g_Var, std::map<std::string, std::pair<std::string, int>> loc_Var, std::string type_check , bool &isConstant, bool isLocal) override
    {
        return Operator;
    }

    virtual void AtLocation() override { std::cout << "Hello in Type Specifier!" << std::endl; }
};

class Struct_Or_Union_Specifier
    : public Expression
{
protected:
    ExpressionPtr exprL = NULL;
    std::string text;
    ExpressionPtr exprR = NULL;
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

    virtual std::string Compile( int &mem, std::map<std::string, std::pair<std::string, int>> g_Var, std::map<std::string, std::pair<std::string, int>> loc_Var, std::string type_check , bool &isConstant, bool isLocal) override
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
    ExpressionPtr exprL = NULL;
    ExpressionPtr exprR = NULL;
public:
    SpecifierQualifierList(int _Type, ExpressionPtr _exprL, ExpressionPtr _exprR)
        : Type(_Type)
        , exprL(_exprL)
        , exprR(_exprR)
    {}

    virtual std::string Compile( int &mem, std::map<std::string, std::pair<std::string, int>> g_Var, std::map<std::string, std::pair<std::string, int>> loc_Var, std::string type_check , bool &isConstant, bool isLocal) override
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