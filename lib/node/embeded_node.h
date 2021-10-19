#include "math_node.h"

class embeded_node : public math_node {
    node_ptr cont;
public:
    embeded_node(node_ptr x, bool min, bool div, bool pow);
    
    void set_cont(node_ptr x);
    const node_ptr& get_cont();
};