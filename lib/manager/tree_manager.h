#include <utility>
#include <cmath>

#include "../includes.h"
#include "../node/int_node.h"
#include "../node/embedded_node.h"
#include "../node/constant_node.h"
#include "../node/function_node.h"

class tree_manager 
{
    dong renum(node_ptr node); //recursively enumerate tree
    dong get_node_value(node_ptr node);
    dong pow_node_value(dong val, node_ptr node); // powers val and returns answer
public:
    dong enumerate_tree(node_ptr root);
};