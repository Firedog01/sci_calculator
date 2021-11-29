#ifndef CALCULATOR
#define CALCULATOR

#include "component/parser.h"
#include "component/checker.h"
#include "component/simplifier.h"
/*
todo
	dodać prev_node do math_node
 */
namespace calculator {

	class calc
	{
		f_man_ptr f_man;
		c_man_ptr c_man;
	public:
		calc();
		void parse(std::string str);
	};

}
/*
assumptions:
	2^3*4 = (2^3)*4
	2/3*4 = (2/3)*4
	2+^3 = 2^3
 */
#endif