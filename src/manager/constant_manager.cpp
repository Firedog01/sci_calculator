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
		throw std::logic_error("nie można uzyskać dostępu do pliku constants");
	}
}

std::string constant_manager::get_name(int id) {
	for(int i = 0; i < const_list.size(); i++) {
		if(const_list[i].id == id) {
			return const_list[i].name;
		}
	}
	return "";
}

calculator::dong constant_manager::get_value(calculator::constant_ptr node) {
	int id = node->get_id_const();
	return get_value(id);
}

calculator::dong constant_manager::get_value(int id) {
	for(int i = 0; i < const_list.size(); i++) {
		if(const_list[i].id == id) {
			return const_list[i].value;
		}
	}
	return 0;
}

int constant_manager::get_id(std::string name) {
	for(int i = 0; i < const_list.size(); i++) {
		if(const_list[i].name == name) {
			return const_list[i].id;
		}
	}
	return -1;
}