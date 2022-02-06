#ifndef EMBEDDED_NODE
#define EMBEDDED_NODE

#include "math_node.h"
#include "../component/str_hdl.h"

namespace calculator::node {

	// embedded branch root needs to be set manually to prev_node
	class embedded_node : public calculator::node::math_node {
		_node_ptr cont;

		virtual dong get_val();
		virtual std::string disp_val();
	public:
		embedded_node(_node_ptr x, bool min, bool div, bool pow);
		
		void set_cont(_node_ptr x);
		const _node_ptr& get_cont();
	};

}
#endif