#include "../../lib/manager/tree_manager.h"

using namespace std;

dong tree_manager::renum(node_ptr node) {
    dong ret_val = 0;


    if(node->get_type() == "embedded") {
        embedded_ptr ptr = static_pointer_cast<embedded_node>(node);
        ret_val = renum(ptr->get_cont());
    }
    if(node->get_mul_node() != nullptr) {
        //^ check here
    }
    if(node->get_plus_node() != nullptr) {

    }

    return ret_val;
}

dong tree_manager::get_node_value(node_ptr node) {
    string type = node->get_type();
    if(type == "int") {

    } else if(type == "function") {

    } else if(type == "constant") {

    } else if(type == "variable") {

    } else {
        return nanl(nullptr); // not-a-number
    }
}

dong tree_manager::enumerate_tree(node_ptr root) {
    return renum(std::move(root));
}




