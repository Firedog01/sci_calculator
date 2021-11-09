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

//todo test -  on it ma boi
void simplifier::swap_nodes(node_ptr ptr1, node_ptr ptr2) {
	node_ptr temp = nullptr;
	temp = ptr1->get_plus_node();
	ptr1->set_plus_node(ptr2->get_plus_node());
	ptr2->set_plus_node(temp);
	temp = ptr1->get_mul_node();
	ptr1->set_mul_node(ptr2->get_mul_node());
	ptr2->set_mul_node(temp);

	if(ptr1->get_prev_node() != nullptr) {
		if(ptr1->get_prev_node()->get_mul_node() == ptr1)
			ptr1->get_prev_node()->set_mul_node(ptr2);
		else if(ptr1->get_prev_node()->get_plus_node() == ptr1)
			ptr1->get_prev_node()->set_plus_node(ptr2);
		else if(ptr1->get_prev_node()->get_type() == Embedded) {
			node_ptr ptr = ptr1->get_prev_node();
			embedded_ptr ptr_e = std::static_pointer_cast<embedded_node>(ptr);
			ptr_e->set_cont(ptr2);
		}
	}
	if(ptr2->get_prev_node() != nullptr) {
		if(ptr2->get_prev_node()->get_mul_node() == ptr2)
			ptr2->get_prev_node()->set_mul_node(ptr1);
		else if(ptr2->get_prev_node()->get_plus_node() == ptr2)
			ptr2->get_prev_node()->set_plus_node(ptr1);
		else if(ptr1->get_prev_node()->get_type() == Embedded) {
			node_ptr ptr = ptr1->get_prev_node();
			embedded_ptr ptr_e = std::static_pointer_cast<embedded_node>(ptr);
			ptr_e->set_cont(ptr2);
		}
	}
	temp = ptr1->get_prev_node();
	ptr1->set_prev_node(ptr2->get_prev_node());
	ptr2->set_prev_node(temp);

	if(this->root == ptr1) {
		cout << "podmiana\n";
		*this->root = ptr2;
	} else if(this->root == ptr2) {
		cout << "podmiana2\n";
		*this->root = ptr1;
	}
}

void simplifier::sort_mul_branches() {
	node_ptr active_plus = *root;
	node_type type_order[5] {Int, Constant, Variable, Embedded, Function};
	// default operation order: min, div, pow
	do {
		cout << "plus branch\n";
		bool changed = true;
		while(changed) {
			cout << "mul---\n";
			node_ptr active_mul = active_plus;
			node_type act_type = active_mul->get_type();
			changed = false;

			while(active_mul->get_mul_node() != nullptr) {
				cout << "type: " << active_mul->get_type() << "\n";
				node_ptr next_node = active_mul->get_mul_node();
				node_type next_type = next_node->get_type();
				int act_i = 0;
				for(int i = 0; i < 5; i++, act_i++) {
					if(active_mul->get_type() == type_order[i]) {
						break;
					}
				}
				cout << "act_i: " << act_i << endl;
				int next_i = 0;
				for(int i = 0; i < 5; i++, next_i++) {
					if(next_node->get_type() == type_order[i]) {
						break;
					}
				}
				cout << "next_i: " << next_i << endl;
				if(act_i > next_i) {
					swap_nodes(active_mul, next_node);
					changed = true;
					cout << "swapped\n";
				}
				//----------------------------------------------------------------
				int act_ops = 0;
				if(active_mul->is_min()) {
					act_ops += 1;
				}
				if(active_mul->is_div()) {
					act_ops += 2;
				}
				if(active_mul->is_pow()) {
					act_ops += 4;
				}
				cout << "act_ops: " << act_ops << endl;
				int next_ops = 0;
				if(next_node->is_min()) {
					next_ops += 1;
				}
				if(next_node->is_div()) {
					next_ops += 2;
				}
				if(next_node->is_pow()) {
					next_ops += 4;
				}
				cout << "next_ops: " << next_ops << endl;
				if(act_ops > next_ops) {
					swap_nodes(active_mul, next_node);
					changed = true;
					cout << "swapped\n";
				}

				active_mul = active_mul->get_mul_node();
				cout << "-----\n";
			}
		}
		active_plus = active_plus->get_plus_node();
	} while(active_plus->get_plus_node() != nullptr);
}

void simplifier::group_ints_pow() {
	node_ptr active_plus = *root;
	node_ptr prev_active_mul = nullptr;
	while(active_plus->get_plus_node() != nullptr) {
		node_ptr active_mul = active_plus->get_mul_node();
		while(active_mul->get_mul_node() != nullptr) {

			if(active_mul->get_type() == Embedded) {
				embedded_ptr ptr = static_pointer_cast<embedded_node>(active_mul);
				// group_ints_pow(ptr->get_cont());
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

void simplifier::group_ints_div() {}

void simplifier::simplify_all(node_ptr root) {
	// group_ints_pow(root);
	// sort_mul_branches(root);
	// group_ints_div(root);
	cout << "simplifier\n";
	root = root->get_mul_node();
	// this->root = root;
	// swap_nodes(root, (root)->get_mul_node());
}



