#ifndef CONSTANT_NODE
#define CONSTANT_NODE

#include "math_node.h"
#include "../manager/constant_manager.h"

class constant_node : public math_node
{
	int id_const;
	c_man_ptr c_man;

	virtual dong get_val();
	virtual std::string disp_val();
public:
	constant_node(c_man_ptr c_man, int id_const, bool min, bool div, bool pow);
	int get_id_const();
	void set_id_const(int id);
};
#endif