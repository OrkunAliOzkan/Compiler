#ifndef ast_expression_statement_hpp
#define ast_expression_statement_hpp

#include <string>
#include <iostream>
#include <cmath>

class ExpressionStatement
    : public Expression
{
protected:
    ExpressionPtr expr = NULL;
public:
    ExpressionStatement()
    {}
    ExpressionStatement(ExpressionPtr _expr)
        : expr(_expr)
    {}

    virtual std::string Compile( int &mem, std::map<std::string, std::pair<std::string, double>> g_Var, std::map<std::string, std::pair<std::string, double>> loc_Var, std::string type_check , bool &isConstant) override
    {
        return "ExpressionStatement";
    }

    virtual ~ExpressionStatement() { delete expr; }
};

#endif