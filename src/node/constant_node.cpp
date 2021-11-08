#include "../../lib/node/constant_node.h"

constant_node::constant_node(c_man_ptr c_man, int id_const, bool min, bool div, bool pow):
		id_const(id_const), math_node(min, div, pow), c_man(c_man) {
	set_type(Constant);
}
int constant_node::get_id_const() {
	return this->id_const;
}
void constant_node::set_id_const(int id) {
	this->id_const = id;
}

dong constant_node::get_val() {
	dong value = c_man->get_value(id_const);
	if(this->is_min()) {
		value *= -1;
	}
	if(this->is_div()) {
		value = 1 / value;
	}
	return value;
}

std::string constant_node::disp_val() {
	return c_man->get_name(get_id_const());
}