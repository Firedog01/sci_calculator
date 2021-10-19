#include <vector>
#include <cmath>
#include <stdexcept>
#include "../includes.h"

class abstract_function 
{
public:
    virtual dong enumerate(std::vector<node_ptr> args) = 0;
};

