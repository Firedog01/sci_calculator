#include "../../lib/manager/constant_manager.h"

using namespace calculator::manager;

constants::constants(int id, std::string name, dong value):
	id(id), name(name), value(value) {}


std::string constant_manager::get_field(std::string str, int& i) {
	std::string ret;
	while(str[i] != ';') {
		ret += str[i];
		i++;
	}
	i++;
	return ret;
}

constant_manager::constant_manager() {
	std::fstream file;
	std::string line;
	file.open("../memory/constants", std::ios::in | std::ios::out);
	if(file.good()) {
		while(getline(file, line)) {
			int i = 0;
			int id = stoi(get_field(line, i));
			std::string name = get_field(line, i);
			dong value = stold(get_field(line, i));
			constants c(id, name, value);
			this->const_list.push_back(c);
		}
		file.close();
	} else {
		std::cout << "Standalone mode\n";
		this->const_list.emplace_back(0, "pi", 3.14159265358979324);
		this->const_list.emplace_back(1, "e", 2.71828182845904524);
	}
}

std::string constant_manager::get_name(int id) {
	for(auto & i : const_list) {
		if(i.id == id) {
			return i.name;
		}
	}
	return "";
}

calculator::dong constant_manager::get_value(const calculator::constant_ptr& node) {
	int id = node->get_id_const();
	return get_value(id);
}

calculator::dong constant_manager::get_value(int id) {
	for(auto & i : const_list) {
		if(i.id == id) {
			return i.value;
		}
	}
	return 0;
}

int constant_manager::get_id(const std::string& name) {
	for(auto & i : const_list) {
		if(i.name == name) {
			return i.id;
		}
	}
	return -1;
}