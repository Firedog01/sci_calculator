#include "../../lib/component/simplifier.h"

using namespace std;

void simplifier::handle_prev_nodes(node_ptr& ptr1, node_ptr& ptr2) {
	node_ptr prev = ptr1->get_prev_node();
	if(prev != nullptr) {
		if(prev->get_mul_node() == ptr1) {
			prev->mul_node = ptr2;
		}
		else if(prev->get_plus_node() == ptr1) {
			prev->plus_node = ptr2;
		}
		else if(prev->get_type() == Embedded) {
			node_ptr ptr = prev;
			embedded_ptr ptr_e = std::static_pointer_cast<embedded_node>(ptr);
			ptr_e->set_cont(ptr2);
		}
	} else {
		cout << "root\n";
	}
}

void simplifier::swap_nodes(node_ptr& ptr1, node_ptr& ptr2, node_ptr& root) {
	node_ptr temp = nullptr;
	temp = ptr1->get_plus_node();
	ptr1->set_plus_node(ptr2->get_plus_node());
	ptr2->set_plus_node(temp);

	temp = ptr1->get_mul_node();
	ptr1->set_mul_node(ptr2->get_mul_node());
	ptr2->set_mul_node(temp);

	handle_prev_nodes(ptr1, ptr2);
	handle_prev_nodes(ptr2, ptr1);
	
	temp = ptr1->get_prev_node();
	ptr1->set_prev_node(ptr2->get_prev_node());
	ptr2->set_prev_node(temp);

	root = ptr1->get_root();
}

int simplifier::get_order_type(node_ptr node) {
	if(node == nullptr) {
		return -2;
	}
	for(int i = 0; i < 5; i++) {
		if(node->get_type() == this->type_order[i]) {
			return i;
		}
	}
	return -1;
}

int simplifier::get_order_oper(node_ptr node) {
	if(node == nullptr) {
		return -1;
	}
	int ops = 0;
	if(!node->is_min()) {
		ops += 1;
	}
	if(node->is_div()) {
		ops += 2;
	}
	if(node->is_pow()) {
		ops += 4;
	}
	return ops;
}

void simplifier::sort_mul_branches(node_ptr& root) {
	
	// default operation order: min, none, div, pow
	node_ptr active_plus = root;
	
	int n_plus_branches = 1;
	while(active_plus->get_plus_node() != nullptr) {
		n_plus_branches++;
		active_plus = active_plus->get_plus_node();
	}
	cout << "n_plus_branches = " << n_plus_branches << endl;
	
	for(int i = 0; i < n_plus_branches; i++) {
		cout << "plus_branch\n";
		bool changed = true;
		
		int n_mul = 0;
		node_ptr active_mul = active_plus;
		while(active_mul->get_mul_node() != nullptr) {
			n_mul++;
			active_mul = active_mul->get_mul_node();
		}
		cout << "n_mul = " << n_mul << "\n";

		while(changed) {
			changed = false;
			
			for(int j = 0; j < n_mul; j++) {
				cout << "i: " << i << " j: " << j << endl;

				cout << "przed\n";
				active_plus = active_plus->get_root();
				cout << "po\n";
				for(int k = 0; k < i; k++) {
					active_plus = active_plus->get_plus_node();
				}

				active_mul = active_plus;
				for(int k = 0; k < j; k++) {
					active_mul = active_mul->get_mul_node();
				}

				if(active_mul == nullptr) {
					cout << "mul null!\n";
				} else {
					cout << "mul not null\n";
				}
				node_ptr next_node = active_mul->get_mul_node();
				
				int act_type = get_order_type(active_mul);
				cout << "act_type: " << act_type << endl;
				int next_type = get_order_type(next_node);
				cout << "next_type: " << next_type << endl;

				int act_ops = get_order_oper(active_mul);
				cout << "act_ops: " << act_ops << endl;
				int next_ops = get_order_oper(next_node);
				cout << "next_ops: " << next_ops << endl;

				if(act_type > next_type || act_ops > next_ops) {
					cout << "pre_swap\n";
					swap_nodes(active_mul, next_node, root);
					changed = true;
					cout << "swapped\n";
				}
				cout << "-----\n";
			}
		}
	}
}

void simplifier::group_ints_pow(node_ptr& root) {
	node_ptr active_plus = root;
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

void simplifier::group_ints_div(node_ptr& root) {}

void simplifier::simplify_all(node_ptr& root) {
	// group_ints_pow(root);
	// sort_mul_branches(root);
	// group_ints_div(root);

	node_ptr temp = root->get_mul_node();
	// temp->set_flag(true, 0);
	// swap_nodes(root, temp, root);
	sort_mul_branches(root);
}
