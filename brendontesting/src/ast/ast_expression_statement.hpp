#ifndef ast_expression_statement_hpp
#define ast_expression_statement_hpp

#include <string>
#include <iostream>
#include <cmath>

class ExpressionStatement
    : public Expression
{
protected:
    ExpressionPtr expr;
public:
    ExpressionStatement()
    {}
    ExpressionStatement(ExpressionPtr _expr)
        : expr(_expr)
    {}

    virtual std::string Compile( std::string current_func, int mem, std::map<std::string, std::string> g_Var, std::map<std::string, bool> reg_available, std::string type_check ) override
    {
        return "ExpressionStatement";
    }

    virtual ~ExpressionStatement() { delete expr; }
};

#endif