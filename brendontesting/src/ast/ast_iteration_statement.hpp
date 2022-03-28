#ifndef ast_iteration_statement_hpp
#define ast_iteration_statement_hpp

#include <string>
#include <iostream>
#include <cmath>

class IterationStatement
    : public Expression
{
protected:
    int Type;
    ExpressionPtr expr1 = NULL;
    ExpressionPtr expr2 = NULL;
    ExpressionPtr expr3 = NULL;
public:
    IterationStatement(int _Type, ExpressionPtr _expr1, ExpressionPtr _expr2, ExpressionPtr _expr3)
        : Type(_Type)
        , expr1(_expr1)
        , expr2(_expr2)
        , expr3(_expr3)
    {}
    IterationStatement(int _Type, ExpressionPtr _expr1, ExpressionPtr _expr2)
        : Type(_Type)
        , expr1(_expr1)
        , expr2(_expr2)
    {}

    virtual ~IterationStatement()
    {
        delete expr1;
        delete expr2;
        delete expr3;
    }


    virtual std::string Compile( int &mem, std::map<std::string, std::pair<std::string, int>> g_Var, std::map<std::string, std::pair<std::string, int>> &loc_Var, std::string type_check , bool &isConstant, bool isLocal, std::vector<int> func_call) override
    {
        
        if(Type == 0)
        {
        //  While loop #1: 	: WHILE '(' expression ')' statement
            //  Variable declaration
                std::string soln = "";           //  Formatted soln
            //  Compiling of left and right nodes
                std::string condition = expr1->Compile(mem, g_Var, loc_Var, type_check, isConstant, isLocal, func_call);
                std::string eval      = expr2->Compile(mem, g_Var, loc_Var, type_check, isConstant, isLocal, func_call);
            //  While loop generation:
                //  TODO:   Implement infinite loop!
                //  Case #1: Infinite loop
                    if(condition == "1")
                    {
                    soln += "$L2:\n";
                    soln += eval;
                    soln += "\n";
                    }
                //  Case #2: Non loop
                    else if(condition == "-1")
                    {
                        soln += "nop\n";
                    }
                //  Case #3: Not infinite loop
                    else
                    {
                        soln += "b $L2\nnop\n$L3:\n";   //  Initialise the while
                        soln += eval;                    //  Code
                        soln += "\n$L2:\n";             //  Conditional declaration
                        soln += condition;                    //  Conditional code
                        soln += "\n";
                    }  
                return soln;
        }
        std::cout << "egg\n" << std::endl;

    } 

};

#endif
