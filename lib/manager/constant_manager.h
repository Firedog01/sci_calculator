#ifndef CONSTANT_MANAGER
#define CONSTANT_MANAGER

#include "../node/constant_node.h"
#include <vector>
#include <fstream>

struct constants {
    int id;
    std::string name;
    dong value;

    constants(int id, std::string name, dong value);
};

class constant_manager 
{
    std::vector<constants> const_list;

    std::string get_field(std::string str, int& i);
public:
    constant_manager();
    std::string get_name(int id);
    dong get_value(constant_ptr node);
    dong get_value(int id);
    int get_id(std::string name);
};
#endif