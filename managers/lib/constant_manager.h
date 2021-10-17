#include "../../node/lib/constant_node.h"
#include <vector>
#include <fstream>

//todo check if works

struct constants {
    int id;
    std::string name;
    long double value;

    constants(int id, std::string name, long double value);
};

class constant_manager 
{
    std::vector<constants> const_list;

    std::string get_field(std::string str, int& i);
public:
    constant_manager();
    std::string get_name(int id);
    long double get_value(constant_ptr node);
    long double get_value(int id);
    int get_id(std::string name);
};