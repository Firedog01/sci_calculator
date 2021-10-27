#ifndef INCLUDES
#define INCLUDES
#include <memory>
#include <vector>
#include <exception>

#define CASE_DIGIT case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':

//node pointers
class math_node;
typedef std::shared_ptr<math_node> node_ptr;
class int_node;
typedef std::shared_ptr<int_node> int_ptr;
class embedded_node;
typedef std::shared_ptr<embedded_node> embedded_ptr;
class constant_node;
typedef std::shared_ptr<constant_node> constant_ptr;
class function_node;
typedef std::shared_ptr<function_node> function_ptr;

//func pointers
class sin_f;
typedef std::shared_ptr<sin_f> sin_f_ptr;

//stronke
typedef long double dong;

// pointer to function implementation  --- unused ---
typedef dong (*fpt)(std::vector<node_ptr>);

//needed by parser
enum op {add, mul, def};

//managers pointers
class function_manager;
typedef std::shared_ptr<function_manager> f_man_ptr;
class constant_manager;
typedef std::shared_ptr<constant_manager> c_man_ptr;
#endif