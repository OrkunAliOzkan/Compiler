#ifndef ast_delcare_hpp
#define ast_delcare_hpp

#include <string>
#include <iostream>

class Declare
    : public Expression
{
private:
    ExpressionPtr expr;
protected:
    Declare(const ExpressionPtr _expr)
        : expr(_expr)
    {}
public:
    virtual ~Declare()
    {
        delete expr;
    }

    virtual const char *getOpcode() const =0;

    ExpressionPtr getExpr() const
    { return expr; }

    virtual void print(std::ostream &dst) const override
    {
        dst << "( ";
        dst << getOpcode();
        dst << " ";
        expr->print(dst);
        dst << " )";
    }
};

class declare_int
    : public Delcare
{
public:
    declare_int(const ExpressionPtr _expr)
        : Delcare(_expr)
    {}

    virtual const char *getOpcode() const override
    { return "int"; }

    
};

#endif
