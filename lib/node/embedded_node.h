#ifndef EMBEDDED_NODE
#define EMBEDDED_NODE

#include "math_node.h"
#include "../component/str_hdl.h"

class embedded_node : public math_node {
    node_ptr cont;

    virtual dong get_val();
    virtual std::string disp_val();
public:
    embedded_node(node_ptr x, bool min, bool div, bool pow);
    
    void set_cont(node_ptr x);
    const node_ptr& get_cont();
};
#endif