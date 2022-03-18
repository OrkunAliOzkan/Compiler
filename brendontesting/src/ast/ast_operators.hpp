#ifndef ast_operators_hpp
#define ast_operators_hpp

#include <string>
#include <iostream>
#include <cmath>

class Operator
    : public Expression
{
protected:
    ExpressionPtr left  = NULL;
    ExpressionPtr right = NULL;
public:
    Operator(ExpressionPtr _left, ExpressionPtr _right)
        : left(_left)
        , right(_right)
    {}

    virtual ~Operator()
    {
        delete left;
        delete right;
    }
};

class AddOperator
    : public Operator
{
public:
    AddOperator(ExpressionPtr _left, ExpressionPtr _right)
        : Operator(_left, _right)
    {}

    virtual std::string Compile( int &mem, std::map<std::string, std::pair<std::string, int>> g_Var, std::map<std::string, std::pair<std::string, int>> &loc_Var, std::string type_check , bool &isConstant, bool isLocal) override
    {
        bool op1_const, op2_const;
        std::string soln;    //  Is formatted soln
        std::string op1 = left->Compile(mem, g_Var, loc_Var, type_check, isConstant, isLocal);
        op1_const = isConstant;
        std::string op2 = right->Compile(mem, g_Var, loc_Var, type_check, isConstant, isLocal);
        op2_const = isConstant;

        if ( op1_const & op2_const )
        {
            std::cout<< "2 ints" << std::endl;
            if (type_check == "int")    
            {
                int result = std::stoi(op1) + std::stoi(op2);
                isConstant = 1;
                return std::to_string(result);
            }
        }
        else if ( !(op1_const) & !(op2_const) )
        {
            //std::cout<< "2 var" << std::endl;
            if (type_check == "int")    
            { 
                soln += "lw $3, " + std::to_string(loc_Var[op1].second) + "($fp)" + "\n";
                soln += "lw $2, " + std::to_string(loc_Var[op2].second) + "($fp)" + "\n";
                soln += "nop\naddu $2,$3,$2\n";
                isConstant = 0;
                return soln;
            }
        }
        else
        {
            //std::cout<< "1 var" << std::endl;
            if (type_check == "int")    
            {
                if (op1_const)
                {  
                    soln += "lw $2, " + std::to_string(loc_Var[op2].second) + "($fp)" + "\n";
                    soln += "nop\naddu $2,$2," + op1 + '\n';
                    isConstant = 0;
                }
                else
                {
                    soln += "lw $2, " + std::to_string(loc_Var[op1].second) + "($fp)" + "\n";
                    soln += "nop\naddiu $2,$2," + op2 + '\n';
                }
                isConstant = 0;
                return soln;
            } 
        } 
    }
};

class SubOperator
    : public Operator
{
public:
    SubOperator(ExpressionPtr _left, ExpressionPtr _right)
        : Operator(_left, _right)
    {}

    virtual std::string Compile( int &mem, std::map<std::string, std::pair<std::string, int>> g_Var, std::map<std::string, std::pair<std::string, int>> &loc_Var, std::string type_check , bool &isConstant, bool isLocal) override
    {
        bool op1_const, op2_const;
        std::string soln;    //  Is formatted soln
        std::string op1 = left->Compile(mem, g_Var, loc_Var, type_check, isConstant, isLocal);
        op1_const = isConstant;
        std::string op2 = right->Compile(mem, g_Var, loc_Var, type_check, isConstant, isLocal);
        op2_const = isConstant;

        if ( op1_const & op2_const )
        {
            std::cout<< "2 ints" << std::endl;
            if (type_check == "int")    
            {
                int result = std::stoi(op1) - std::stoi(op2);
                isConstant = 1;
                return std::to_string(result);
            }
        }
        else if ( !(op1_const) & !(op2_const) )
        {
            if (type_check == "int")    
            { 
                soln += "lw $3, " + std::to_string(loc_Var[op1].second) + "($fp)" + "\n";
                soln += "lw $2, " + std::to_string(loc_Var[op2].second) + "($fp)" + "\n";
                soln += "nop\nsubu $2,$3,$2\n";
                isConstant = 0;
                return soln;
            }
        }
        else
        {
            if (type_check == "int")    
            {
                if (op1_const)
                {  
                    soln += "lw $2, " + std::to_string(loc_Var[op2].second) + "($fp)" + "\n";
                    soln += "nop\nsubu $2,$2," + op1 + '\n';
                    isConstant = 0;
                }
                else
                {
                    soln += "lw $2, " + std::to_string(loc_Var[op1].second) + "($fp)" + "\n";
                    soln += "nop\nsubu $2,$2," + op2 + '\n';
                }
                isConstant = 0;
                return soln;
            } 
        } 
    }
};


class MulOperator
    : public Operator
{
public:
    MulOperator(ExpressionPtr _left, ExpressionPtr _right)
        : Operator(_left, _right)
    {}
};

class DivOperator
    : public Operator
{
public:
    DivOperator(ExpressionPtr _left, ExpressionPtr _right)
        : Operator(_left, _right)
    {}
};

class ModOperator
    : public Operator
{
public:
    ModOperator(ExpressionPtr _left, ExpressionPtr _right)
        : Operator(_left, _right)
    {}

};

class OrOperator
    : public Operator
{
public:
    OrOperator(ExpressionPtr _left, ExpressionPtr _right)
        : Operator(_left, _right)
    {}

    virtual std::string Compile( int &mem, std::map<std::string, std::pair<std::string, int>> g_Var, std::map<std::string, std::pair<std::string, int>> &loc_Var, std::string type_check , bool &isConstant, bool isLocal) override
    {
        bool op1_const, op2_const;
        std::string soln;    //  Is formatted soln
        std::string op1 = left->Compile(mem, g_Var, loc_Var, type_check, isConstant, isLocal);
        op1_const = isConstant;
        std::string op2 = right->Compile(mem, g_Var, loc_Var, type_check, isConstant, isLocal);
        op2_const = isConstant;

        if ( op1_const & op2_const )
        {
            if (type_check == "int")    
            {
                int result = std::stoi(op1) - std::stoi(op2);
                isConstant = 1;
                return std::to_string(result);
            }
        }
        else if ( !(op1_const) & !(op2_const) )
        {
            if (type_check == "int")    
            { 
                soln += "lw $3, " + std::to_string(loc_Var[op1].second) + "($fp)" + "\n";
                soln += "lw $2, " + std::to_string(loc_Var[op2].second) + "($fp)" + "\n";
                soln += "nop\nand $2,$3,$2\n";
                isConstant = 0;
                return soln;
            }
        }
        else
        {
            if (type_check == "int")    
            {
                if (op1_const)
                {  
                    soln += "lw $2, " + std::to_string(loc_Var[op2].second) + "($fp)" + "\n";
                    soln += "nop\nandi $2,$2," + op1 + '\n';
                    isConstant = 0;
                }
                else
                {
                    soln += "lw $2, " + std::to_string(loc_Var[op1].second) + "($fp)" + "\n";
                    soln += "nop\nandi $2,$2," + op2 + '\n';
                }
                isConstant = 0;
                return soln;
            } 
        } 
    }
};

class bOrOperator
    : public Operator
{
public:
    bOrOperator(ExpressionPtr _left, ExpressionPtr _right)
        : Operator(_left, _right)
    {}
};

class AndOperator
    : public Operator
{
public:
    AndOperator(ExpressionPtr _left, ExpressionPtr _right)
        : Operator(_left, _right)
    {}
};

class bAndOperator
    : public Operator
{
public:
    bAndOperator(ExpressionPtr _left, ExpressionPtr _right)
        : Operator(_left, _right)
    {}
  virtual std::string Compile( int &mem, std::map<std::string, std::pair<std::string, int>> g_Var, std::map<std::string, std::pair<std::string, int>> &loc_Var, std::string type_check , bool &isConstant, bool isLocal) override
    {
        bool op1_const, op2_const;
        std::string soln;    //  Is formatted soln
        std::string op1 = left->Compile(mem, g_Var, loc_Var, type_check, isConstant, isLocal);
        op1_const = isConstant;
        std::string op2 = right->Compile(mem, g_Var, loc_Var, type_check, isConstant, isLocal);
        op2_const = isConstant;

        if ( op1_const & op2_const )
        {
            if (type_check == "int")    
            {
                int result = std::stoi(op1) & std::stoi(op2);
                isConstant = 1;
                return std::to_string(result);
            }
        }
        else if ( !(op1_const) & !(op2_const) )
        {
            if (type_check == "int")    
            { 
                soln += "lw $3, " + std::to_string(loc_Var[op1].second) + "($fp)" + "\n";
                soln += "lw $2, " + std::to_string(loc_Var[op2].second) + "($fp)" + "\n";
                soln += "nop\nand $2,$3,$2\n";
                isConstant = 0;
                return soln;
            }
        }
        else
        {
            if (type_check == "int")    
            {
                if (op1_const)
                {  
                    soln += "lw $2, " + std::to_string(loc_Var[op2].second) + "($fp)" + "\n";
                    soln += "nop\nand $2,$2," + op1 + '\n';
                    isConstant = 0;
                }
                else
                {
                    soln += "lw $2, " + std::to_string(loc_Var[op1].second) + "($fp)" + "\n";
                    soln += "nop\nand $2,$2," + op2 + '\n';
                }
                isConstant = 0;
                return soln;
            } 
        }
    } 
};

class xorOperator
    : public Operator
{
public:
    xorOperator(ExpressionPtr _left, ExpressionPtr _right)
        : Operator(_left, _right)
    {}
};

class EqOperator
    : public Operator
{
public:
    EqOperator(ExpressionPtr _left, ExpressionPtr _right)
        : Operator(_left, _right)
    {}
};

class NeqOperator
    : public Operator
{
public:
    NeqOperator(ExpressionPtr _left, ExpressionPtr _right)
        : Operator(_left, _right)
    {}
};

class LTOperator
    : public Operator
{
public:
    LTOperator(ExpressionPtr _left, ExpressionPtr _right)
        : Operator(_left, _right)
    {}
};

class GTOperator
    : public Operator
{
public:
    GTOperator(ExpressionPtr _left, ExpressionPtr _right)
        : Operator(_left, _right)
    {}
};

class LEOperator
    : public Operator
{
public:
    LEOperator(ExpressionPtr _left, ExpressionPtr _right)
        : Operator(_left, _right)
    {}
};

class GEOperator
    : public Operator
{
public:
    GEOperator(ExpressionPtr _left, ExpressionPtr _right)
        : Operator(_left, _right)
    {}
};

class LShiftLeftOperator
    : public Operator
{
public:
    LShiftLeftOperator(ExpressionPtr _left, ExpressionPtr _right)
        : Operator(_left, _right)
    {}
};

class LShiftRightOperator
    : public Operator
{
public:
    LShiftRightOperator(ExpressionPtr _left, ExpressionPtr _right)
        : Operator(_left, _right) {}
};


#endif
