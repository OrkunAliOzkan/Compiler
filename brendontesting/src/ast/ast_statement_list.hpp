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

    virtual std::string Compile( int &mem, std::map<std::string, std::pair<std::string, int>> g_Var, std::map<std::string, std::pair<std::string, int>> &loc_Var, std::string type_check , bool &isConstant, bool isLocal, std::vector<int> func_call) override
    {
        std::string L = exprL->Compile(mem, g_Var, loc_Var, type_check, isConstant, isLocal, func_call);
        std::string R = exprR->Compile(mem, g_Var, loc_Var, type_check, isConstant, isLocal, func_call);
        return L + R;
    }

    virtual ~StatementList()
    {
        delete exprL;
        delete exprR;
    }
};

#endif