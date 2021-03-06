#ifndef MATH_NODE
#define MATH_NODE
/* flags
 * 0b0000000x - minus flag	  -
 * 0b000000x0 - division flag   /
 * 0b00000x00 - power flag	  ^
 * 0b00xxx000 - val flags:
 *	   000	    - Int
 *	   001	    - Embedded
 *	   010	    - Variable
 *	   011	    - Constant
 *	   100	    - Function
 *	   111	    - Undefined
 * 0b0x000000 - pair flag
 */

#include "../includes.h"
#include "../component/str_hdl.h"
#include <cmath>
#include <cstdint>
#include <string>
#include <utility>
#include <iostream>

namespace calculator {
	class simplifier;
}

namespace calculator::node {

	class math_node : public std::enable_shared_from_this<math_node>  {
		friend class calculator::simplifier;

		_node_ptr plus_node;
		_node_ptr mul_node;
		_node_ptr prev_node;
		uint8_t flags;

		void set_flag(bool val, int disp);
		virtual dong get_val();
		virtual std::string disp_val();

		void set_flags(uint8_t flags);
		uint8_t get_flags() const;

	public:
		math_node(bool min, bool div, bool pow);
		~math_node() = default;

		_node_ptr get_plus_node();
		void set_plus_node(_node_ptr node);
		_node_ptr get_mul_node();
		void set_mul_node(_node_ptr node);
		_node_ptr get_prev_node();
		void set_prev_node(_node_ptr node);

		bool is_min() const;
		void set_min(bool val);
		bool is_div() const;
		void set_div(bool val);
		bool is_pow() const;
		void set_pow(bool val);
		bool is_pair() const;
		void set_pair(bool val);

		old_node_type get_type() const;
		void set_type(old_node_type type);

		//util
		dong enumerate();
		std::string display();
		_node_ptr get_root();
	};
}
#endif

