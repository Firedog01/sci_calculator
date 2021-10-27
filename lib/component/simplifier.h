#ifndef SIMPLIFIER
#define SIMPLIFIER

#include "../node/int_node.h"
#include "../node/embedded_node.h"
#include "../node/constant_node.h"
#include "../node/function_node.h"

class simplifier
{
public:
    void flatten_tree(node_ptr root);
    
    void simplify_all(node_ptr root);
};

#endif