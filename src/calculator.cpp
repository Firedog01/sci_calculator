#include "../lib/calculator.h"

using namespace std;

calculator::calculator() {

}

void calculator::parse(string str) {
    checker checker(str);
    if(checker.is_good()) {
        parser parser(str);
    } else {
        string err = checker.syntax_check_verboose();
        throw new logic_error(err);
    }
}