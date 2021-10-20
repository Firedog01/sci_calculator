#include "../../lib/manager/tree_manager.h"

using namespace std;

dong tree_manager::get_tree_value(node_ptr node) {
    dong ret_val = get_node_value(node);
    node_ptr mul_node = node->get_mul_node();
    node_ptr plus_node = node->get_plus_node();

    if(mul_node != nullptr) {
        if(mul_node->is_pow()) {
            ret_val = pow(ret_val, get_tree_value(mul_node));
        } else {
            ret_val *= get_tree_value(mul_node);
        }
    }
    if(plus_node != nullptr) {
        if(plus_node->is_pow()) {
            // syntax error
        } else {
            ret_val += get_tree_value(plus_node);
        }
    }

    return ret_val;
}

dong tree_manager::get_node_value(node_ptr node) {
    dong value;
    string type = node->get_type();
    if(type == "int") {
        int_ptr ptr = static_pointer_cast<int_node>(node);
        value = ptr->get_cont();
    } else if(type == "function") {
        function_ptr ptr = static_pointer_cast<function_node>(node);
        value = ptr->enumerate();
    } else if(type == "constant") {
        constant_ptr ptr = static_pointer_cast<constant_node>(node);
        value = c_man.get_value(ptr->get_id_const());
    } else if(type == "variable") {
        value = 0; // TODO variable handling
    } else if(type == "embedded") { //because of pow_node_value
        embedded_ptr ptr = static_pointer_cast<embedded_node>(node);
        value = get_tree_value(ptr->get_cont());
    } else {
        return nanl(nullptr); // not-a-number
    }
    if(node->is_min()) {
        value *= -1;
    }
    if(node->is_div()) {
        value = 1 / value;
    }
    return value;
}

dong tree_manager::enumerate_tree(node_ptr root) {
    return get_tree_value(std::move(root));
}




