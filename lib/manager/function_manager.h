#ifndef FUNCTION_MANAGER
#define FUNCTION_MANAGER
#include "../node/function_node.h"
#include "../func/abstract_function.h"

struct function {
    int id;
    std::string name;
    fpt ptr;

    function(int id, std::string name, fpt ptr);
};

class function_manager
{
    std::vector<function> funcs;
public:
    function_manager();
    std::string get_name(int id);
    int get_id(std::string name);
};
#endif