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
    {}

    virtual std::string Compile( int &mem, std::map<std::string, std::pair<std::string, int>> g_Var, std::map<std::string, std::pair<std::string, int>> loc_Var, std::string type_check , bool &isConstant, bool isLocal) override
    {
        return id;
    }    
};

class IdentifierList
    : public Expression
{
protected:
    ExpressionPtr expr = NULL;
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
    std::string value;
public:
    Integer(std::string _value)
        : value(_value)
    {}

    virtual std::string Compile( int &mem, std::map<std::string, std::pair<std::string, int>> g_Var, std::map<std::string, std::pair<std::string, int>> loc_Var, std::string type_check , bool &isConstant, bool isLocal) override
    {
        isConstant = 1;
        return value;   //  returns string
    }
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