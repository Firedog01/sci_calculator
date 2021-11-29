#include "../../lib/node/function_node.h"

using namespace calculator::node;


calculator::node_ptr function_node::get_embedded(int pos) {
	if(pos >= 0 && pos <= args.size()) 
		return args.at(pos);
	else 
		return nullptr;
}

std::vector<calculator::node_ptr> function_node::get_args() {
	return args;
}

int function_node::get_id_func() {
	return id_func;
}

function_node::function_node(f_man_ptr f_man, int func_id, std::vector<node_ptr> args, bool min, bool div, bool pow) :
		math_node(min, div, pow), args(move(args)), id_func(func_id), f_man(f_man) {
	set_type(Function);
}

calculator::dong function_node::get_val() {
	dong value = f_man->enumerate(id_func, args);
	if(this->is_min()) {
		value *= -1;
	}
	if(this->is_div()) {
		value = 1 / value;
	}
	return value;
}

std::string function_node::disp_val() {
	std::string ret;
	ret += f_man->get_name(get_id_func());
	ret += str_hdl::O_BRACKET_C;
	if(args.size() > 0) {
		ret += args.at(0)->display();
	}
	for(int i = 1; i < args.size(); i++) {
		ret += str_hdl::F_ARG_DELIM;
		ret += args.at(i)->display();
	}
	ret += str_hdl::C_BRACKET_C;
	return ret;
}
