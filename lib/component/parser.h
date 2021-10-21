#include <string>
#include <limits>
#include <stdexcept>
#include <iostream>

#include "string_handling.h"

#include "../node/int_node.h"
#include "../node/embedded_node.h"
#include "../node/constant_node.h"
#include "../node/function_node.h"

#include "../manager/constant_manager.h"
#include "../manager/function_manager.h"
#include "../manager/tree_manager.h"


class parser {
private:
    node_ptr root;
    constant_manager c_man;
    function_manager f_man;
    tree_manager t_man;

    /**
     * main creation function. Creates new branch for root or for embeded root
     */
    node_ptr create_embedded_branch(std::string str);

    /**
     * creates node depending on its contents. Calls one of functions below.
     */ 
    node_ptr create_node(std::string str, int& i, op& op);
    node_ptr create_int_node(const std::string& cont, bool min, bool div, bool pow);
    node_ptr create_embedded_node(std::string cont, bool min, bool div, bool pow);
    node_ptr create_constant_node(const std::string& name, bool min, bool div, bool pow);
    node_ptr create_function_node(std::string name, std::string arguments, bool min, bool div, bool pow);
    

    // recursive displaying
    std::string display_subtree(const node_ptr& node, op op);
    static std::string get_math_operator(op op, bool min, bool div, bool pow);
    
public:
    std::string test();
    std::string display_tree();

    parser(std::string str);

    node_ptr getRoot();
    dong enumerate_root();
};

/*
assumptions:
    2^3*4 = 2^(3*4)
    2/3*4 = (2/3)*4
 */