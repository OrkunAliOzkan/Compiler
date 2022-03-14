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

    virtual std::string Compile( std::string current_func, int mem, std::map<std::string, std::string> g_Var, std::map<std::string, bool> reg_available, std::string type_check ) override
    {
        return child->Compile(current_func, mem, g_Var, reg_available, type_check);
    }

    virtual void AtLocation() override { std::cout << "In Head Node" << std::endl; child->AtLocation(); }

    virtual ~HeadNode() { delete child; }
};

#endif