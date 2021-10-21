#ifndef INCLUDES
#define INCLUDES
#include <memory>
#include <vector>

//node pointers
class math_node;
class int_node;
class embedded_node;
class constant_node;
class function_node;
typedef std::shared_ptr<math_node> node_ptr;
typedef std::shared_ptr<int_node> int_ptr;
typedef std::shared_ptr<embedded_node> embedded_ptr;
typedef std::shared_ptr<constant_node> constant_ptr;
typedef std::shared_ptr<function_node> function_ptr;

//stronke
typedef long double dong;

// pointer to function implementation
typedef dong (*fpt)(std::vector<node_ptr>);

//needed by parser
enum op {add, mul, def};

class syntax_error : public std::logic_error {};

#endif