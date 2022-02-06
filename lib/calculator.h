#ifndef CALCULATOR
#define CALCULATOR

#include "component/parser.h"
#include "component/checker.h"
#include "component/simplifier.h"
#include "component/parser2.h"
/*
todo
	dodać prev_node do math_node
 */
namespace calculator {

	class calc
	{
		f_man_ptr f_man;
		c_man_ptr c_man;
		parser_ptr parser;

		simplifier_ptr simplifier;
//		checker_ptr checker;
	public:
		calc();
		void parse(const std::string& str);
	};

}
/*
assumptions:
	2^3*4 = (2^3)*4
	2/3*4 = (2/3)*4
	2+^3 = 2^3
 */
#endif