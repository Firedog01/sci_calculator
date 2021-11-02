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

function_node::function_node(f_man_ptr f_man, int func_id, vector<node_ptr> args, bool min, bool div, bool pow) :
        math_node(min, div, pow), args(move(args)), id_func(func_id), f_man(f_man) {
    set_type(4);
}

dong function_node::get_val() {
    dong value = f_man->enumerate(id_func, args);
    if(this->is_min()) {
        value *= -1;
    }
    if(this->is_div()) {
        value = 1 / value;
    }
    return value;
}
