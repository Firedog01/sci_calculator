//
// Created by janru on 05.02.2022.
//

#include "../../lib/manager/tree_manager.h"

using namespace calculator;

std::string manager::tree_manager::display() {
    return std::string();
}

dong manager::tree_manager::enumerate() {
    return 0;
}


op_type manager::tree_manager::get_op(const node_ptr& node) {
    uint8_t flags = node->get_flags();
    return (op_type)(flags & (0b111 << 3) );
}

nd_type manager::tree_manager::get_type(const node_ptr& node) {
    return integer;
}

void manager::tree_manager::append_to(node_ptr base, node_ptr append, bool isEmb) {

}

node_ptr manager::tree_manager::create_node(nd_type type) {
    return calculator::node_ptr();
}

node_ptr manager::tree_manager::get_root() {
    return root;
}

void manager::tree_manager::set_root(node_ptr node) {
    root = node;
}
