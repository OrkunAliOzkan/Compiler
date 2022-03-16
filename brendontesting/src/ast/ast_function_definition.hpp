#ifndef ast_function_definition_hpp
#define ast_function_definition_hpp

#include <string>
#include <iostream>
#include <cmath>

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

    virtual std::string Compile( int &mem, std::map<std::string, std::pair<std::string, int>> g_Var, std::map<std::string, std::pair<std::string, int>> loc_Var, std::string type_check , bool &isConstant, bool isLocal) override
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
                    mem = 4;
                    std::string contents = expr3->Compile(mem, g_Var, loc_Var, type_check, isConstant, 1);   //  contents of foo

                    int mem_used;
                    if (mem == 4)   { mem_used = -8; }
                    else            { mem_used = -24 - 8*(int( mem / 8 ) - 1); }

                    std::string func_name = expr2->Compile(mem, g_Var, loc_Var, type_check, isConstant, 1);
                    std::string beginning = func_name + ":\n";
                    beginning += "\taddiu $sp, $sp, " + std::to_string(mem_used) + "\n";
                    beginning += "\tsw $fp, " + std::to_string(-1*mem_used - 4) + "($sp)\n";
                    beginning += "\tmove $fp, $sp\n";

                    std::string ending;
                    std::string type_specifiers (expr1->Compile(mem, g_Var, loc_Var, type_check , isConstant, 1));
                    
                    if( type_specifiers.find("void") != std::string::npos )   { ending += "\tnop\n"; }

                    ending += "move $sp, $fp\n";
                    ending += "\tlw $fp, " + std::to_string(-1*mem_used - 4) + "($sp)\n";
                    ending += "\taddiu $sp, $sp, " + std::to_string(-1*mem_used) + "\n";;
                    ending += "\tj $31\n";
                    ending += "\tnop\n";

                    //return beginning + contents + ending;
                    return beginning + '\t' + contents + ending;
                }
                else //Parameters Function called
                {
                     return "Not implemented";
                }
            }

        }
        else{ //Parameters declared
            return "Not implemented";
        }
    }

    virtual ~FunctionDefinition()
    { delete expr1; delete expr2; delete expr3; delete expr4; }
};

#endif
