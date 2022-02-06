#include "../../lib/node/int_node.h"

using namespace calculator::node;

int_node::int_node(const uint64_t& x, bool min, bool div, bool pow) :
		math_node(min, div, pow) {
	set_type(Int);
	set_cont(x);
}

void int_node::set_cont(uint64_t x) {
	this->cont = x;
}

const uint64_t& int_node::get_cont() {
	return this->cont;
}

calculator::int_ptr int_node::operator=(calculator::_node_ptr ptr) {
	return std::static_pointer_cast<int_node>(ptr);
}

calculator::dong int_node::get_val() {
	calculator::dong value = this->get_cont();
	if(this->is_min()) {
		value *= -1;
	}
	if(this->is_div()) {
		value = 1 / value;
	}
	return value;
}

std::string int_node::disp_val() {
	return std::to_string(this->get_cont());
}


