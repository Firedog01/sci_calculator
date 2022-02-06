#ifndef INT_NODE
#define INT_NODE
#include "math_node.h"

namespace calculator::node {

	class int_node : public math_node{
		uint64_t cont;

		virtual calculator::dong get_val();
		virtual std::string disp_val(); 
	public:
		int_node(const uint64_t& x, bool min, bool div, bool pow);

		void set_cont(uint64_t x);
		const uint64_t& get_cont();

		calculator::int_ptr operator=(calculator::_node_ptr);
	};

}
#endif 