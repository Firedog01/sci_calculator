//
// Created by janru on 06.02.2022.
//

#ifndef SCI_CALCULATOR_PARSER2_H
#define SCI_CALCULATOR_PARSER2_H

#include <string>
#include <limits>
#include <stdexcept>
#include <iostream>
#include <utility>

#include "str_hdl.h"
#include "../manager/function_manager.h"
#include "../manager/constant_manager.h"
#include "../manager/tree_manager.h"

#include "../node/int_node.h"
#include "../node/embedded_node.h"
#include "../node/constant_node.h"
#include "../node/function_node.h"

namespace calculator {

    class parser2 {
    private:
        _node_ptr root;
        f_man_ptr f_man;
        c_man_ptr c_man;
    public:
        parser2(f_man_ptr f_man, c_man_ptr c_man) : f_man(std::move(f_man)), c_man(std::move(c_man)) {}
        node_ptr parse(std::string str);
        node_ptr get_root();
    };

}


#endif //SCI_CALCULATOR_PARSER2_H
