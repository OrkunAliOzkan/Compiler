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
    virtual std::string Compile( std::string current_func, std::map<std::string, std::string> g_Var, std::map<std::string, bool> reg_available, std::string type_check ) 
    {
        return 0;
    }

};


#endif
