#include "../../lib/manager/function_manager.h"

function::function(int id, std::string name, fpt ptr) : id(id), name(name), ptr(ptr) {}

using namespace std;

function_manager::function_manager() {
    fpt sin_func = &sin_f::enumerate;
    funcs.emplace_back(0, "sin", sin_func);
}



std::string function_manager::get_name(int id) {
    for(int i = 0; i < funcs.size(); i++) {
        if(funcs.at(i).id == id) {
            return funcs.at(i).name;
        }
    }
    return "";
}

int function_manager::get_id(std::string name) {
    for (int i = 0; i < funcs.size(); i++) {
        if (funcs.at(i).name == name) {
            return funcs.at(i).id;
        };
    };
    return -1;
}

dong function_manager::enumerate(string name, vector<node_ptr> args) {
    for (int i = 0; i < funcs.size(); i++) {
        if (funcs.at(i).name == name) {
            return (*funcs.at(i).ptr)(args);
        };
    }
    string err = "Function ";
    err += name;
    err += " not found";
    throw logic_error(err);
}
