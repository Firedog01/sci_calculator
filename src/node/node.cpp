//
// Created by janru on 05.02.2022.
//

#include "../../lib/node/node.h"

#include <utility>

namespace calculator::node {

    node_ptr node::get_next() {
        return next;
    }

    node_ptr node::get_emb() {
        return emb;
    }

    void node::set_next(node_ptr node) {
        next = node;
    }

    void node::set_emb(node_ptr node) {
        emb = node;
    }

    uint8_t node::get_flags() {
        return flags;
    }

    void node::set_flags(uint8_t _flags) {
        flags = _flags;
    }
}
