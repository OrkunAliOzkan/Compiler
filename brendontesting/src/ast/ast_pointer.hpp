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

    virtual std::string Compile( int &mem, std::map<std::string, std::pair<std::string, int>> g_Var, std::map<std::string, std::pair<std::string, int>> loc_Var, std::string type_check , bool &isConstant, bool isLocal) override
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