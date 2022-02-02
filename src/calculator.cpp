#include "../lib/calculator.h"

using namespace calculator;

calc::calc() {
	f_man = std::make_shared<manager::function_manager>();
	c_man = std::make_shared<manager::constant_manager>();
}

void calc::parse(std::string str) {
	checker checker(str);
	std::string err = checker.get_err();
	if(err.empty()) {
		parser parser(f_man, c_man);
		node_ptr root = parser.parse(str);
		simplifier smp;

		std::cout << root->display();
		std::cout << " = " << root->enumerate() << std::endl;

//		std::cout << "simplifying...\n";
//		smp.simplify_all(root);
//
//		std::cout << root->display();
//		std::cout << " = " << root->enumerate() << std::endl;
	} else {
		throw std::logic_error(err);
	}
}
