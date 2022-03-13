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
        return "declarator";
    }
};

class Declaration_Spec
    : public Expression
{
protected:
    std::string type;
    ExpressionPtr exprL;
    ExpressionPtr exprR;
public:
    Declaration_Spec(std::string _type, ExpressionPtr _left, ExpressionPtr _right)
        : type(_type)
        , exprL(_left)
        , exprR(_right)
    {}
    Declaration_Spec(std::string _type, ExpressionPtr _left)
        : type(_type)
        , exprL(_left)
    {}

    // VOID, CHAR, INT, LONG ETC.
    // EXTERN TYPEDEF STATIC AUTO REGISTER
    // CONST VOLATILE

    virtual std::string Compile( std::string current_func, int mem, std::map<std::string, std::string> g_Var, std::map<std::string, bool> reg_available, std::string type_check ) override
    {
        if (exprR == NULL)  { return exprL->Compile(current_func, mem, g_Var, reg_available, type_check); }
        else { return exprL->Compile(current_func, mem, g_Var, reg_available, type_check) + " " + exprR->Compile(current_func, mem, g_Var, reg_available, type_check); }
    }

    virtual ~Declaration_Spec()
    {
        delete exprL;
        delete exprR;
    }
};

class DirectDeclarator
    : public Expression
{
protected:
    int Type;
    std::string ident;
    ExpressionPtr exprL;
    ExpressionPtr exprR;
public:
    DirectDeclarator(int _Type, std::string _ident, ExpressionPtr _exprL, ExpressionPtr _exprR)
        : Type(_Type)
        , ident(_ident)
        , exprL(_exprL)
        , exprR(_exprR)
    {}

    DirectDeclarator(int _Type, std::string _ident)
        : Type(_Type)
        , ident(_ident)
    {}

    DirectDeclarator(int _Type, ExpressionPtr _exprL )
        : Type(_Type)
        , exprL(_exprL)
    {}

        DirectDeclarator(int _Type, ExpressionPtr _exprL, ExpressionPtr _exprR)
        : Type(_Type)
        , exprL(_exprL)
        , exprR(_exprR)
    {}

    virtual std::string Compile( std::string current_func, int mem, std::map<std::string, std::string> g_Var, std::map<std::string, bool> reg_available, std::string type_check ) override
    {
        if          (Type == 0) { return ident; } // For direct_declarator -> IDENTIFIER
        else if     (Type == 1) { return "NOT IMPLEMENTED"; }
        else if     (Type == 2) { return "NOT IMPLEMENTED"; }
        else if     (Type == 3) { return "NOT IMPLEMENTED"; }
        else if     (Type == 4) { return "NOT IMPLEMENTED"; }
        else if     (Type == 5) { return "NOT IMPLEMENTED"; }
        else                    { return "NOT IMPLEMENTED"; }
    }

    virtual ~DirectDeclarator()
    {
        delete exprL;
        delete exprR;
    }
};

class Init_Declarator
    : public Expression
{
protected:
    ExpressionPtr exprL;
    ExpressionPtr exprR;
public:
    Init_Declarator(ExpressionPtr _exprL, ExpressionPtr _exprR)
        : exprL(_exprL)
        , exprR(_exprR)
    {}

    virtual std::string Compile( std::string current_func, int mem, std::map<std::string, std::string> g_Var, std::map<std::string, bool> reg_available, std::string type_check ) override
    {
        return "hello!";
    }

    virtual ~Init_Declarator()
    {
        delete exprL;
        delete exprR;
    }
};

class Init_Declarator_List
    : public Expression
{
protected:
    ExpressionPtr exprL;
    ExpressionPtr exprR;
public:
    Init_Declarator_List(ExpressionPtr _exprL, ExpressionPtr _exprR)
        : exprL(_exprL)
        , exprR(_exprR)
    {}

    virtual std::string Compile( std::string current_func, int mem, std::map<std::string, std::string> g_Var, std::map<std::string, bool> reg_available, std::string type_check ) override
    {
        return "hello!";
    }

    virtual ~Init_Declarator_List()
    {
        delete exprL;
        delete exprR;
    }
};

class Declaration
    : public Expression
{
protected:
    ExpressionPtr exprL;
    ExpressionPtr exprR;
public:
    Declaration(ExpressionPtr _exprL, ExpressionPtr _exprR)
        : exprL(_exprL)
        , exprR(_exprR)
    {}

    virtual std::string Compile( std::string current_func, int mem, std::map<std::string, std::string> g_Var, std::map<std::string, bool> reg_available, std::string type_check ) override
    {
        return exprL->Compile(current_func, mem, g_Var, reg_available, type_check) + " " + exprR->Compile(current_func, mem, g_Var, reg_available, type_check);
    }

    virtual ~Declaration()
    {
        delete exprL;
        delete exprR;
    }
};

class ExternalDeclaration
    : public Expression
{
protected:
    std::string type;
    ExpressionPtr expr;
public:
    ExternalDeclaration(std::string _type, ExpressionPtr _expr)
        : type(_type)
        , expr(_expr)
    {}

    virtual std::string Compile( std::string current_func, int mem, std::map<std::string, std::string> g_Var, std::map<std::string, bool> reg_available, std::string type_check ) override
    {
        if (type == "declaration")  { return expr->Compile(current_func, mem, g_Var, reg_available, type_check);}
        else                        { return "not implemented"; }
    }

    virtual void AtLocation() override { std::cout<<"in external decalation"<<std::endl; }

    virtual ~ExternalDeclaration()
    {
        delete expr;
    }
};

class DirectAbstractDeclarator
    : public Expression
{
protected:
    int Type;
    ExpressionPtr expr1;
    ExpressionPtr expr2;
public:
    DirectAbstractDeclarator(int _Type, ExpressionPtr _expr1, ExpressionPtr _expr2)
        : Type(_Type)
        , expr1(_expr1)
        , expr2(_expr2)
    {}
    DirectAbstractDeclarator(int _Type, ExpressionPtr _expr1)
        : Type(_Type)
        , expr1(_expr1)
    {}
    DirectAbstractDeclarator(int _Type)
        : Type(_Type)
    {}

    virtual std::string Compile( std::string current_func, int mem, std::map<std::string, std::string> g_Var, std::map<std::string, bool> reg_available, std::string type_check ) override
    {
        return "DirectAbstractDeclarator!\n";
    }

    virtual ~DirectAbstractDeclarator() { delete expr1; delete expr2; }
};

class AbstractDeclarator
    : public Expression
{
protected:
    ExpressionPtr exprL;
    ExpressionPtr exprR;
public:
    AbstractDeclarator(ExpressionPtr _exprL, ExpressionPtr _exprR)
        : exprL(_exprL)
        , exprR(_exprR)
    {}

    virtual std::string Compile( std::string current_func, int mem, std::map<std::string, std::string> g_Var, std::map<std::string, bool> reg_available, std::string type_check ) override
    {
        return "AbstractDeclarator!\n";
    }

    virtual ~AbstractDeclarator() { delete exprL; delete exprR; }
};

#endif
