#ifndef SING
#define SING

#include <vector>
#include <cmath>
#include <stdexcept>
#include "../includes.h"
#include "../node/function_node.h"
#include "abstr_function.h"

namespace calculator::func {

struct sin_f : abstr_function {
	virtual dong enumerate(std::vector<node_ptr> args);
};

}
#endif
