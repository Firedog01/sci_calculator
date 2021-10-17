#include "../lib/constant_manager.h"

using namespace std;

constants::constants(int id, string name, long double value):
    id(id), name(name), value(value) {}


std::string constant_manager::get_field(std::string str, int& i) {
    string ret;
    while(str[i] != ';') {
        ret += str[i];
        i++;
    }
    i++;
    return ret;
}

constant_manager::constant_manager() {
    fstream file;
    string line;
    file.open("memory/constants", ios::in | ios::out);
    if(file.good()) {
        while(getline(file, line)) {
            int i = 0;
            int id = stoi(get_field(line, i));
            string name = get_field(line, i);
            long double value = stold(get_field(line, i));
            constants c(id, name, value);
            this->const_list.push_back(c);
        }
        file.close();
    } else {
        throw logic_error("nie można uzyskać dostępu do pliku constants");
    }
}

string constant_manager::get_name(int id) {
    for(int i = 0; i < const_list.size(); i++) {
        if(const_list[i].id == id) {
            return const_list[i].name;
        }
    }
    return "";
}

long double constant_manager::get_value(constant_ptr node) {
    int id = node->get_id_const();
    return get_value(id);
}

long double constant_manager::get_value(int id) {
    for(int i = 0; i < const_list.size(); i++) {
        if(const_list[i].id == id) {
            return const_list[i].value;
        }
    }
    return 0;
}

int constant_manager::get_id(string name) {
    for(int i = 0; i < const_list.size(); i++) {
        if(const_list[i].name == name) {
            return const_list[i].id;
        }
    }
    return -1;
}