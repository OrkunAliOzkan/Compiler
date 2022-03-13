#ifndef ast_jump_statement_hpp
#define ast_jump_statement_hpp

#include <string>
#include <iostream>
#include <cmath>

class JumpStatement
    : public Expression
{
protected:
    int Type;
    std::string ident;
    ExpressionPtr expr;
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

    virtual ~JumpStatement()
    { delete expr; }
};

#endif
