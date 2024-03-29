#ifndef ast_expression_hpp
#define ast_expression_hpp

#include <string>
#include <iostream>
#include <map>
#include <memory>
#include <vector>
#include <set>

class Expression;

typedef Expression *ExpressionPtr;

class Expression
{
public:
    virtual ~Expression()
    {}

    // The map will contain gVar[VARIABLE_NAME] = VARIABLE_LOCATION (global variables)
    //REMOVE LATER
    virtual std::string Compile( int &mem, std::map<std::string, std::pair<std::string, int>> g_Var, std::map<std::string, std::pair<std::string, int>> &loc_Var, std::string type_check , bool &isConstant, bool isLocal, std::vector<int> func_call) 
    {
        throw std::runtime_error("This should not be called. Needs to be overriden. COMPILE");
    }

    virtual void AtLocation() { throw std::runtime_error("This should not be called. Needs to be overriden. AT LOCATION"); }
    
};

#endif
