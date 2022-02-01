#include "../../lib/node/embedded_node.h"

using namespace calculator::node;

embedded_node::embedded_node(node_ptr x, bool min, bool div, bool pow) :
		math_node(min, div, pow) {
	set_type(Embedded);
	set_cont(std::move(x));
	//wyrzucić z konstruktora
    //x->set_prev_node(math_node::shared_from_this());
}

void embedded_node::set_cont(node_ptr x) {
	this->cont = std::move(x);
}

const calculator::node_ptr& embedded_node::get_cont() {
	return this->cont;
}

calculator::dong embedded_node::get_val() {
	dong value = this->get_cont()->enumerate();
	if(this->is_min()) {
		value *= -1;
	}
	if(this->is_div()) {
		value = 1 / value;
	}
	return value;
}

std::string embedded_node::disp_val() {
	std::string ret;
	ret += str_hdl::O_BRACKET_C;
//	ret += "emb";
	ret += get_cont()->display();
	ret += str_hdl::C_BRACKET_C;
	return ret;
}
