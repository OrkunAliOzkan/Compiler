#ifndef ast_declare_hpp
#define ast_declare_hpp

#include <string>
#include <iostream>
#include <cmath>

class Declarator
    : public Expression
{
protected:
    ExpressionPtr exprL = NULL;
    ExpressionPtr exprR = NULL;
public:
    Declarator(ExpressionPtr _exprL, ExpressionPtr _exprR)
        : exprL(_exprL)
        , exprR(_exprR)
    {}

    virtual ~Declarator()
    {
        delete exprL;
        delete exprR;
    }

    virtual std::string Compile( int &mem, std::map<std::string, std::pair<std::string, int>> g_Var, std::map<std::string, std::pair<std::string, int>> &loc_Var, std::string type_check , bool &isConstant, bool isLocal, std::vector<int> func_call) override
    {
        return "declarator";
    }
};

class Declaration_Spec
    : public Expression
{
protected:
    std::string type;
    ExpressionPtr exprL = NULL;
    ExpressionPtr exprR = NULL;
public:
    Declaration_Spec(std::string _type, ExpressionPtr _left, ExpressionPtr _right)
        : type(_type)
        , exprL(_left)
        , exprR(_right)
    {}
    Declaration_Spec(std::string _type, ExpressionPtr _left)
        : type(_type)
        , exprL(_left)
    {}

    // VOID, CHAR, INT, LONG ETC.
    // EXTERN TYPEDEF STATIC AUTO REGISTER
    // CONST VOLATILE

    virtual std::string Compile( int &mem, std::map<std::string, std::pair<std::string, int>> g_Var, std::map<std::string, std::pair<std::string, int>> &loc_Var, std::string type_check , bool &isConstant, bool isLocal, std::vector<int> func_call) override
    {
        if (exprR == NULL)  { return exprL->Compile(mem, g_Var, loc_Var, type_check, isConstant, isLocal, func_call); }
        else { return exprL->Compile(mem, g_Var, loc_Var, type_check, isConstant, isLocal, func_call) + " " + exprR->Compile(mem, g_Var, loc_Var, type_check, isConstant, isLocal, func_call); }
    }

    virtual ~Declaration_Spec()
    {
        delete exprL;
        delete exprR;
    }
};

class DirectDeclarator
    : public Expression
{
protected:
    int Type;
    std::string ident;
    ExpressionPtr exprL = NULL;
    ExpressionPtr exprR = NULL;
public:
    DirectDeclarator(int _Type, std::string _ident, ExpressionPtr _exprL, ExpressionPtr _exprR)
        : Type(_Type)
        , ident(_ident)
        , exprL(_exprL)
        , exprR(_exprR)
    {}

    DirectDeclarator(int _Type, std::string _ident)
        : Type(_Type)
        , ident(_ident)
    {}

    DirectDeclarator(int _Type, ExpressionPtr _exprL )
        : Type(_Type)
        , exprL(_exprL)
    {}

        DirectDeclarator(int _Type, ExpressionPtr _exprL, ExpressionPtr _exprR)
        : Type(_Type)
        , exprL(_exprL)
        , exprR(_exprR)
    {}

    virtual std::string Compile( int &mem, std::map<std::string, std::pair<std::string, int>> g_Var, std::map<std::string, std::pair<std::string, int>> &loc_Var, std::string type_check , bool &isConstant, bool isLocal, std::vector<int> func_call) override
    {
        if          (Type == 0) { return ident; } // For direct_declarator -> IDENTIFIER
        else if     (Type == 1) { return "NOT IMPLEMENTED"; }
        else if     (Type == 2) { return "NOT IMPLEMENTED"; }
        else if     (Type == 3) { return "NOT IMPLEMENTED"; }
        else if     (Type == 4) { return "NOT IMPLEMENTED"; }
        else if     (Type == 5) { return "NOT IMPLEMENTED"; }
        else
        { 
            std::string func_name = exprL->Compile(mem, g_Var, loc_Var, type_check, isConstant, 1, func_call);

            std::string beginning = func_name + ":\n";
            beginning += "addiu $sp, $sp, " + std::to_string(mem) + "\n";
            beginning += "sw $fp, " + std::to_string(-1*mem - 4) + "($sp)\n";
            beginning += "move $fp, $sp\n";

            return beginning; 
        }
    }

    virtual ~DirectDeclarator()
    {
        delete exprL;
        delete exprR;
    }
};

class Init_Declarator
    : public Expression
{
protected:
    ExpressionPtr exprL = NULL;
    ExpressionPtr exprR = NULL;
public:
    Init_Declarator(ExpressionPtr _exprL, ExpressionPtr _exprR)
        : exprL(_exprL)
        , exprR(_exprR)
    {}
    Init_Declarator(ExpressionPtr _exprL)
        : exprL(_exprL)
    {}

    virtual std::string Compile( int &mem, std::map<std::string, std::pair<std::string, int>> g_Var, std::map<std::string, std::pair<std::string, int>> &loc_Var, std::string type_check , bool &isConstant, bool isLocal, std::vector<int> func_call) override
    {
        /*
            Only appears to be called when declaring.
            This function can return:
                x = 4
                x = y
                x = 4 + 3
                x = 4 + y
                x = y + z
                x
                or a pointer = 
                or a list = 
                or an array =
                or by themselves. 
        */

        if ( exprR == NULL)
        {
            // This is when there is no equals sign. No initialisation.

            //For now just assume that we are doing something like int x; Doesnt actually do anyting.

            //if(isLocal, func_call)     { loc_Var[ exprL->Compile(mem, g_Var, loc_Var, type_check, isConstant, isLocal, func_call) ] = std::make_pair(, 'c'); }
            //else            {}

            return "";
        }
        else
        {
            std::string var_name = exprL->Compile(mem, g_Var, loc_Var, type_check, isConstant, isLocal, func_call);
            std::string evaluation = exprR->Compile(mem, g_Var, loc_Var, type_check, isConstant, isLocal, func_call);

            if (type_check == "int")
            {
                if(isConstant)
                {
                    mem += 4;
                    std::string def_int;
                    if (evaluation == "0") { def_int += "sw $0, " + std::to_string(mem) + "($fp)" + '\n'; }
                    else
                    {
                        def_int += "li $2, " + evaluation + '\n' ;   //  loading the evaluation into reg 2
                        def_int += "sw $2, " + std::to_string(mem) + "($fp)" + '\n';     //  Store $2 into memory location where @
                    }

                    //Adding to map of values.
                    if(isLocal)     { loc_Var[var_name] = std::make_pair("int", mem); }
                    else            { g_Var[var_name] = std::make_pair("int", mem); }

                    return def_int;
                }
                else
                {
                    mem += 4;
                    std::string def_int;

                    def_int += evaluation;
                    def_int += "sw $2, " + std::to_string(mem) + "($fp)" + '\n';     //  Store $2 into memory location where @

                    return def_int;
                }
            }
            else { return "not implemented"; }
        }
    }

    virtual ~Init_Declarator()
    {
        delete exprL;
        delete exprR;
    }
};

class Init_Declarator_List
    : public Expression
{
protected:
    ExpressionPtr exprL = NULL;
    ExpressionPtr exprR = NULL;
public:
    Init_Declarator_List(ExpressionPtr _exprL, ExpressionPtr _exprR)
        : exprL(_exprL)
        , exprR(_exprR)
    {}

    virtual std::string Compile( int &mem, std::map<std::string, std::pair<std::string, int>> g_Var, std::map<std::string, std::pair<std::string, int>> &loc_Var, std::string type_check , bool &isConstant, bool isLocal, std::vector<int> func_call) override
    {
        std::string L = exprL->Compile(mem, g_Var, loc_Var, type_check, isConstant, isLocal, func_call);
        std::string R = exprR->Compile(mem, g_Var, loc_Var, type_check, isConstant, isLocal, func_call);
        return L + R;
    }

    virtual ~Init_Declarator_List()
    {
        delete exprL;
        delete exprR;
    }
};

class Declaration
    : public Expression
{
protected:
    ExpressionPtr exprL = NULL;
    ExpressionPtr exprR = NULL;
public:
    Declaration(ExpressionPtr _exprL, ExpressionPtr _exprR)
        : exprL(_exprL)
        , exprR(_exprR)
    {}

    virtual std::string Compile( int &mem, std::map<std::string, std::pair<std::string, int>> g_Var, std::map<std::string, std::pair<std::string, int>> &loc_Var, std::string type_check , bool &isConstant, bool isLocal, std::vector<int> func_call) override
    {
        /* This function is for:
            int x;
            int x = 4;
            long int x = anything;
            etc
        */

        // First find the Declaration specifiers: This will return int, void, long int, etc.
        std::string type = exprL->Compile(mem, g_Var, loc_Var, type_check, isConstant, isLocal, func_call);

        //Then evaluate the right hand side with the specific type.
        if( type.find("void") != std::string::npos )                { return exprR->Compile(mem, g_Var, loc_Var, "void", isConstant, isLocal, func_call); }
        else if ( type.find("char") != std::string::npos )          { return exprR->Compile(mem, g_Var, loc_Var, "char", isConstant, isLocal, func_call); }
        else if ( type.find("short") != std::string::npos )         { return exprR->Compile(mem, g_Var, loc_Var, "short", isConstant, isLocal, func_call); }
        else if ( type.find("int") != std::string::npos )           { return exprR->Compile(mem, g_Var, loc_Var, "int", isConstant, isLocal, func_call); }
        else if ( type.find("long") != std::string::npos )          { return exprR->Compile(mem, g_Var, loc_Var, "long", isConstant, isLocal, func_call); }
        else if ( type.find("float") != std::string::npos )         { return exprR->Compile(mem, g_Var, loc_Var, "float", isConstant, isLocal, func_call); }
        else if ( type.find("double") != std::string::npos )        { return exprR->Compile(mem, g_Var, loc_Var, "double", isConstant, isLocal, func_call); }
        else if ( type.find("signed") != std::string::npos )        { return exprR->Compile(mem, g_Var, loc_Var, "signed", isConstant, isLocal, func_call); }
        else if ( type.find("unsigned") != std::string::npos )      { return exprR->Compile(mem, g_Var, loc_Var, "unsigned", isConstant, isLocal, func_call); }
        else                                                        { return "not implemented"; }
    }

    virtual ~Declaration()
    {
        delete exprL;
        delete exprR;
    }
};

class DirectAbstractDeclarator
    : public Expression
{
protected:
    int Type;
    ExpressionPtr expr1 = NULL;
    ExpressionPtr expr2 = NULL;
public:
    DirectAbstractDeclarator(int _Type, ExpressionPtr _expr1, ExpressionPtr _expr2)
        : Type(_Type)
        , expr1(_expr1)
        , expr2(_expr2)
    {}
    DirectAbstractDeclarator(int _Type, ExpressionPtr _expr1)
        : Type(_Type)
        , expr1(_expr1)
    {}
    DirectAbstractDeclarator(int _Type)
        : Type(_Type)
    {}

    virtual std::string Compile( int &mem, std::map<std::string, std::pair<std::string, int>> g_Var, std::map<std::string, std::pair<std::string, int>> &loc_Var, std::string type_check , bool &isConstant, bool isLocal, std::vector<int> func_call) override
    {
        return "DirectAbstractDeclarator!\n";
    }

    virtual ~DirectAbstractDeclarator() { delete expr1; delete expr2; }
};

class AbstractDeclarator
    : public Expression
{
protected:
    ExpressionPtr exprL = NULL;
    ExpressionPtr exprR = NULL;
public:
    AbstractDeclarator(ExpressionPtr _exprL, ExpressionPtr _exprR)
        : exprL(_exprL)
        , exprR(_exprR)
    {}

    virtual std::string Compile( int &mem, std::map<std::string, std::pair<std::string, int>> g_Var, std::map<std::string, std::pair<std::string, int>> &loc_Var, std::string type_check , bool &isConstant, bool isLocal, std::vector<int> func_call) override
    {
        return "AbstractDeclarator!\n";
    }

    virtual ~AbstractDeclarator() { delete exprL; delete exprR; }
};

#endif
