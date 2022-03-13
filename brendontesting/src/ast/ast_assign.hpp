#ifndef ast_assign_hpp
#define ast_assign_hpp

#include <string>
#include <iostream>
#include <cmath>

class AssignmentOperator
    : public Expression
{
protected:
    std::string Operator;
public:
    AssignmentOperator(std::string _Operator)
        : Operator(_Operator)
    {}

    virtual std::string Compile( std::string current_func, int mem, std::map<std::string, std::string> g_Var, std::map<std::string, bool> reg_available, std::string type_check ) override
    {
        return "AssignmentOperator";
    }
};

#endif
