#ifndef PARSER
#define PARSER

#include <string>
#include <limits>
#include <stdexcept>
#include <iostream>
#include <utility>

#include "str_hdl.h"

#include "../node/int_node.h"
#include "../node/embedded_node.h"
#include "../node/constant_node.h"
#include "../node/function_node.h"

namespace calculator {

	class parser {
	private:
		_node_ptr root;
		calculator::f_man_ptr f_man;
		c_man_ptr c_man;

		/**
		 * main creation function. Creates new branch for root or for embeded root
		 */
		_node_ptr create_embedded_branch(std::string str);

		_node_ptr create_node(std::string str, int& i, op& op);
		_node_ptr create_int_node(const std::string& cont, bool min, bool div, bool pow);
		_node_ptr create_embedded_node(std::string cont, bool min, bool div, bool pow);
		_node_ptr create_constant_node(const std::string& name, bool min, bool div, bool pow);
		_node_ptr create_function_node(std::string name, const std::vector<std::string>& args, bool min, bool div, bool pow);
		
	public:
		parser(f_man_ptr f_man, c_man_ptr c_man) : f_man(std::move(f_man)), c_man(std::move(c_man)) {}
		_node_ptr parse(std::string str);
		_node_ptr get_root();
	};

}
#endif