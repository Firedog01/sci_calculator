#ifndef INT_NODE
#define INT_NODE
#include "math_node.h"

class int_node : public math_node{
    uint64_t cont;

    virtual dong get_val();
public:
    int_node(const uint64_t& x, bool min, bool div, bool pow);

    void set_cont(uint64_t x);
    const uint64_t& get_cont();

    int_ptr operator=(node_ptr);
};
#endif 