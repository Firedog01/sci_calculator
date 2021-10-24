#ifndef FUNCTION_MANAGER
#define FUNCTION_MANAGER
#include "../node/function_node.h"
#include "../func/sin_f.h"

struct function {
    int id;
    std::string name;
    fpt ptr;

    function(int id, std::string name, fpt ptr);
};

sin_f sin_class;

class function_manager
{
//    func::cos cos;

    std::vector<function> funcs;
public:
    function_manager();
    std::string get_name(int id);
    int get_id(std::string name);
    dong enumerate(std::string name, std::vector<node_ptr> args);
};
#endif