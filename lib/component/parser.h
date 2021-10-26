#ifndef PARSER
#define PARSER

#include <string>
#include <limits>
#include <stdexcept>
#include <iostream>

#include "str_hdl.h"

#include "../node/int_node.h"
#include "../node/embedded_node.h"
#include "../node/constant_node.h"
#include "../node/function_node.h"

class parser {
private:
    node_ptr root;
    f_man_ptr f_man;
    c_man_ptr c_man;
//    constant_manager c_man;
//    function_manager f_man;
//    tree_manager t_man;

    /**
     * main creation function. Creates new branch for root or for embeded root
     */
    node_ptr create_embedded_branch(std::string str);

    /**
     * Creates node depending on its contents. Calls one of functions below.
     * @param str string
     * @param i integer, iterator through string
     * @param op enum, used for deciding which branch to fill
     */ 
    node_ptr create_node(std::string str, int& i, op& op);
    node_ptr create_int_node(const std::string& cont, bool min, bool div, bool pow);
    node_ptr create_embedded_node(std::string cont, bool min, bool div, bool pow);
    node_ptr create_constant_node(const std::string& name, bool min, bool div, bool pow);
    node_ptr create_function_node(std::string name,  std::vector<std::string> args, bool min, bool div, bool pow);
    

    // recursive displaying
    std::string display_subtree(const node_ptr& node, op op);
    static std::string get_math_operator(op op, bool min, bool div, bool pow);
    
public:
    //debugs
    void test();
    std::string display_tree();

    /**
     * Constructor calls create_embedded_branch for root
     * may throw logic_exception
     * for sure will not is checker is ran first
     * @throws logic_error
     * @param str string
     */
    parser(std::string str);

    node_ptr getRoot();
};

/*
assumptions:
    2^3*4 = 2^(3*4)
    2/3*4 = (2/3)*4
    2+^3 = 2^3
 */
#endif