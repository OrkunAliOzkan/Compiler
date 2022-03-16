#ifndef ast_statement_list_hpp
#define ast_statement_list_hpp

#include <string>
#include <iostream>
#include <cmath>

class StatementList
    : public Expression
{
protected:
    ExpressionPtr exprL = NULL;
    ExpressionPtr exprR = NULL;
public:
    StatementList(ExpressionPtr _exprL, ExpressionPtr _exprR)
        : exprL(_exprL)
        , exprR(_exprR)
    {}

    virtual std::string Compile( int &mem, std::map<std::string, std::pair<std::string, double>> g_Var, std::map<std::string, std::pair<std::string, double>> loc_Var, std::string type_check , bool &isConstant) override
    {
        return "StatementList";
    }

    virtual ~StatementList()
    {
        delete exprL;
        delete exprR;
    }
};

#endif