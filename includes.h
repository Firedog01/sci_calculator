#ifndef INCLUDES
#define INCLUDES
#include <memory>
#include <vector>

class math_node;
class int_node;
class embeded_node;
class constant_node;
class function_node;

typedef std::shared_ptr<math_node> node_ptr;
typedef std::shared_ptr<int_node> int_ptr;
typedef std::shared_ptr<embeded_node> embeded_ptr;
typedef std::shared_ptr<constant_node> constant_ptr;
typedef std::shared_ptr<function_node> function_ptr;

typedef long double dong;

// pointer to function implementation
typedef dong (*fpt)(std::vector<node_ptr>);

enum op {add, mul, def};

#endif