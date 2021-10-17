#include "../lib/embeded_node.h"

embeded_node::embeded_node(node_ptr x, bool min, bool div, bool pow) :
        math_node(min, div, pow) {
    set_type(1);
    set_cont(x);
}

void embeded_node::set_cont(node_ptr x) {
    this->cont = x;
}

const node_ptr& embeded_node::get_cont() {
    return this->cont;
}