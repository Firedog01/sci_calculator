#include "../../lib/node/int_node.h"

int_node::int_node(const uint64_t& x, bool min, bool div, bool pow) :
        math_node(min, div, pow) {
    set_type(0);
    set_cont(x);
}

void int_node::set_cont(uint64_t x) {
    this->cont = x;
}

const uint64_t& int_node::get_cont() {
    return this->cont;
}

int_ptr int_node::operator=(node_ptr ptr) {
    return std::static_pointer_cast<int_node>(ptr);
}
