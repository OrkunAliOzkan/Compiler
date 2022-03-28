#ifndef ast_hpp
#define ast_hpp

#include "ast/ast_expression.hpp"
#include "ast/ast_function_definition.hpp"
#include "ast/ast_assign.hpp"
#include "ast/ast_primitives.hpp"
#include "ast/ast_operators.hpp"
#include "ast/ast_declare.hpp"
#include "ast/ast_translation.hpp"
#include "ast/ast_a_expr.hpp"
#include "ast/ast_specifiers.hpp"
#include "ast/ast_enum.hpp"
#include "ast/ast_pointer.hpp"
#include "ast/ast_type_name.hpp"
#include "ast/ast_initialize.hpp"
#include "ast/ast_labeled_statement.hpp"
#include "ast/ast_compound_statement.hpp"
#include "ast/ast_declaration_list.hpp"
#include "ast/ast_statement_list.hpp"
#include "ast/ast_expression_statement.hpp"
#include "ast/ast_selection_statement.hpp"
#include "ast/ast_iteration_statement.hpp"
#include "ast/ast_jump_statement.hpp"
#include "ast/ast_head.hpp"
#include "ast/ast_unary.hpp"
#include "ast/ast_postfix.hpp"

extern Expression *parseAST();

#endif
