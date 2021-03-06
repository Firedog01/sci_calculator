#ifndef SING
#define SING

#include <vector>
#include <cmath>
#include <stdexcept>
#include "../includes.h"
#include "../node/function_node.h"
#include "abstr_function.h"

namespace calculator { namespace func {

struct sin_f : abstr_function {
	virtual dong enumerate(std::vector<_node_ptr> args);
};

} }
#endif
