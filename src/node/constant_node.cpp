#include "../../lib/node/constant_node.h"

constant_node::constant_node(int id_const, bool min, bool div, bool pow):
        id_const(id_const), math_node(min, div, pow) {
    set_type(3);
}
int constant_node::get_id_const() {
    return this->id_const;
}
void constant_node::set_id_const(int id) {
    this->id_const = id;
}