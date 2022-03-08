#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <stack>
#include "ast.hpp"


/*Unary Expression Function Declarations*/
const Expression* Unary_Expression::getNext() const{
	return expression;
}

std::string Unary_Expression::getType() const{
	return "Unary";
}

/*Additive Expression Function Declarations*/