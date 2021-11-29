#include "../../lib/component/str_hdl.h"

using namespace calculator;

void str_hdl::remove_spaces(std::string& str) {
	std::string replace;
	for(char i : str) {
		if(i != ' ') {
			replace += i;
		}
	}
	str = replace;
}

std::string str_hdl::get_num(std::string str, int& i) {
	std::string num;
	while(str[i] >= '0' && str[i] <= '9') {
		num += str[i];
		i++;
	}
	return num;
}

std::string str_hdl::get_embedded(std::string str, int& i) {
	std::string embedded;
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

std::string str_hdl::get_name(std::string str, int& i) {
	std::string name;
	while(check_name_character(str[i])) {
		name += str[i];
		i++;
	}
	return name;
}

std::vector<std::string> str_hdl::get_func_args(std::string str, int &i) {
	std::vector<std::string> ret;
	std::string func_cont = get_embedded(str, i), arg;
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

std::string str_hdl::get_op(op op, bool min, bool div, bool pow) {
	if(op == add) {
		if(min) {
			return std::string(1, str_hdl::OP_SUB_C);
		} else {
			return std::string(1, str_hdl::OP_ADD_C);
		}
	} else if(op == mul) {
		std::string ret;
		if(pow) {
			if(div) {
				ret += str_hdl::OP_POW_C;
				ret += str_hdl::OP_DIV_C;
			} else {
				ret += str_hdl::OP_POW_C;
			}
		} else {
			if(div) {
				ret += str_hdl::OP_DIV_C;
			} else {
				ret += str_hdl::OP_MUL_C;
			}
		}

		if(min) {
			ret += str_hdl::OP_SUB_C;
		}
		return ret;
	}
	return "";
}
