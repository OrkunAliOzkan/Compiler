#ifndef ast_compound_statement_hpp
#define ast_compound_statement_hpp

#include <string>
#include <iostream>
#include <cmath>

class CompoundStatement
    : public Expression
{
protected:
    int Type;
    ExpressionPtr exprL;
    ExpressionPtr exprR;
public:
    CompoundStatement(int _Type)
        : Type(_Type)
    {}

    CompoundStatement(int _Type, ExpressionPtr _exprL)
        : Type(_Type)
        , exprL(_exprL)
    {}

    CompoundStatement(int _Type, ExpressionPtr _exprL, ExpressionPtr _exprR)
        : Type(_Type)
        , exprL(_exprL)
        , exprR(_exprR)
    {}

    virtual std::string Compile( std::string current_func, int mem, std::map<std::string, std::string> g_Var, std::map<std::string, bool> reg_available, std::string type_check ) override
    {
        return "CompoundStatement";
    }

    virtual ~CompoundStatement()
    {
        delete exprL;
        delete exprR;
    }
};

#endif