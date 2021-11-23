#include "../../lib/component/simplifier.h"

using namespace std;

void simplifier::get_mul_root(node_ptr& active_mul, int p) {
	//update root position
	active_mul = active_mul->get_root();
	for(int i = 0; i < p; i++) {
		active_mul = active_mul->get_plus_node();
	}
}

void simplifier::get_node(node_ptr& node, node_ptr& root, int p, int m) {
	get_mul_root(node, p); //node równy szczytowi
	int n_mul = get_n_mul(node);
	if(m > n_mul) { // ? >=
		node = nullptr;
	} else {
		for(int i = 0; i < m; i++) {
			node = node->get_mul_node();
		}
	}
}

int simplifier::get_n_plus(node_ptr root) {
	int n = 1;
	
	while(root->get_plus_node() != nullptr) {
		n++;
		root = root->get_plus_node();
	}
	 cout << "n_plus_branches = " << n << endl;
	return n;
}

int simplifier::get_n_mul(node_ptr active_plus) {
	int n = 0; //nie dokońca wiem dlaczego, ale inaczej nie działa

	while(active_plus->get_mul_node() != nullptr) {
		n++;
		active_plus = active_plus->get_mul_node();
	}
	 cout << "n_mul = " << n << endl;
	return n;
}



void simplifier::set_prev_node(node_ptr& to_prev, node_ptr& to_set) {
	node_ptr prev = to_prev->get_prev_node();
	if(prev != nullptr) {
		if(prev->get_mul_node() == to_prev) {
			prev->mul_node = to_set;
		}
		else if(prev->get_plus_node() == to_prev) {
			prev->plus_node = to_set;
		}
		else if(prev->get_type() == Embedded) {
			node_ptr ptr = prev;
			embedded_ptr ptr_e = std::static_pointer_cast<embedded_node>(ptr);
			ptr_e->set_cont(to_set);
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

    set_prev_node(ptr1, ptr2);
    set_prev_node(ptr2, ptr1);
	
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
	node_ptr active = root;
	
	for(int i_plus = 0; i_plus < get_n_plus(root); i_plus++) {
		bool changed = true;
		while(changed) {
			changed = false;
			for(int i_mul = 0; i_mul < get_n_mul(root); i_mul++) { 

				get_node(active, root, i_plus, i_mul);
				node_ptr next_node = active->get_mul_node();
				
				int act_type = get_order_type(active);
				cout << "act_type: " << act_type << endl;
				int next_type = get_order_type(next_node);
				cout << "next_type: " << next_type << endl;

				int act_ops = get_order_oper(active);
				cout << "act_ops: " << act_ops << endl;
				int next_ops = get_order_oper(next_node);
				cout << "next_ops: " << next_ops << endl;

				if(act_type > next_type || act_ops > next_ops) {
					swap_nodes(active, next_node, root);
					changed = true;
					cout << "swapped\n";
				}
				cout << "-----\n";
			}
		}
	}
}

//math_node->set_pair(true);
void simplifier::group_pows(node_ptr& root) {
	node_ptr active = root;
	
	for(int i_plus = 0; i_plus < get_n_plus(root); i_plus++) {
		bool changed = true;
		while(changed) {
			changed = false;
			for(int i_mul = 0; i_mul < get_n_mul(root); i_mul++) {
                cout << "i_plus: " << i_plus << " i_mul: " << i_mul << "\n";
				get_node(active, root, i_plus, i_mul);
                cout << "node set\n";
				node_ptr next_node = active->get_mul_node();
				if(next_node->is_pow()) {
                    cout << "is pow\n";
					node_ptr cont = active;

                    next_node->get_plus_node();
                    next_node->set_plus_node(nullptr);
                    cout << "assign\n";
					embedded_ptr new_node = make_shared<embedded_node>(
						cont, active->is_min(), active->is_div(), active->is_pow()
					);
                    active->set_min(false);
                    active->set_div(false);
                    active->set_pow(false);

                    cout << "created new node\n";
					node_ptr new_node_base = static_pointer_cast<math_node>(new_node);
                    cout << "cast done\n";
                    set_prev_node(active, new_node_base);
					node_ptr next_next_node = next_node->get_mul_node();
					if(next_next_node != nullptr) {
						//move new_node->next_mul to next_next_node
					}
				}
				if(active->get_type() == Embedded) {
					embedded_ptr ptr = static_pointer_cast<embedded_node>(active);
					node_ptr cont = ptr->get_cont();
					group_pows(cont);
				}
			}
		}
	}
}

void simplifier::group_ints_div(node_ptr& root) {}

void simplifier::simplify_all(node_ptr& root) {
//	group_pows(root);
//	sort_mul_branches(root);
	// group_ints_div(root);
}
