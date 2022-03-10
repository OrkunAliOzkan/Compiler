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
    //virtual std::string variable_loc( std::map<std::string, std::string> g_Var) { return 0; }

};


#endif
