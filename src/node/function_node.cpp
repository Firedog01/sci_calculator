#include "../../lib/node/function_node.h"

using namespace std;

function_node::function_node(int id_func, std::vector<node_ptr> args, fpt func, bool min, bool div, bool pow):
        math_node(min, div, pow), id_func(id_func), args(args), func(func) {}

int function_node::get_id_func() {
    return id_func;
}

node_ptr function_node::get_embed(int pos) {
    if(pos >= 0 && pos <= args.size()) 
        return args.at(pos);
    else 
        return nullptr;
}

vector<node_ptr> function_node::get_args() {
    return args;
}

dong function_node::enumerate() {
    return (*func)(get_args());
}
