#include "../../lib/component/checker.h"

using namespace std;

string calculator::checker::operator_check() {
	string err;

//	if(str_hdl::check_operator(str[0])) { // nie zaczyna się operatorem
//		err += "Początkowy operator będzie zignorowany\n";
//	}
	string operators;
	for(char i : str) {
		if(str_hdl::check_operator(i)) {
			operators += i;
		} else {
			if(!operators.empty()) {
				operators = "";
			}
		}
	}
	if(!operators.empty()) {
		err += "Operator na końcu nie ma liczby\n";
	}
	return err;
}

string calculator::checker::brackets_check() {
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
		err += "Niezamknięty nawias\n";
	}
	return err;
}

string calculator::checker::numbers_check() {
	string err;
	for(int i = 0; i < str.length(); i++) {
		if(str[i] >= '0' && str[i] <= '9') {
			str_hdl::get_num(str, i);
			if(str[i] == ' ') { // liczby oddzielone spacją
				i++;
				if(str[i] >= '0' && str[i] <= '9') {
					err += "Dwie liczby odzdielone spacją\n";
				}
			}
		}
	}
	return err;
}

string calculator::checker::functions_check() {
	return "";
}

string calculator::checker::constants_check() {
	string err;
	for(int i = 0; i < str.length(); i++) {
		if(str[i] == str_hdl::CONST_C) {
			i++;
			string name = str_hdl::get_name(str, i);
			manager::constant_manager c_man;
			int id = c_man.get_id(name);
			if(id == -1) {
				err += "Constant not found: ";
				err += name;
				err += '\n';
			} else {
                cout << name << to_string(id) << "\n";
            }
		}
	}
	return err;
}

string calculator::checker::characters_check() {
	string err;
    string str = this->str;
    str_hdl::remove_spaces(str);

	for(int i = 0; i < str.length(); i++) {
		if(str_hdl::check_operator(str[i])) {
			do {
				i++;
			} while(str_hdl::check_operator(str[i]));
			switch(str[i]) {
				case str_hdl::CONST_C:
				case str_hdl::FUNC_C:
					i++;
					str_hdl::get_name(str, i);
					break;
				CASE_DIGIT
					str_hdl::get_num(str, i);
					break;
				case str_hdl::O_BRACKET_C:
				case str_hdl::C_BRACKET_C:
					i++;
					break;
				default:
					err += "Niewłaściwy znak: ";
					err += str[i];
					err += '\n';
			}
		} else if(str_hdl::check_after_operator_character(str[i])) {
			i++;
			str_hdl::get_name(str, i);
		} else {
			err += "Niewłaściwy znak: ";
			err += str[i];
			err += '\n';
		}
	}
	return err;
}


calculator::checker::checker(string str) : str(str) {}

string calculator::checker::get_err() {
	string err;
	err += operator_check();
	err += brackets_check();
	err += numbers_check();
	err += functions_check();
	err += constants_check();
	err += characters_check();
	return err;
}










