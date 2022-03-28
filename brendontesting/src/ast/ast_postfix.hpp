#ifndef ast_postfix_hpp
#define ast_postfix_hpp

#include <string>
#include <iostream>
#include <cmath>

class postfix
    : public Expression
{
protected:
    int type;
    std::string operand;
    ExpressionPtr expr1 = NULL;
    ExpressionPtr expr2 = NULL;
public:
    postfix(int _type, ExpressionPtr _expr1)
        : type(_type)
        , expr1(_expr1)
    {}

    postfix(int _type, ExpressionPtr _expr1, ExpressionPtr _expr2)
        : type(_type)
        , expr1(_expr1)
        , expr2(_expr2)
    {}

    postfix(int _type, ExpressionPtr _expr1, std::string _operand, ExpressionPtr _expr2)
        : type(_type)
        , expr1(_expr1)
        , operand(_operand)
        , expr2(_expr2)
    {}

    postfix(int _type, ExpressionPtr _expr1, std::string _operand)
        : type(_type)
        , expr1(_expr1)
        , operand(_operand)
    {}

    virtual std::string Compile( int &mem, std::map<std::string, std::pair<std::string, int>> g_Var, std::map<std::string, std::pair<std::string, int>> &loc_Var, std::string type_check , bool &isConstant, bool isLocal, std::vector<int> func_call) override
    {
        std::string soln;
        if (expr2 == NULL)
        {
            if (type == 0)          {}
            else if (type == 1) //  Traditional funciton call, type and expression
            {
                std::string func_ = expr1->Compile(mem, g_Var, loc_Var, type_check, isConstant, isLocal, func_call);
                int index = func_.length() - 1; // last character
                while (index != 0 && !isspace(func_[index]))
                {
                  --index;
                }
                std::string func_name = func_.substr(index); // +1 to skip leading space

                soln = "jal " + func_name + "\nnop\n";
                mem += 4;
                soln += "sw $2, " + std::to_string(mem) + "($fp)\n";
            }
            else if (type == 2)     {}
            else if (type == 3)     {}
            
        }
        else {}
        return soln;
    }

    virtual ~postfix() { delete expr1; delete expr2; }
};

#endif
