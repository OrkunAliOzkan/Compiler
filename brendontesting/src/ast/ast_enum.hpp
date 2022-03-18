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
    ExpressionPtr expr = NULL;
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

    virtual std::string Compile(    int &mem, 
                                    std::map<std::string, 
                                    std::pair<std::string, 
                                    int>> g_Var, 
                                    std::map<std::string, 
                                    std::pair<std::string, 
                                    int>> loc_Var, std::string type_check , bool &isConstant, bool isLocal) override
    {
        return "EnumSpecifier";
    }

    virtual ~EnumSpecifier() { delete expr; }
};

class EnumeratorList
    : public Expression
{
protected:
    ExpressionPtr exprL = NULL;
    ExpressionPtr exprR = NULL;
public:
    EnumeratorList(ExpressionPtr _exprL, ExpressionPtr _exprR)
        : exprL(_exprL)
        , exprR(_exprR)
    {}

    virtual std::string Compile(    int &mem, std::map<std::string, std::pair<std::string, 
                                    int>> g_Var, std::map<std::string, std::pair<std::string, 
                                    int>> loc_Var, std::string type_check , 
                                    bool &isConstant, 
                                    bool isLocal) override
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
    ExpressionPtr expr = NULL;
public:
    Enumerator(std::string _ident, ExpressionPtr _expr)
        : ident(_ident)
        , expr(_expr)
    {}

    Enumerator(std::string _ident)
        : ident(_ident)
    {}

    virtual std::string Compile( int &mem, std::map<std::string, std::pair<std::string, int>> g_Var, std::map<std::string, std::pair<std::string, int>> loc_Var, std::string type_check , bool &isConstant, bool isLocal) override
    {
        return "Enumerator";
    }

    virtual ~Enumerator() { delete expr; }
};

#endif