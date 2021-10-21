#include "../../lib/component/checker.h"

using namespace std;

string checker::operator_check() {
    string err;

//    if(string_handling::check_operator(str[0])) { // nie zaczyna się operatorem
//        err += "Początkowy operator będzie zignorowany\n";
//    }
    string operators;
    for(char i : str) {
        if(string_handling::check_operator(i)) {
            operators += i;
        } else {
            if(!operators.empty()) {
                operators = "";
            }
        }
    }
    if(!operators.empty()) {
        err += "Operator na końcu nie ma liczby";
    }
    return err;
}

string checker::brackets_check() {
    string err;
    int bracket = 0;
    for(char i : str) {
        if(i == '(') {
            bracket++;
        }
        if(i == ')') {
            bracket--;
        }
    }
    if(bracket != 0) {
        err += "Niezamknięty nawias";
    }
    return err;
}

string checker::numbers_check() {
    string err;
    int bracket = 0;
    for(char i : str) {
        if(i == '(') {
            bracket++;
        }
        if(i == ')') {
            bracket--;
        }
    }
    return err;
}


checker::checker(string str) : str(str) {}

string checker::get_err() {
    string err;
    err += operator_check();
    err += brackets_check();
    return err;
}






