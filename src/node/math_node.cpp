#include "../../lib/node/math_node.h"

#include <utility>


math_node::math_node(bool min, bool div, bool pow): 
		plus_node(nullptr), mul_node(nullptr), prev_node(nullptr), flags(0) {
	prev_node = nullptr; //?
	set_min(min);
	set_div(div);
	set_pow(pow);
	set_type(Undefined);
}

math_node::~math_node() {
	// std::cout << "a\n";
}



void math_node::set_flags(uint8_t flags) {
	this->flags = flags;
}

uint8_t math_node::get_flags() const {
	return flags;
}


bool math_node::is_min() const {
	return (flags & (1 << 0));
}

void math_node::set_min(bool val) {
	set_flag(val, 0);
}


bool math_node::is_div() const {
	return (flags & (1 << 1));
}

void math_node::set_div(bool val) {
	set_flag(val, 1);
}


bool math_node::is_pow() const {
	return (flags & (1 << 2));
}

void math_node::set_pow(bool val) {
	set_flag(val, 2);
}

bool math_node::is_pair() const {
	return (flags & (1 << 6));
}

void math_node::set_pair(bool val) {
	set_flag(val, 6);
}


void math_node::set_flag(bool val, int disp) {
	flags = ((flags & ~(1 << disp)) | (val << disp));
}


void math_node::set_plus_node(node_ptr node) {
	this->plus_node = node;
	if(node != nullptr) {
		this->plus_node->set_prev_node(shared_from_this());
	}
}
node_ptr math_node::get_plus_node() {
	return this->plus_node;
}

void math_node::set_mul_node(node_ptr node) {
	this->mul_node = node;
	if(node != nullptr) {
		this->mul_node->set_prev_node(shared_from_this());
	}
}
node_ptr math_node::get_mul_node() {
	return this->mul_node;
}

void math_node::set_prev_node(node_ptr node) {
	this->prev_node = node;
}
node_ptr math_node::get_prev_node() {
	return this->prev_node;
}

using namespace std;


node_type math_node::get_type() const {
	string ret;
	char flag = this->flags >> 3 & 7;
	switch(flag) {
		case 0:
			return Int;
		case 1:
			return Embedded;
		case 2:
			return Variable;
		case 3:
			return Constant;
		case 4:
			return Function;
		default:
			return Undefined;
	}
}

void math_node::set_type(node_type type) {
	uint8_t val = (uint8_t)(type);
	if(val > 7) {
		val = 7;
	}
	this->flags = ((flags & ~(7 << 3)) | (val << 3));
}

dong math_node::get_val() {
	return -1;
}

std::string math_node::disp_val() {
	return "not defined";
}

dong math_node::enumerate() {
	dong ret_val = this->get_val();
	// cout << "ret_val: " << ret_val << endl;
	if(mul_node != nullptr) {
		if(mul_node->is_pow()) {
			ret_val = pow(ret_val, mul_node->get_val());
			ret_val *= mul_node->get_mul_node()->enumerate();
		} else {
			ret_val *= mul_node->enumerate();
		}
	}
	if(plus_node != nullptr) {
		if(plus_node->is_pow()) {
			// syntax error
		} else {
			ret_val += plus_node->enumerate();
		}
	}

	return ret_val;
}

std::string math_node::display() {
	std::string ret;
	if(prev_node == nullptr) {
		if(is_div() || is_pow()) {
			ret += str_hdl::get_op(mul, is_min(), is_div(), is_pow());
		} else if(is_min()) {
			ret += str_hdl::get_op(add, is_min(), is_div(), is_pow());
		}
	} else if(prev_node->get_type() == Embedded) {
		if(is_div() || is_pow()) {
			ret += str_hdl::get_op(mul, is_min(), is_div(), is_pow());
		} else if(is_min()) {
			ret += str_hdl::get_op(add, is_min(), is_div(), is_pow());
		}
	}
	ret += this->disp_val();

	if(get_mul_node() != nullptr) {
		node_ptr mul_node = get_mul_node();
		ret += str_hdl::get_op(mul, mul_node->is_min(), mul_node->is_div(), mul_node->is_pow());
		ret += mul_node->display();
	}
	if(get_plus_node() != nullptr) {
		node_ptr plus_node = get_plus_node();
		ret += str_hdl::get_op(add, plus_node->is_min(), plus_node->is_div(), plus_node->is_pow());
		ret += plus_node->display();
	}
	return ret;
}

node_ptr math_node::get_root() {
	// std::cout << "a\n";
	if(get_prev_node() == nullptr) {
		// cout << "b\n";
		return shared_from_this();
	} else {
		// cout << "c " << get_prev_node() << "\n";
		return get_prev_node()->get_root();
	}
}

