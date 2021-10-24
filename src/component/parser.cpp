#include "../../lib/component/parser.h"

using namespace std;

void parser::test() {
    cout << "wyswietlanie drzewa: ";
    cout << display_tree() << "\n\n";
    cout << "dostępne stałe:\n";
    for(int i = 0; i < 2; i++) {
        cout << c_man.get_name(i) << " " << c_man.get_value(i) <<"\n";
    } 
    cout << "value: " << t_man.enumerate_tree(root) << endl;
}

// doaawanie zawartości node'ów
// *. ustalenie flag operatorów
// *. utworzenie node'u odpowiedniego typu
// *. przestawienie 


// kwestja przecinka w liczbach. np 2.34 = 2 + 34 / 100
//
//
parser::parser(string str): 
        c_man(), f_man(), t_man() {
    str_hdl::remove_spaces(str);
    cout << "skrocony string: " + str + '\n';
    this->root = create_embedded_branch(str);
}

node_ptr parser::create_embedded_branch(std::string str) {
    int i = 0;
    op cur_op = add;
//    cout << "emb_root\n";
//    cout << "processed string: " << str << "\n";
    node_ptr emb_root = create_node(str, i, cur_op),
             active_plus = emb_root,
             active_mul = emb_root;

    shared_ptr<int_node> ptr;
//    ptr = static_pointer_cast<int_node>(emb_root);
    

    while(i < str.length()) {
//        cout << str[i] << ", " << i << "\n";
        node_ptr new_node = create_node(str, i, cur_op);

        if(cur_op == add) {
//            cout << "nowy add node: ";
//            ptr = static_pointer_cast<int_node>(new_node);
//            cout << get_math_operator(cur_op, ptr->is_min(), ptr->is_div(), ptr->is_pow()) << '\n';

            active_plus->set_plus_node(new_node);
            active_mul = new_node;
            active_plus = new_node;
        } else if(cur_op == mul) {
//            cout << "nowy mul node: ";
//            ptr = static_pointer_cast<int_node>(new_node);
//            cout << get_math_operator(cur_op, ptr->is_min(), ptr->is_div(), ptr->is_pow()) << '\n';

            active_mul->set_mul_node(new_node);
            active_mul = new_node;
        }
    }
//    cout << "koniec ------------\n";
    return emb_root;
}



node_ptr parser::create_node(string str, int& i, op& op) {
    bool min = false, 
         div = false, 
         pow = false;
    op = def;

    while(i < str.length()) {
        // cout << "cn: " << str[i] << ", " << i << "\n"; 
        
        switch(str[i]) {
        case str_hdl::OP_ADD_C:
            if(op == def) {
                op = add;
            }
            break;
        case str_hdl::OP_SUB_C:
            if(op == def) {
                op = add;
            }
            min = !min;
            break;
        case str_hdl::OP_MUL_C:
            op = mul;
            break;
        case str_hdl::OP_DIV_C:
            op = mul;
            div = true;
            break;
        case str_hdl::OP_POW_C:
            op = mul;
            pow = true;
            break;

        CASE_DIGIT {
            if(op == def) {
                op = mul;
            }
            string num = str_hdl::get_num(str, i);
            return create_int_node(num, min, div, pow);
        }

        case str_hdl::O_BRACKET_C: {
            if(op == def) {
                op = mul;
            }
            string embedded = str_hdl::get_embedded(str, i);
            return create_embedded_node(embedded, min, div, pow);
        }
        
         case str_hdl::FUNC_C: {
             i++;
             string name = str_hdl::get_name(str, i);
             return create_function_node(name, str_hdl::get_func_args(str, i), min, div, pow);
         }
        

        case str_hdl::CONST_C: {
            i++;
            string name = str_hdl::get_name(str, i);
            return create_constant_node(name, min, div, pow);
        }
            
        default:
            string err = "unknown operator ";
            err += str[i];
            throw logic_error(err);
        }
        i++;
    }
    return nullptr;
}

node_ptr parser::create_int_node(const string& cont, bool min, bool div, bool pow) {
    unsigned long long val = stoull(cont); 
    return make_shared<int_node>(val, min, div, pow);
}

node_ptr parser::create_embedded_node(string cont, bool min, bool div, bool pow) {
    node_ptr root_branch = create_embedded_branch(cont);
    return make_shared<embedded_node>(root_branch, min, div, pow);
}

node_ptr parser::create_constant_node(const string& name, bool min, bool div, bool pow) {
    int id_const = c_man.get_id(name);
    if(id_const == -1) {
        string err = "constant: ";
        err += name;
        err += " not defined";
        throw logic_error(err);
    } else {
        return make_shared<constant_node>(id_const, min, div, pow);
    }
}

node_ptr parser::create_function_node(string name, vector<string> args_str, bool min, bool div, bool pow) {
    int id_func = f_man.get_id(name);
    if(id_func == -1) {
        string err = "function: ";
        err += name;
        err += " not defined";
        throw logic_error(err);
    } else {
        vector<node_ptr> args;
        for(int j = 0; j < args_str.size(); j++) {
            args.push_back( (create_embedded_branch(args_str[j])) );
        }
        return make_shared<function_node>(id_func, args, min, div, pow);
    }

}

string parser::display_tree() {
    return display_subtree(root, add);
}

string parser::display_subtree(const node_ptr& node, op op) {
    string ret, type;
    type = node->get_type();
    ret += get_math_operator(op, node->is_min(), node->is_div(), node->is_pow());
    
    if(type == "int") {
        int_ptr ptr = static_pointer_cast<int_node>(node);
        ret += to_string(ptr->get_cont());
    } else if(type == "embedded") {
        embedded_ptr ptr = static_pointer_cast<embedded_node>(node);
        ret += str_hdl::O_BRACKET_C;
        ret += display_subtree(ptr->get_cont(), add);
        ret += str_hdl::C_BRACKET_C;
    } else if(type == "constant") {
        constant_ptr ptr = static_pointer_cast<constant_node>(node);
        ret += str_hdl::CONST_C;
        ret += c_man.get_name(ptr->get_id_const());
    } else if(type == "function") {
        function_ptr ptr = static_pointer_cast<function_node>(node);
        ret += str_hdl::FUNC_C;
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
            return string(1, str_hdl::OP_SUB_C);
        } else {
            return string(1, str_hdl::OP_ADD_C);
        }
    } else if(op == mul) {
        string ret;
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

node_ptr parser::getRoot() {
    return this->root;
}

dong parser::enumerate_root() {
    return t_man.enumerate_tree(root);
}
