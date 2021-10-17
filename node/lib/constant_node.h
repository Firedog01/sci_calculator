#ifndef CONSTANT_NODE
#define CONSTANT_NODE
#include "math_node.h"

class constant_node : public math_node
{
    int id_const;
public:
    constant_node(int id_const, bool min, bool div, bool pow);
    int get_id_const();
    void set_id_const(int id);
};
#endif