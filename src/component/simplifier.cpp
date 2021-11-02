#include "../../lib/component/simplifier.h"

using namespace std;

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
        active = active->get_plus_node();
    }
    return active;
}


//bool simplifier::flatten_tree(node_ptr node) {
//    node_ptr mul_node = node->get_mul_node();
//    if(mul_node != nullptr) {
//        if(mul_node->get_type() == "embedded") {
//            embedded_ptr ptr = static_pointer_cast<embedded_node>(mul_node);
//            node_ptr embd_node = ptr->get_cont();
//
//            flatten_tree(embd_node);
//
//            node_ptr active_mul = traverse_tree_get_active_mul(embd_node);
//            node_ptr active_plus = traverse_tree_get_active_plus(embd_node);
//
//            if(mul_node->get_mul_node() != nullptr) {
//                active_mul->set_mul_node(mul_node->get_mul_node());
//            }
//            if(mul_node->get_plus_node() != nullptr) {
//                active_plus->set_plus_node(mul_node->get_plus_node());
//            }
//            node->set_mul_node(embd_node);
//        }
//        flatten_tree(mul_node);
//    }
//    node_ptr plus_node = node->get_plus_node();
//    if(plus_node != nullptr) {
//
//        if(plus_node->get_type() == "embedded") {
//            embedded_ptr ptr = static_pointer_cast<embedded_node>(plus_node);
//            node_ptr embd_node = ptr->get_cont();
//
//            flatten_tree(embd_node);
//
//            node_ptr active_mul = traverse_tree_get_active_mul(embd_node);
//            node_ptr active_plus = traverse_tree_get_active_plus(embd_node);
//
//            if(plus_node->get_mul_node() != nullptr) {
//                active_mul->set_mul_node(plus_node->get_mul_node());
//            }
//            if(plus_node->get_plus_node() != nullptr) {
//                active_plus->set_plus_node(plus_node->get_plus_node());
//            }
//            node->set_plus_node(embd_node);
//        }
//        flatten_tree(plus_node);
//    }
//}

void simplifier::simplify_all(node_ptr root) {
    // flatten_tree(root);
}



