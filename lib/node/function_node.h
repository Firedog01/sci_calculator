#ifndef FUNCTION_NODE
#define FUNCTION_NODE

#include "math_node.h"
#include "../func/sin_f.h"
#include <vector>
#include <utility>

class function_node : public math_node
{
    std::vector<node_ptr> args;
    int id_func;
public:
    function_node(int id_func, std::vector<node_ptr> args, bool min, bool div, bool pow);
    node_ptr get_embedded(int pos);
    std::vector<node_ptr> get_args();
    int get_id_func();
};
#endif