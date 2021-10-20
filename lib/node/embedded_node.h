#ifndef EMBEDDED_NODE
#define EMBEDDED_NODE

#include "math_node.h"

class embedded_node : public math_node {
    node_ptr cont;
public:
    embedded_node(node_ptr x, bool min, bool div, bool pow);
    
    void set_cont(node_ptr x);
    const node_ptr& get_cont();
};
#endif