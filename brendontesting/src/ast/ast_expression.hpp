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
    virtual std::string Compile( std::string current_func, int mem, std::map<std::string, std::string> g_Var, std::map<std::string, bool> reg_available, std::string type_check ) 
    {
        throw std::runtime_error("This should not be called. Needs to be overriden.");
    }

};

#endif
