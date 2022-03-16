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

    virtual std::string Compile( int &mem, std::map<std::string, std::pair<std::string, double>> g_Var, std::map<std::string, std::pair<std::string, double>> loc_Var, std::string type_check , bool &isConstant) override
    {
        return "AssignmentOperator";
    }
};

#endif
