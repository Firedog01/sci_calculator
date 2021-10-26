#ifndef ABSTR_FUNCTION_H
#define ABSTR_FUNCTION_H

#include "../includes.h"
#include <vector>

struct abstr_function {
    virtual dong enumerate(std::vector<node_ptr> args) {
        return 0;
    }
};


#endif