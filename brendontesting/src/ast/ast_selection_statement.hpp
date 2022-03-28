#ifndef ast_selection_statement_hpp
#define ast_selection_statement_hpp

#include <string>
#include <iostream>
#include <cmath>

class SelectionStatement
    : public Expression
{
protected:
    ExpressionPtr statement1 = NULL;
    ExpressionPtr statement2 = NULL;
    ExpressionPtr statement3 = NULL;
    int aSwitch;
public:
    SelectionStatement(int _aSwitch, ExpressionPtr _statement1, ExpressionPtr _statement2)
        : aSwitch(_aSwitch)
        , statement1(_statement1)
        , statement2(_statement2)
    {}

    SelectionStatement(ExpressionPtr _statement1, ExpressionPtr _statement2, ExpressionPtr _statement3)
        : statement1(_statement1)
        , statement2(_statement2)
        , statement3(_statement3)
    {}

    virtual std::string Compile( int &mem, std::map<std::string, std::pair<std::string, int>> g_Var, std::map<std::string, std::pair<std::string, int>> &loc_Var, std::string type_check , bool &isConstant, bool isLocal, std::vector<int> func_call) override
    {
        if ( statement3 == NULL)
        {
            if (aSwitch) //Switch statement
            {
                return "not implemented yet";
            }
            else //IF statement
            {
                std::string condition = statement1->Compile(mem, g_Var, loc_Var, type_check, isConstant, isLocal, func_call);
                std::string eval = statement2->Compile(mem, g_Var, loc_Var, type_check, isConstant, isLocal, func_call);

                if (condition == "1")           { return eval + '\n'; } //  Infinite loop
                else if (condition == "-1")     { return ""; }          //  No loop
                else                            { return condition + '\n' + eval + "\n$L2:\n"; }
            }
        }
        else // IF-ELSE statement
        {
            std::string condition = statement1->Compile(mem, g_Var, loc_Var, type_check, isConstant, isLocal, func_call);
            std::string eval1 = statement2->Compile(mem, g_Var, loc_Var, type_check, isConstant, isLocal, func_call);
            std::string eval2 = statement3->Compile(mem, g_Var, loc_Var, type_check, isConstant, isLocal, func_call);

            if (condition == "1")           { return eval1 + '\n'; }
            else if (condition == "-1")     { return eval2 + '\n'; }
            else                            { return condition + '\n' + eval1 + "b $L3\nnop\n\n$L2:\n" + eval2 + "\n$L3:\n"; }
        }
    }

    virtual ~SelectionStatement()
    {
        delete statement1;
        delete statement2;
        delete statement3;
    }
};

#endif
