#ifndef ast_labeled_statement_hpp
#define ast_labeled_statement_hpp

#include <string>
#include <iostream>
#include <cmath>

class LabeledStatement
    : public Expression
{
protected:
    std::string Type;
    ExpressionPtr exprL;
    ExpressionPtr exprR;
public:
    LabeledStatement(std::string _Type, ExpressionPtr _exprL, ExpressionPtr _exprR)
        : Type(_Type)
        , exprL(_exprL)
        , exprR(_exprR)
    {}
    LabeledStatement(std::string _Type, ExpressionPtr _exprL)
        : Type(_Type)
        , exprL(_exprL)
    {}

    virtual std::string Compile( std::string current_func, int mem, std::map<std::string, std::string> g_Var, std::map<std::string, bool> reg_available, std::string type_check ) override
    {
        return "LabeledStatement";
    }

    virtual ~LabeledStatement()
    {
        delete exprL;
        delete exprR;
    }
};

#endif