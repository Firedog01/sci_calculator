#include "math_node.h"

class function_node : public math_node
{
    std::string cont;
    int id_func;
public:
    function_node(int id_func, bool min, bool div, bool pow);
    std::string get_func();
    void set_func(int id);
    long double enumerate();
    std::string get_cont();
    void set_cont(std::string cont);
};