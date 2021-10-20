#ifndef TREE_MANAGER
#define TREE_MANAGER
#include <utility>
#include <cmath>

#include "../includes.h"
#include "../node/int_node.h"
#include "../node/embedded_node.h"
#include "../node/constant_node.h"
#include "../node/function_node.h"

#include "../manager/constant_manager.h"

class tree_manager 
{
    constant_manager c_man;

    dong get_tree_value(node_ptr node); //recursively enumerate tree
    dong get_node_value(node_ptr node);
public:
    tree_manager() : c_man() {}
    dong enumerate_tree(node_ptr root);
};
#endif