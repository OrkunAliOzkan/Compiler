#ifndef ast_unary_hpp
#define ast_unary_hpp

#include <string>
#include <iostream>
#include <cmath>

class UnaryOperator
    : public Expression
{
protected:
    int type;
public:
    UnaryOperator(int _type)
        : type(_type)
    {}

    virtual std::string Compile( int &mem, std::map<std::string, std::pair<std::string, int>> g_Var, std::map<std::string, std::pair<std::string, int>> &loc_Var, std::string type_check , bool &isConstant, bool isLocal, std::vector<int> func_call) override
    {
        std::string soln;
        switch(type)
        {
            case(0):
                soln += "0";
                break;
            case(1):
                soln += "1";
                break;
            case(2):
                soln += "2";
                break;
            case(3):
                soln += "3";
                break;
            case(4):
                soln += "4";
                break;
            case(5):
                soln += "5";
                break;
        }
        return soln;
    }

    virtual ~UnaryOperator() {}
};

class Unary
    : public Expression
{
protected:
    int type;
    ExpressionPtr expr1 = NULL;
    ExpressionPtr expr2 = NULL;
public:
    Unary(int _type, ExpressionPtr _expr1)
        : type(_type)
        , expr1(_expr1)
    {}

    Unary(ExpressionPtr _expr1, ExpressionPtr _expr2)
        : expr1(_expr1)
        , expr2(_expr2)
    {}

    virtual std::string Compile( int &mem, std::map<std::string, std::pair<std::string, int>> g_Var, std::map<std::string, std::pair<std::string, int>> &loc_Var, std::string type_check , bool &isConstant, bool isLocal, std::vector<int> func_call) override
    {

        std::string soln;
        if (expr2 == NULL)
        {
            if (type == 0)          {}
            else if (type == 1)     {}
            else if (type == 2)     {}
            else if (type == 3)     {}
        }
        else
        {
            int unary_operator = std::stoi(expr1->Compile(mem, g_Var, loc_Var, type_check, isConstant, isLocal, func_call));
            switch(unary_operator)
            {
                
                case(0):
                    soln += "";
                    break;
                case(1):
                    soln += "";
                    break;
                case(2):
                    soln += "";
                    break;
                case(3):
                    soln += "";
                    break;
                case(4):
                    soln += "";
                    break;
                case(5):
                    soln += "";
                    break;
            }
            return soln;
        }
    }

    virtual ~Unary() { delete expr1; delete expr2; }
};

#endif
