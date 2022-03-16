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
    ExpressionPtr exprL = NULL;
    ExpressionPtr exprR = NULL;
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

    virtual std::string Compile( int &mem, std::map<std::string, std::pair<std::string, double>> g_Var, std::map<std::string, std::pair<std::string, double>> loc_Var, std::string type_check , bool &isConstant) override
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