#include "../../lib/component/parser.h"

#include <utility>

using namespace calculator;

// todo 
//	  zrobić testy do funciton
//	  poparawić testy constant

// Kwesta przecinka w liczbach. np 2.34 = 2 + 34 / 100
//
//
_node_ptr parser::parse(std::string str) {
	str_hdl::remove_spaces(str);
//	std::cout << "skrócony string: " + str + '\n';
	this->root = create_embedded_branch(str);
	return this->root;
}

_node_ptr parser::create_embedded_branch(std::string str) {
	int i = 0;
	op cur_op = add_;
	_node_ptr emb_root = create_node(str, i, cur_op);
	_node_ptr active_plus = emb_root,  active_mul = emb_root;

	while(i < str.length()) {
		_node_ptr new_node = create_node(str, i, cur_op);
		if(cur_op == add_) {
			active_plus->set_plus_node(new_node);
			active_mul = new_node;
			active_plus = new_node;
		} else if(cur_op == mul_) {
			active_mul->set_mul_node(new_node);
			active_mul = new_node;
		}
	}
	return emb_root;
}


_node_ptr parser::create_node(std::string str, int& i, op& op) {
	bool min = false, div = false, pow = false;
	op = def_;

	for(; i < str.length(); i++) {
		switch(str[i]) {
		case str_hdl::OP_ADD_C:
			if(op == def_) {
				op = add_;
			}
			break;
		case str_hdl::OP_SUB_C:
			if(op == def_) {
				op = add_;
			}
			min = !min;
			break;
		case str_hdl::OP_MUL_C:
			op = mul_;
			break;
		case str_hdl::OP_DIV_C:
			op = mul_;
			div = true;
			break;
		case str_hdl::OP_POW_C:
			op = mul_;
			pow = true;
			break;

		CASE_DIGIT {
			if(op == def_) {
				op = mul_;
			}
			std::string num = str_hdl::get_num(str, i);
			return create_int_node(num, min, div, pow);
		}

		case str_hdl::O_BRACKET_C: {
			if(op == def_) {
				op = mul_;
			}
			std::string embedded = str_hdl::get_embedded(str, i);
			return create_embedded_node(embedded, min, div, pow);
		}
		
		case str_hdl::FUNC_C: {
			if(op == def_) {
				op = mul_;
			}
			i++;
			std::string name = str_hdl::get_name(str, i);
			std::vector<std::string> args = str_hdl::get_func_args(str, i);
			return create_function_node(name, args, min, div, pow);
		}
		
		case str_hdl::CONST_C: {
			if(op == def_) {
				op = mul_;
			}
			i++;
			std::string name = str_hdl::get_name(str, i);
			return create_constant_node(name, min, div, pow);
		}
			
		default:
			std::string err = "unknown operator ";
			err += str[i];
			throw std::logic_error(err);
		}
	}
	return nullptr;
}

_node_ptr parser::create_int_node(const std::string& cont, bool min, bool div, bool pow) {
	unsigned long long val = stoull(cont);
	return std::make_shared<node::int_node>(val, min, div, pow);
}

_node_ptr parser::create_embedded_node(std::string cont, bool min, bool div, bool pow) {
	_node_ptr root_branch = create_embedded_branch(std::move(cont));
	embedded_ptr new_embd = std::make_shared<node::embedded_node>(root_branch, min, div, pow);
	root_branch->set_prev_node(new_embd);
	return new_embd;
}

_node_ptr parser::create_constant_node(const std::string& name, bool min, bool div, bool pow) {
	int id_const = c_man->get_id(name);
	return std::make_shared<node::constant_node>(c_man, id_const, min, div, pow);
}

_node_ptr parser::create_function_node(std::string name, const std::vector<std::string>& args_str, bool min, bool div, bool pow) {
	int id_func = f_man->get_id_func(std::move(name));
	std::vector<_node_ptr> args;
	args.reserve(args_str.size());
	for(auto & j : args_str) {
		args.push_back( (create_embedded_branch(j)) );
	}
	function_ptr new_func = std::make_shared<node::function_node>(f_man, id_func, args, min, div, pow);
	
	return new_func;
}

_node_ptr parser::get_root() {
	return this->root;
}
