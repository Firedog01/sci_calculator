//
// Created by janru on 05.02.2022.
//

#ifndef SCI_CALCULATOR_NODE_H
#define SCI_CALCULATOR_NODE_H

#include "../includes.h"
#include "../component/str_hdl.h"
#include <cmath>
#include <cstdint>
#include <string>
#include <utility>
#include <iostream>

namespace calculator::node {
    class node : public std::enable_shared_from_this<node>  {

        node_ptr next;
        node_ptr emb;
        uint8_t flags;
    public:
        node():
            next(nullptr), emb(nullptr), flags(0) {};
        explicit node(uint8_t flags):
            next(nullptr), emb(nullptr), flags(flags) {};
        ~node() = default;

        node_ptr get_next();
        node_ptr get_emb();
        void set_next(node_ptr node);
        void set_emb(node_ptr node);

        uint8_t get_flags();
        void set_flags(uint8_t flags);
    };
}

#endif //SCI_CALCULATOR_NODE_H
