#ifndef ast_primitives_hpp
#define ast_primitives_hpp

#include <string>
#include <iostream>
#include <cmath>

class Variable
    : public Expression
{
protected:
    std::string id;
public:
    Variable(const std::string &_id)
        : id(_id)
    {
        std::cout<<"<<<<<<<<<<<<<<<< new variable! " << id << " >>>>>>>>>>>>>>>>>" << std::endl;
    }
    
    virtual std::string getID() const { return id; }
    
};

class IdentifierList
    : public Expression
{
protected:
    ExpressionPtr expr;
    std::string id;
public:
    IdentifierList(ExpressionPtr _expr, const std::string &_id)
        : expr(_expr)
        , id(_id)
    {}
    IdentifierList(const std::string &_id)
        : id(_id)
    {}

    virtual ~IdentifierList() { delete expr; }
};


class Integer
    : public Expression
{
protected:
    int value;
public:
    Integer(int _value)
        : value(_value)
    {}

    virtual int getVAL() const { return value;}
};

class Double
    : public Expression
{
protected:
    double value;
public:
    Double(int _value)
        : value(_value)
    {}

    virtual double getVAL() const { return value;}
};

class Float
    : public Expression
{
protected:
    float value;
public:
    Float(int _value)
        : value(_value)
    {}

    virtual float getVAL() const { return value;}
};

#endif