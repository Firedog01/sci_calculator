#include <string>
#include <limits>
#include <stdexcept>
#include <iostream>

#include "node/lib/math_node.h"
#include "node/lib/int_node.h"
#include "node/lib/embeded_node.h"
#include "node/lib/constant_node.h"
#include "node/lib/function_node.h"

#include "managers/lib/constant_manager.h"


class parser {
private:
    node_ptr root;
    constant_manager c_man;

    std::string debug;

    //misc functions 
    void remove_spaces(std::string& str);
    std::string get_num(std::string str, int& i);
    std::string get_embeded(std::string str, int& i);
    std::string get_name(std::string str, int& i);
    bool check_name_character(char c);


    // creating nodes
    node_ptr create_embeded_branch(std::string str);

    node_ptr create_node(std::string str, int& i, op& op);
    node_ptr create_int_node(std::string cont, bool min, bool div, bool pow);
    node_ptr create_embeded_node(std::string cont, bool min, bool div, bool pow);
    node_ptr create_constant_node(std::string name, bool min, bool div, bool pow);
    node_ptr create_function_node(std::string name, std::string arguments, bool min, bool div, bool pow);
    

    //displaying
    std::string display_subtree(node_ptr node, op op);
    std::string get_math_operator(op op, bool min, bool div, bool pow);


    //tree optimalisation
    void flatten_tree();

    
public:
    parser(std::string str);
    std::string test();
    std::string display_tree();
};