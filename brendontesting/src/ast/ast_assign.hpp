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
    ExpressionPtr expr1 = NULL;
    ExpressionPtr expr2 = NULL;
public:
    AssignmentOperator(ExpressionPtr _expr1, std::string _Operator, ExpressionPtr _expr2)
        : expr1(_expr1)
        , Operator(_Operator)
        , expr2(_expr2)
    {}

    virtual std::string Compile( int &mem, std::map<std::string, std::pair<std::string, int>> g_Var, std::map<std::string, std::pair<std::string, int>> &loc_Var, std::string type_check , bool &isConstant, bool isLocal, std::vector<int> func_call) override
    {
        //  Variable declarations
            bool op1_const, op2_const;  //  Defines is numeric inputs are a constant or not
            std::string soln;           //  Formatted soln

        //  Compiled left and right nodes
            std::string op1 = expr1->Compile(mem, g_Var, loc_Var, type_check, isConstant, isLocal, func_call);
            op1_const = isConstant;
            std::string op2 = expr2->Compile(mem, g_Var, loc_Var, type_check, isConstant, isLocal, func_call);
            op2_const = isConstant;
        
        if (Operator == "=")
        {
            if(!op1_const && !op2_const)        //  Both variables 
            {
                soln += "lw $3 " + loc_Var[op1].first + "($fp)\nlw $3 " + loc_Var[op2].first + "($fp)\nnop\n";
            }
            else if(!op1_const && op2_const)   //  Assigned to variable
            {}
            /*else((!op1_const) && op2_const)   //  first is numeric
            {
                
            }*/

        }
    }
};

#endif
