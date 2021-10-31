#include "../../lib/component/displayer.h"

using namespace std;


/* formatting rules:
    1/2 = (1/2)
    
*/
string displayer::display_subtree(const node_ptr& node, op op) {
    string ret, type;
    type = node->get_type();

    
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
        ret += c_man->get_name(ptr->get_id_const());
    } else if(type == "function") {
        function_ptr ptr = static_pointer_cast<function_node>(node);
        ret += f_man->get_name(ptr->get_id_func());
        ret += str_hdl::O_BRACKET_C;
        vector<node_ptr> args = ptr->get_args();
        for(int i = 0; i < args.size(); i++) {
            ret += display_subtree(args.at(i), add);
            ret += str_hdl::F_ARG_DELIM;
        }
        ret += str_hdl::C_BRACKET_C;
    } else {
        ret += "type not set";
    }

    if(node->get_mul_node() != nullptr) {
        node_ptr mul_node = node->get_mul_node();
        ret += get_math_operator(mul, mul_node->is_min(), mul_node->is_div(), mul_node->is_pow());
        if(mul_node->get_mul_node() != nullptr || mul_node->get_plus_node() != nullptr) {
//            ret += str_hdl::O_BRACKET_C;
            ret += display_subtree(mul_node, mul);
//            ret += str_hdl::C_BRACKET_C;
        } else {
            ret += display_subtree(node->get_mul_node(), mul);
        }
    }
    if(node->get_plus_node() != nullptr) {
        node_ptr plus_node = node->get_plus_node();
        ret += get_math_operator(add, plus_node->is_min(), plus_node->is_div(), plus_node->is_pow());
        ret += display_subtree(node->get_plus_node(), add);
    }
    return ret;
}

string displayer::get_math_operator(op op, bool min, bool div, bool pow) {
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

dong displayer::enumerate(node_ptr root) {
    return root->enumerate();
}

string displayer::display(node_ptr root) {
    return display_subtree(root, def);
}