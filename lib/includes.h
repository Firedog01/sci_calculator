#ifndef INCLUDES
#define INCLUDES
#include <memory>
#include <vector>

#define CASE_NUMBER case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':

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