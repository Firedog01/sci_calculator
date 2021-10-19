#include "math_node.h"
#include "../../functions/lib/sin.h"
#include <vector>

class function_node : public math_node
{
    std::vector<node_ptr> args;
    int id_func;
    fpt func;
public:
    function_node(int id_func, std::vector<node_ptr> args, fpt func, bool min, bool div, bool pow);
    int get_id_func();
    node_ptr get_embed(int pos);
    std::vector<node_ptr> get_args();
    dong enumerate();
};