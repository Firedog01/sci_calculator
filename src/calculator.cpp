#include "../lib/calculator.h"

using namespace std;

calculator::calculator() {

}

void calculator::parse(string str) {
    checker checker(str);
    string err = checker.get_err();
    if(err.empty()) {
        simplifier smp;
        parser parser(str);
        node_ptr root = parser.getRoot();

        parser.test();
        smp.simplify_all(root);
        parser.test();
    } else {
        throw logic_error(err);
    }
}

