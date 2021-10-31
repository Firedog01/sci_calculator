#ifndef DISPLAYER
#define DISPLAYER

#include "str_hdl.h"

#include "../node/int_node.h"
#include "../node/embedded_node.h"
#include "../node/constant_node.h"
#include "../node/function_node.h"

class displayer
{
    f_man_ptr f_man;
    c_man_ptr c_man;

    std::string display_subtree(const node_ptr& node, op op);
    std::string get_math_operator(op op, bool min, bool div, bool pow);
public:
    displayer(f_man_ptr f_man, c_man_ptr c_man) : f_man(f_man), c_man(c_man) {}
    dong enumerate(node_ptr root);
    std::string display(node_ptr root);
};

#endif