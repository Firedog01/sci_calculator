#ifndef FUNCTION_NODE
#define FUNCTION_NODE
#include <vector>
#include <utility>

#include "math_node.h"
#include "../manager/function_manager.h"

namespace calculator::node {

	class function_node : public math_node
	{
		std::vector<_node_ptr> args;
		int id_func;
		f_man_ptr f_man;

		virtual dong get_val();
		virtual std::string disp_val();
	public:
		function_node(f_man_ptr f_man, int id_func, std::vector<_node_ptr> args, bool min, bool div, bool pow);
		_node_ptr get_embedded(int pos);
		std::vector<_node_ptr> get_args();
		int get_id_func();
	};

}
#endif