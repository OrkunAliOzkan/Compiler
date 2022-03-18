#ifndef ast_compound_statement_hpp
#define ast_compound_statement_hpp

#include <string>
#include <iostream>
#include <cmath>

class CompoundStatement
    : public Expression
{
protected:
    ExpressionPtr exprL = NULL;
    ExpressionPtr exprR = NULL;
public:
    CompoundStatement(ExpressionPtr _exprL, ExpressionPtr _exprR)
        : exprL(_exprL)
        , exprR(_exprR)
    {}

    virtual std::string Compile( int &mem, std::map<std::string, std::pair<std::string, int>> g_Var, std::map<std::string, std::pair<std::string, int>> &loc_Var, std::string type_check , bool &isConstant, bool isLocal) override
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