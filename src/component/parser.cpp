#include "../../lib/component/parser.h"

using namespace std;

// todo 
//	  zrobić testy do funciton
//	  poparawić testy constant

// kwestja przecinka w liczbach. np 2.34 = 2 + 34 / 100
//
//
node_ptr parser::parse(string str) {
	str_hdl::remove_spaces(str);
	cout << "skrocony string: " + str + '\n';
	this->root = create_embedded_branch(str);
	return this->root;
}

node_ptr parser::create_embedded_branch(std::string str) {
	int i = 0;
	op cur_op = add;
	node_ptr emb_root = create_node(str, i, cur_op); 
	node_ptr active_plus = emb_root,  active_mul = emb_root;

	while(i < str.length()) {
		node_ptr new_node = create_node(str, i, cur_op);
		if(cur_op == add) {
			active_plus->set_plus_node(new_node);
			active_mul = new_node;
			active_plus = new_node;
		} else if(cur_op == mul) {
			active_mul->set_mul_node(new_node);
			active_mul = new_node;
		}
	}
	return emb_root;
}


node_ptr parser::create_node(string str, int& i, op& op) {
	bool min = false, div = false, pow = false;
	op = def;

	while(i < str.length()) {
		switch(str[i]) {
		case str_hdl::OP_ADD_C:
			if(op == def) {
				op = add;
			}
			break;
		case str_hdl::OP_SUB_C:
			if(op == def) {
				op = add;
			}
			min = !min;
			break;
		case str_hdl::OP_MUL_C:
			op = mul;
			break;
		case str_hdl::OP_DIV_C:
			op = mul;
			div = true;
			break;
		case str_hdl::OP_POW_C:
			op = mul;
			pow = true;
			break;

		CASE_DIGIT {
			if(op == def) {
				op = mul;
			}
			string num = str_hdl::get_num(str, i);
			return create_int_node(num, min, div, pow);
		}

		case str_hdl::O_BRACKET_C: {
			if(op == def) {
				op = mul;
			}
			string embedded = str_hdl::get_embedded(str, i);
			return create_embedded_node(embedded, min, div, pow);
		}
		
		case str_hdl::FUNC_C: {
			if(op == def) {
				op = mul;
			}
			i++;
			string name = str_hdl::get_name(str, i);
			vector<string> args = str_hdl::get_func_args(str, i);
			return create_function_node(name, args, min, div, pow);
		}
		
		case str_hdl::CONST_C: {
			if(op == def) {
				op = mul;
			}
			i++;
			string name = str_hdl::get_name(str, i);
			return create_constant_node(name, min, div, pow);
		}
			
		default:
			string err = "unknown operator ";
			err += str[i];
			throw logic_error(err);
		}
		i++;
	}
	return nullptr;
}

node_ptr parser::create_int_node(const string& cont, bool min, bool div, bool pow) {
	unsigned long long val = stoull(cont);
	return make_shared<int_node>(val, min, div, pow);
}

node_ptr parser::create_embedded_node(string cont, bool min, bool div, bool pow) {
	node_ptr root_branch = create_embedded_branch(cont);
	return make_shared<embedded_node>(root_branch, min, div, pow);
}

node_ptr parser::create_constant_node(const string& name, bool min, bool div, bool pow) {
	int id_const = c_man->get_id(name);
	return make_shared<constant_node>(c_man, id_const, min, div, pow);
}

node_ptr parser::create_function_node(string name, vector<string> args_str, bool min, bool div, bool pow) {
	int id_func = f_man->get_id_func(name);
	vector<node_ptr> args;
	for(int j = 0; j < args_str.size(); j++) {
		args.push_back( (create_embedded_branch(args_str[j])) );
	}
	return make_shared<function_node>(f_man, id_func, args, min, div, pow);
}

node_ptr parser::get_root() {
	return this->root;
}
