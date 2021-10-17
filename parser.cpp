#include "parser.h"

using namespace std;

string parser::test() {
    cout << "wyswietlanie drzewa: ";
    cout << display_tree() << "\n\n";
    cout << "dostępne stałe:\n";
    for(int i = 0; i < 2; i++) {
        cout << c_man.get_name(i) << " " << c_man.get_value(i) <<"\n";
    } 
    return "";
}

// doaawanie zawartości node'ów
// *. ustalenie flag operatorów
// *. utworzenie node'u odpowiedniego typu
// *. przestawienie 


// kwestja przecinka w liczbach. np 2.34 = 2 + 34 / 100
//
//
parser::parser(string str): 
        c_man() {
    this->remove_spaces(str);
    cout << "skrocony string: " + str + '\n';
    this->root = create_embeded_branch(str);
}

node_ptr parser::create_embeded_branch(std::string str) {
    int i = 0;
    op cur_op = add;
    cout << "emb_root\n";
    cout << "processed string: " << str << "\n";
    node_ptr emb_root = create_node(str, i, cur_op),
             active_plus = emb_root,
             active_mul = emb_root;

    shared_ptr<int_node> ptr;
    ptr = static_pointer_cast<int_node>(emb_root);
    

    while(i < str.length()) {
        cout << str[i] << ", " << i << "\n";
        node_ptr new_node = create_node(str, i, cur_op);

        if(cur_op == add) {
            cout << "nowy add node: ";
            ptr = static_pointer_cast<int_node>(new_node);
            cout << get_math_operator(cur_op, ptr->is_min(), ptr->is_div(), ptr->is_pow()) << '\n';

            active_plus->set_plus_node(new_node);
            active_mul = new_node;
            active_plus = new_node;
        } else if(cur_op = mul) {
            cout << "nowy mul node: ";
            ptr = static_pointer_cast<int_node>(new_node);
            cout << get_math_operator(cur_op, ptr->is_min(), ptr->is_div(), ptr->is_pow()) << '\n';

            active_mul->set_mul_node(new_node);
            active_mul = new_node;
        }
    }
    cout << "koniec ------------\n";
    return emb_root;
}



void parser::remove_spaces(string& str) {
    string replace;
    for(int i = 0; i < str.length(); i++) {
        if(str[i] != ' ') {
            replace += str[i];
        }
    }
    str = replace;
}

string parser::get_num(string str, int& i) {
    string num;
    while(str[i] >= '0' && str[i] <= '9') {
        num += str[i];
        i++;
    }
    return num;
}

std::string parser::get_embeded(std::string str, int& i) {
    string embeded;
    int brackets = 1; // +1 for opening -1 for closing

    i++;
    do {
        if(str[i] == ')') {
            brackets--;
        }
        if(str[i] == '(') {
            brackets++;
        }
        embeded += str[i];
        i++;
    } while(brackets > 0);
    embeded.pop_back();
    return embeded;
}

std::string parser::get_name(std::string str, int& i) {
    string name;
    while(check_name_character(str[i])) {
        name += str[i];
        i++;
    }
    return name;
}

bool parser::check_name_character(char c) {
    bool check = false;
    if(c >= 'a' && c <='z') {
        check = true;
    }
    if(c == '_') {
        check = true;
    }
    return check;
}

node_ptr parser::create_node(string str, int& i, op& op) {
    bool min = false, 
         div = false, 
         pow = false;
    op = def;

    while(i < str.length()) {
        // cout << "cn: " << str[i] << ", " << i << "\n"; 
        
        switch(str[i]) {
        case '+':
            if(op == def) {
                op = add;
            }
            break;
        case '-':
            if(op == def) {
                op = add;
            }
            min = !min;
            break;
        case '*':
            op = mul;
            break;
        case '/':
            op = mul;
            div = true;
            break;
        case '^':
            op = mul;
            pow = true;
            break;

        case '0': case '1': case '2': case '3': case '4':
        case '5': case '6': case '7': case '8': case '9':
            if(op == def) {
                op = mul;
            }
            return create_int_node(get_num(str, i), min, div, pow);

        case '(':  
            return create_embeded_node(get_embeded(str, i), min, div, pow);
        
        // case '?':
        //     i++;
        //     return create_function_node(get_name(str, i), );

        case '_':
            i++;
            return create_constant_node(get_name(str, i), min, div, pow);
            
        default:
            string err = "unknown operator ";
            err += str[i];
            throw logic_error(err);
        }
        i++;
    }
    return nullptr;
}

node_ptr parser::create_int_node(string cont, bool min, bool div, bool pow) {
    unsigned long long val = stoull(cont); 
    return make_shared<int_node>(val, min, div, pow);
}

node_ptr parser::create_embeded_node(string cont, bool min, bool div, bool pow) {
    node_ptr root_branch = create_embeded_branch(cont);
    return make_shared<embeded_node>(root_branch, min, div, pow);
}

node_ptr parser::create_constant_node(string name, bool min, bool div, bool pow) {
    int id_const = c_man.get_id(name);
    if(id_const == -1) {
        string err = "constant: ";
        err += name;
        err += " not defined";
        throw logic_error(err);
        return nullptr;
    } else {
        return make_shared<constant_node>(id_const, min, div, pow);
    }
}

node_ptr parser::create_function_node(string name, string arguments, bool min, bool div, bool pow) {
    return nullptr;
}

string parser::display_tree() {
    return display_subtree(root, add);
}

string parser::display_subtree(node_ptr node, op op) {
    string ret, type;
    type = node->get_type();
    ret += get_math_operator(op, node->is_min(), node->is_div(), node->is_pow());
    
    if(type == "int") {
        int_ptr ptr = static_pointer_cast<int_node>(node);
        ret += to_string(ptr->get_cont());

    } else if(type == "embeded") {
        embeded_ptr ptr = static_pointer_cast<embeded_node>(node);
        ret += "(";
        ret += display_subtree(ptr->get_cont(), add);
        ret += ")";
    } else if(type == "constant") {
        constant_ptr ptr = static_pointer_cast<constant_node>(node);
        ret += '_';
        ret += c_man.get_name(ptr->get_id_const());
    } else if(type == "function") {
        function_ptr ptr = static_pointer_cast<function_node>(node);
        ret += '?';
        
    } else {
        ret += "type not set";
    }

    if(node->get_mul_node() != nullptr) {
        // cout << "mul node:\n";
        ret += display_subtree(node->get_mul_node(), mul);
    }
    if(node->get_plus_node() != nullptr) {
        // cout << "plus node:\n";
        ret += display_subtree(node->get_plus_node(), add);
    }
    return ret;
}

std::string parser::get_math_operator(op op, bool min, bool div, bool pow) {
    if(op == add) {
        if(min) {
            return "-";
        } else {
            return "+";
        }
    } else if(op == mul) {
        string ret;
        if(pow) {
            if(div) {
                ret += "^/";
            } else {
                ret += "^";
            }
        } else {
            if(div) {
                ret += "/";
            } else {
                ret += "*";
            }
        }

        if(min) {
            ret += "-";
        }
        return ret;
    }
    string empty;
    return empty;
}