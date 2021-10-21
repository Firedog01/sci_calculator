#include "../lib/calculator.h"

using namespace std;

calculator::calculator() {

}

void calculator::parse(string str) {
    checker checker(str);
    string err = checker.get_err();
    if(err.empty()) {
        parser parser(str);
        parser.test();
    } else {
        throw logic_error(err);
    }
}


