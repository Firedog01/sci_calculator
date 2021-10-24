#include "../../lib/node/function_node.h"



using namespace std;


node_ptr function_node::get_embedded(int pos) {
    if(pos >= 0 && pos <= args.size()) 
        return args.at(pos);
    else 
        return nullptr;
}

vector<node_ptr> function_node::get_args() {
    return args;
}

int function_node::get_id_func() {
    return id_func;
}


function_node::function_node(int func_id, vector<node_ptr> args, bool min, bool div, bool pow) :
        math_node(min, div, pow), args(move(args)), id_func(func_id) {
    set_type(4);
}


