#ifndef FUNCTION_MANAGER
#define FUNCTION_MANAGER

#include <memory>

#include "../func/abstr_function.h"
#include "../func/sin_f.h"

struct function {
    int id;
    std::string name;
    abstr_function func;

    function(int id, std::string name, abstr_function func);
};

class function_manager
{
    std::vector<function> funcs;
public:
    function_manager();
    std::string get_name(int id);
    int get_id_func(std::string name);
    dong enumerate(int id, std::vector<node_ptr> args);
};


#endif