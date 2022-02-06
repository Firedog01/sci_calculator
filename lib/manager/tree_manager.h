//
// Created by janru on 05.02.2022.
//

#ifndef SCI_CALCULATOR_TREE_MANAGER_H
#define SCI_CALCULATOR_TREE_MANAGER_H

#include <string>
#include "../includes.h"
#include "../node/node.h"

/* flags
 * 0b00000xxx - type flags:
 *	      000    - integer
 *	      001    - variable
 *	      010    - constant
 *	      011    - function
 *	      111    - ambiguous
 * 0b00xxx000 - operator flags
 *     000      - addition
 *     001      - subtraction
 *     010      - multiplication
 *     011      - division
 *     100      - power
 *     101      - root
 *     111      - ambiguous
 */
namespace calculator::manager {
    class tree_manager {
        struct node_bundle {
            nd_type type;
            op_type op;
            node::node node;
        };

        node_ptr root;
    public:
        void append_to(node_ptr base, node_ptr append, bool isEmb);

        node_ptr create_node(nd_type type);
        node_ptr get_root();
        void set_root(node_ptr node);

        // void swap_nodes(node::node n1, node::node n2);

        op_type get_op(const node_ptr& node);
        nd_type get_type(const node_ptr& node);

        std::string display();
        dong enumerate();
    };
}



#endif //SCI_CALCULATOR_TREE_MANAGER_H
