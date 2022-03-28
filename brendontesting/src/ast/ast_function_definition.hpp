#ifndef ast_function_definition_hpp
#define ast_function_definition_hpp

#include <string>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

class FunctionDefinition
    : public Expression
{
protected:
    ExpressionPtr expr1 = NULL;
    ExpressionPtr expr2 = NULL;
    ExpressionPtr expr3 = NULL;
    ExpressionPtr expr4 = NULL;
    int call;
public:
    FunctionDefinition(ExpressionPtr _expr1, ExpressionPtr _expr2, ExpressionPtr _expr3, ExpressionPtr _expr4)
        : expr1(_expr1)
        , expr2(_expr2)
        , expr3(_expr3)
        , expr4(_expr4)
    {}
    FunctionDefinition(ExpressionPtr _expr1, ExpressionPtr _expr2, ExpressionPtr _expr3, int _call)
        : expr1(_expr1)
        , expr2(_expr2)
        , expr3(_expr3)
        , call(_call)
    {}
    FunctionDefinition(ExpressionPtr _expr1, ExpressionPtr _expr2)
        : expr1(_expr1)
        , expr2(_expr2)
    {}

    virtual std::string Compile( int &mem, std::map<std::string, std::pair<std::string, int>> g_Var, std::map<std::string, std::pair<std::string, int>> &loc_Var, std::string type_check , bool &isConstant, bool isLocal, std::vector<int> func_call) override
    {
        if(expr4 == NULL)
        {
            if (expr3 == NULL) // No parameters Function called
            {
                return "Not implemented";
            }
            else 
            {
                if (call == 0) // No parameters Function Declared
                {
                    std::string type_specifiers (expr1->Compile(mem, g_Var, loc_Var, type_check , isConstant, 1, func_call));

                    if( type_specifiers.find("int") != std::string::npos )              { type_check = "int"; }
                    else if( type_specifiers.find("float") != std::string::npos )       { type_check = "float"; }

                    if( std::find(func_call.begin(), func_call.end(), 1) != func_call.begin() ) { mem = 20; }
                    else { mem = 4; }

                    std::string contents = expr3->Compile(mem, g_Var, loc_Var, type_check, isConstant, 1, func_call);   //  contents of foo

                    int mem_used;
                    if (mem == 4)   { mem_used = -8; }
                    else            { mem_used = -24 - 8*(int( mem / 8 ) - 1); }

                    std::string beginning = expr2->Compile(mem_used, g_Var, loc_Var, type_check, isConstant, 1, func_call);

                    std::string ending;
                    if( type_specifiers.find("void") != std::string::npos )   { ending += "nop\nmove $2, $0\n"; }

                    ending += "move $sp, $fp\n";
                    ending += "lw $fp, " + std::to_string(-1*mem_used - 4) + "($sp)\n";
                    ending += "addiu $sp, $sp, " + std::to_string(-1*mem_used) + "\n";;
                    ending += "j $31\n";
                    ending += "nop\n";

                    //return beginning + contents + ending;
                    return beginning + contents + ending;
                }
                else //Parameters Function called
                {
                }
            }

        }
        else //Parameters declared
        {
            std::string type_specifiers (expr1->Compile(mem, g_Var, loc_Var, type_check , isConstant, 1, func_call));
            if( type_specifiers.find("int") != std::string::npos )              { type_check = "int"; }
            else if( type_specifiers.find("float") != std::string::npos )       { type_check = "float"; }

            if( std::find(func_call.begin(), func_call.end(), 1) != func_call.begin() ) { mem = 20; }
            else { mem = 4; }

            std::string params = expr3->Compile(mem, g_Var, loc_Var, type_check, isConstant, 1, func_call);   //  params of foo
            std::string contents = expr4->Compile(mem, g_Var, loc_Var, type_check, isConstant, 1, func_call);   //  contents of foo

            int mem_used;
            if (mem == 4)   { mem_used = -8; }
            else            { mem_used = -24 - 8*(int( mem / 8 ) - 1); }

            std::string func_name = expr2->Compile(mem, g_Var, loc_Var, type_check, isConstant, 1, func_call);
            std::string beginning = func_name + ":\n";
            beginning += "addiu $sp, $sp, " + std::to_string(mem_used) + "\n";
            beginning += "sw $fp, " + std::to_string(-1*mem_used - 4) + "($sp)\n";
            beginning += "move $fp, $sp\n";

            /*
            if (params == "1")          { beginning += "sw $4, " + std::to_string(-1*mem_used) + "($fp)"; }
            else if (params == "2")     { beginning += "sw $4, " + std::to_string(-1*mem_used) + "($fp)"; }
            else if (params == "3")     {}
            else if (params == "4")     {}
            else if (params == ">4")    {}
            */

            std::string ending;
            
            if( type_specifiers.find("void") != std::string::npos )   { ending += "nop\nmove $2, $0\n"; }

            ending += "move $sp, $fp\n";
            ending += "lw $fp, " + std::to_string(-1*mem_used - 4) + "($sp)\n";
            ending += "addiu $sp, $sp, " + std::to_string(-1*mem_used) + "\n";;
            ending += "j $31\n";
            ending += "nop\n";

            //return beginning + contents + ending;
            return beginning + contents + ending;
        }
    }

    virtual ~FunctionDefinition()
    { delete expr1; delete expr2; delete expr3; delete expr4; }
};

#endif
