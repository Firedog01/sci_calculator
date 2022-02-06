#ifndef INCLUDES
#define INCLUDES
#define CASE_DIGIT case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':

#include <memory>
#include <vector>
#include <exception>

namespace calculator {

    //node pointers
    namespace node {
        class math_node;
        class int_node;
        class embedded_node;
        class constant_node;
        class function_node;

        class node;
    }
    typedef std::shared_ptr<node::math_node> _node_ptr;
    typedef std::shared_ptr<node::int_node> int_ptr;
    typedef std::shared_ptr<node::embedded_node> embedded_ptr;
    typedef std::shared_ptr<node::constant_node> constant_ptr;
    typedef std::shared_ptr<node::function_node> function_ptr;

    typedef std::shared_ptr<node::node> node_ptr;

    //observer/observee pointers
    namespace node::observer {
        class node_obervee;
        class update_tree;
    }
    typedef std::shared_ptr<node::observer::node_obervee> node_observee_ptr;
    typedef std::shared_ptr<node::observer::update_tree> update_tree_ptr;

    //func pointers
    namespace func {
        class sin_f;  
        class abstr_function;
    }
    typedef std::shared_ptr<func::sin_f> sin_f_ptr;
    typedef std::shared_ptr<func::abstr_function> abstr_function_ptr;
    
    //managers pointers
    namespace manager {
        class function_manager;
        class constant_manager;
    }
    typedef std::shared_ptr<manager::function_manager> f_man_ptr;
    typedef std::shared_ptr<manager::constant_manager> c_man_ptr;

	//component pointers
	class parser;
	class simplifier;
	class checker;
	typedef std::shared_ptr<calculator::parser> parser_ptr;
	typedef std::shared_ptr<calculator::simplifier> simplifier_ptr;
	typedef std::shared_ptr<calculator::checker> checker_ptr;
	
    
    //stronke
    typedef long double dong;

    // pointer to function implementation  --- unused ---
    typedef dong (*fpt)(std::vector<_node_ptr>);

    //needed by parser
    enum op {add_, mul_, def_}; // todo refactor
    enum old_node_type {
        Int = 0,
        Embedded,
        Function,
        Constant,
        Variable,
        Undefined = 7
    };

    enum nd_type {
        integer  = 0b000,
        variable = 0b001,
        constant = 0b010,
        function = 0b011,

        ambiguous = 0b111
    };
    enum op_type {
        add = 0b000,
        min = 0b001,
        mul = 0b010,
        div = 0b011,
        pow = 0b100,
        rot = 0b101,

        amb = 0b111
    };
}
#endif