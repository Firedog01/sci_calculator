#include "../../lib/component/simplifier.h"

node_ptr simplifier::traverse_tree_get_active_plus(node_ptr ptr) {
    node_ptr active = ptr;
    while(active->get_mul_node() != nullptr) {
        active = active->get_mul_node();
    }
    return active;
}

node_ptr simplifier::traverse_tree_get_active_mul(node_ptr ptr) {
    node_ptr active = ptr;
    while(active->get_plus_node() != nullptr) {
        active = active->get_mul_node();
    }
    return active;
}


void simplifier::flatten_tree(node_ptr node) {
    node_ptr mul_node = node->get_mul_node();
    node_ptr plus_node = node->get_plus_node();
    if(mul_node != nullptr) {
        if(mul_node->get_type() == "embedded") {
            embedded_ptr ptr = static_pointer_cast<embedded_node>(mul_node);
            node_ptr embd_node = ptr->get_cont();
            //przestawić środek i ustawić niższe node'y odpowiednio
        }
    }

}

void simplifier::simplify_all(node_ptr root) {
    flatten_tree(root);
}



