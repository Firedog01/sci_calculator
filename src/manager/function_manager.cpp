#include "../../lib/manager/function_manager.h"

function::function(int id, std::string name, abstr_function_ptr func) : id(id), name(name), func(func) {}

using namespace std;

function_manager::function_manager() {
	sin_f_ptr sinF = make_shared<sin_f>();
	funcs.emplace_back(0, "sin", sinF);
}

std::string function_manager::get_name(int id) {
	for(int i = 0; i < funcs.size(); i++) {
		if(funcs.at(i).id == id) {
			return funcs.at(i).name;
		}
	}
	return "";
}

int function_manager::get_id_func(std::string name) {
	for (int i = 0; i < funcs.size(); i++) {
		if (funcs.at(i).name == name) {
			return funcs.at(i).id;
		}
	}
	return -1;
}

dong function_manager::enumerate(int id, std::vector<node_ptr> args) {
	if(id == -1) {
		std::string err = "Function not found";
		throw std::logic_error(err);
	}
	
	for (int i = 0; i < funcs.size(); i++) {
		if (funcs.at(i).id == id) {
			return funcs.at(0).func->enumerate(args);
		};
	}
	std::string err = "Id out of bounds";
	throw std::logic_error(err);
}
