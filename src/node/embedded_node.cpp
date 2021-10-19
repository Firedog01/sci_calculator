#include "../../lib/node/embedded_node.h"

embedded_node::embedded_node(node_ptr x, bool min, bool div, bool pow) :
        math_node(min, div, pow) {
    set_type(1);
    set_cont(x);
}

void embedded_node::set_cont(node_ptr x) {
    this->cont = x;
}

const node_ptr& embedded_node::get_cont() {
    return this->cont;
}