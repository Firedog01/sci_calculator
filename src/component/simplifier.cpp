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

void simplifier::swap_nodes_same_plus_branch(node_ptr ptr1, node_ptr ptr2) {
	// ptr1->get_prev_node()->set_mul_node()
}


/* sort mul branches 

zawartość:
    int
    const
    variable
    embedded
    func
operacje:
    mul, div, pow
*/
void simplifier::sort_mul_branches(node_ptr root) {
	node_ptr active_plus = root;
	while(active_plus->get_plus_node() != nullptr) {

	}
}

void simplifier::group_ints_pow(node_ptr root) {
	node_ptr active_plus = root;
	node_ptr prev_active_mul = nullptr;
	while(active_plus->get_plus_node() != nullptr) {
		node_ptr active_mul = active_plus->get_mul_node();
		while(active_mul->get_mul_node() != nullptr) {

			if(active_mul->get_type() == Embedded) {
				embedded_ptr ptr = static_pointer_cast<embedded_node>(active_mul);
				group_ints_pow(ptr->get_cont());
			}
			node_ptr next_active_mul = active_mul->get_mul_node();
			if(active_mul->get_type() == Int && 
					next_active_mul->get_type() == Int) {
				//grupowanie potęg 
				if(next_active_mul->is_pow()) {
					node_ptr next_next_mul = next_active_mul->get_mul_node();
					//next_active_mul->set_mul_node(nullptr);
					//przestawić poprzedni na new_node
					//przestwaić flagi z mul_node na new_node;

					//node_ptr x, bool min, bool div, bool pow
					// embedded_ptr new_node = make_shared<embedded_node>(mul_node, );
					// new_node->set_mul_node(next_next_mul);
				}
			}
			prev_active_mul = active_mul;
			active_mul = active_mul->get_mul_node();
		}
		prev_active_mul = nullptr;
		active_plus = active_plus->get_plus_node();
	}
}

void simplifier::group_ints_div(node_ptr root) {}

void simplifier::simplify_all(node_ptr root) {
	group_ints_pow(root);
	group_ints_div(root);
}



