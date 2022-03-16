#ifndef ast_pointer_hpp
#define ast_pointer_hpp

#include <string>
#include <iostream>
#include <cmath>

class pointer
    : public Expression
{
protected:
    ExpressionPtr exprL = NULL;
    ExpressionPtr exprR = NULL;
public:
    pointer(ExpressionPtr _exprL, ExpressionPtr _exprR)
        : exprL(_exprL)
        , exprR(_exprR)
    {}

    pointer(ExpressionPtr _exprL)
        : exprL(_exprL)
    {}

    pointer()
    {}

    virtual std::string Compile( int &mem, std::map<std::string, std::pair<std::string, double>> g_Var, std::map<std::string, std::pair<std::string, double>> loc_Var, std::string type_check , bool &isConstant) override
    {
        return "pointer";
    }

    virtual ~pointer()
    {
        delete exprL;
        delete exprR;
    }
};

#endif