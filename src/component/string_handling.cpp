#include "../../lib/component/string_handling.h"

using namespace std;

void string_handling::remove_spaces(string& str) {
    string replace;
    for(char i : str) {
        if(i != ' ') {
            replace += i;
        }
    }
    str = replace;
}

string string_handling::get_num(string str, int& i) {
    string num;
    while(str[i] >= '0' && str[i] <= '9') {
        num += str[i];
        i++;
    }
    return num;
}

string string_handling::get_embedded(string str, int& i) {
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

string string_handling::get_name(string str, int& i) {
    string name;
    while(check_name_character(str[i])) {
        name += str[i];
        i++;
    }
    return name;
}

bool string_handling::check_name_character(char c) {
    bool check = false;
    if(c >= 'a' && c <='z') {
        check = true;
    }
    if(c == '_') {
        check = true;
    }
    return check;
}

bool string_handling::check_after_operator_character(char c) {
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
}