#include "../../lib/component/str_hdl.h"

using namespace std;

void str_hdl::remove_spaces(string& str) {
    string replace;
    for(char i : str) {
        if(i != ' ') {
            replace += i;
        }
    }
    str = replace;
}

string str_hdl::get_num(string str, int& i) {
    string num;
    while(str[i] >= '0' && str[i] <= '9') {
        num += str[i];
        i++;
    }
    return num;
}

string str_hdl::get_embedded(string str, int& i) {
    string embedded;
    int brackets = 1; // +1 for opening -1 for closing

    i++;
    do {
        if(str[i] == ')') {
            brackets--;
        }
        if(str[i] == '(') {
            brackets++;
        }
        embedded += str[i];
        i++;
    } while(brackets > 0);
    embedded.pop_back();
    return embedded;
}

string str_hdl::get_name(string str, int& i) {
    string name;
    while(check_name_character(str[i])) {
        name += str[i];
        i++;
    }
    return name;
}

vector<string> str_hdl::get_func_args(string str, int &i) {
    vector<string> ret;
    string func_cont = get_embedded(str, i), arg;
    for(int j = 0; j < func_cont.length(); j++) {
        if(func_cont[j] == F_ARG_DELIM) {
            ret.push_back(arg);
            arg = "";
        } else {
            arg += func_cont[j];
        }
    }
    ret.push_back(arg);
    return ret;
}

bool str_hdl::check_name_character(char c) {
    bool check = false;
    if(c >= 'a' && c <='z') {
        check = true;
    }
    if(c == '_') {
        check = true;
    }
    return check;
}

bool str_hdl::check_after_operator_character(char c) {
    bool check = false;
    if(c >= '0' && c <= '9') {
        check = true;
    }
    if(c == CONST_C) {
        check = true;
    }
    if(c == FUNC_C) {
        check = true;
    }
    if(c == C_BRACKET_C || c == O_BRACKET_C) {
        check = true;
    }
    return check;
}

bool str_hdl::check_operator(char c) {
    bool check = false;
    if(c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
        check = true;
    }
    return check;
}


