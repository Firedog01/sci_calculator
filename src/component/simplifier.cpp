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

void simplifier::group_ints(node_ptr root) {
    node_ptr active_plus = root;
    while(active_plus->get_plus_node() != nullptr) {
        node_ptr active_mul = active_plus->get_mul_node();
        while(active_mul->get_mul_node() != nullptr) {

            if(active_mul->get_type() == "embedded") {
                embedded_ptr ptr = static_pointer_cast<embedded_node>(active_mul);
                group_ints(ptr->get_cont());
            }
            node_ptr next_active_mul = active_mul->get_mul_node();
            if(active_mul->get_type() == "int" && 
                    next_active_mul->get_type() == "int") {
                //grupowanie potęg i ułamków
                if(next_active_mul->is_div() || next_active_mul->is_pow()) {
                    //next_active_mul->set_mul_node(nullptr);
                
                    //node_ptr x, bool min, bool div, bool pow
                    //embedded_ptr new_node = make_shared<embedded_node>();
                }
            }
            active_mul = active_mul->get_mul_node();
        }
        active_plus = active_plus->get_plus_node();
    }
}

void simplifier::simplify_all(node_ptr root) {
    group_ints(root);
}



