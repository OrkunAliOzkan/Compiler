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
    Variable(std::string _id)
        : id(_id)
    {}
    
    virtual std::string getID() const { return id; }
    
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