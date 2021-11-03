#include "../../lib/node/math_node.h"

#include <utility>


math_node::math_node(bool min, bool div, bool pow): 
        plus_node(nullptr), mul_node(nullptr), flags(0) {
    set_min(min);
    set_div(div);
    set_pow(pow);
    set_type(7);
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


void math_node::set_flag(bool val, int disp) {
    flags = ((flags & ~(1 << disp)) | (val << disp));
}


void math_node::set_plus_node(node_ptr node) {
    this->plus_node = std::move(node);
}
node_ptr math_node::get_plus_node() {
    return this->plus_node;
}

void math_node::set_mul_node(node_ptr node) {
    this->mul_node = std::move(node);
}
node_ptr math_node::get_mul_node() {
    return this->mul_node;
}
using namespace std;


string math_node::get_type() const {
    string ret;
    char flag = this->flags >> 3 & 7;
    switch(flag) {
        case 0:
        ret = "int";
        break;

        case 1:
        ret = "embedded";
        break;
        
        case 2:
        ret = "variable";
        break;
        
        case 3:
        ret = "constant";
        break;
        
        case 4:
        ret = "function";
        break;
        
        default:
        ret = "undefined";
    }
    return ret;
}

void math_node::set_type(uint8_t val) {
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



