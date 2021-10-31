#ifndef SIMPLIFIER
#define SIMPLIFIER

#include "../node/int_node.h"
#include "../node/embedded_node.h"
#include "../node/constant_node.h"
#include "../node/function_node.h"

class simplifier
{
    node_ptr traverse_tree_get_active_plus(node_ptr ptr);
    node_ptr traverse_tree_get_active_mul(node_ptr ptr);
public:
    void flatten_tree(node_ptr node);
    
    void simplify_all(node_ptr root);
};

#endif