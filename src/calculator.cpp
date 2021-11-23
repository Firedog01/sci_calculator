#include "../lib/calculator.h"

using namespace std;

calculator::calculator() {
	f_man = make_shared<function_manager>();
	c_man = make_shared<constant_manager>();
}

void calculator::parse(string str) {
	checker checker(str);
	string err = checker.get_err();
	if(err.empty()) {
		parser parser(f_man, c_man);
		node_ptr root = parser.parse(str);
		simplifier smp;

		cout << root->display();
		cout << " = " << root->enumerate() << endl;

		cout << "simplifying...\n";
		smp.simplify_all(root);

		cout << root->display();
		cout << " = " << root->enumerate() << endl;
	} else {
		throw logic_error(err);
	}
}

