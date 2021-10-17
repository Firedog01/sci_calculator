#include "../lib/function_node.h"

function_node::function_node(int id_func, bool min, bool div, bool pow):
        math_node(min, div, pow) {
    set_func(id_func);
}
// std::string function_node::get_func();
void function_node::set_func(int id) {
    this->id_func = id;
}
// long double function_node::enumerate();
// std::string function_node::get_cont();
// void function_node::set_cont(std::string cont);