#include "../lib/calculator.h"

using namespace std;

calculator::calc::calc() {
	f_man = make_shared<manager::function_manager>();
	c_man = make_shared<manager::constant_manager>();
	parser = make_shared<calculator::parser>(f_man, c_man);
	simplifier = make_shared <calculator::simplifier>();
//	checker
}

void calculator::calc::parse(const string& str) {
	checker checker(str);
    parser2 parser2(f_man, c_man);

	string err = checker.get_err();
	if(err.empty()) {
		
		_node_ptr root = parser->parse(str);
        node_ptr toot = parser2.parse(str);
		
		cout << "before: " << root->display() << " = " << root->enumerate() << "\n";
		cout << "alt:    " <<
        simplifier->simplify_all(root);
		cout << "after:  " << root->display() << " = " << root->enumerate() << "\n";
	} else {
		throw logic_error(err);
	}
}
