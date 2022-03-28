#ifndef ast_jump_statement_hpp
#define ast_jump_statement_hpp

#include <string>
#include <iostream>
#include <cmath>
#include <map>

class JumpStatement
    : public Expression
{
protected:
    int Type;
    std::string ident;
    ExpressionPtr expr = NULL;
public:
    JumpStatement(int _Type, std::string _ident)
        : Type(_Type)
        , ident(_ident)
    {}
    JumpStatement(int _Type, ExpressionPtr _expr)
        : Type(_Type)
        , expr(_expr)
    {}
    JumpStatement(int _Type)
        : Type(_Type)
    {}

    virtual std::string Compile( int &mem, std::map<std::string, std::pair<std::string, int>> g_Var, std::map<std::string, std::pair<std::string, int>> &loc_Var, std::string type_check , bool &isConstant, bool isLocal, std::vector<int>func_call) override
    {
        std::string soln;
        if (Type == 1)              {;}
        else if (Type == 2)         {;}
        else if (Type == 3)         {;}
        else if (Type == 4)         { soln += "nop\nnop\n"; }
        else if (Type == 5)
        {
            std::string to_return = expr->Compile(mem, g_Var, loc_Var, type_check, isConstant, isLocal, func_call);
            
            if (isConstant)                         { soln += "li $2, " + to_return + '\n'; }
            else if ( loc_Var.count(to_return) )    { soln += "lw $2, " + std::to_string(loc_Var[to_return].second) + "($fp)" + "\n"; }
            else { soln += to_return; }
        }
        return soln;
    }

    virtual ~JumpStatement()
    { delete expr; }
};

#endif
