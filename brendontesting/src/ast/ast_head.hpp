#ifndef ast_head_hpp
#define ast_head_hpp

#include <string>
#include <iostream>
#include <cmath>

class HeadNode
    : public Expression
{
protected:
    ExpressionPtr child = NULL;
public:
    HeadNode(ExpressionPtr _child)
        : child(_child)
    {}

    virtual std::string Compile( int &mem, std::map<std::string, std::pair<std::string, double>> g_Var, std::map<std::string, std::pair<std::string, double>> loc_Var, std::string type_check , bool &isConstant) override
    {
        return child->Compile(mem, g_Var, loc_Var, type_check, isConstant);
    }

    virtual void AtLocation() override { std::cout << "In Head Node" << std::endl; child->AtLocation(); }

    virtual ~HeadNode() { delete child; }
};

#endif