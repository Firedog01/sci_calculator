#ifndef SING
#define SING

#include <vector>
#include <cmath>
#include <stdexcept>
#include "../includes.h"
#include "../manager/tree_manager.h"
#include "abstr_function.h"

struct sin_f : abstr_function {
    virtual dong enumerate(std::vector<node_ptr> args);
};
#endif
