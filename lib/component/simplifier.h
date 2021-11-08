#ifndef SIMPLIFIER
#define SIMPLIFIER

#include "../node/int_node.h"
#include "../node/embedded_node.h"
#include "../node/constant_node.h"
#include "../node/function_node.h"

/*
 * todo:
 *	 wykonywanie operacji na intach
 *	 skracanie ułamków
 *	 łączenie wartości w nawiasach
 *	 coś z potęgami ??
 *	 skracanie funkcji trygonometrycznych
 */

class simplifier
{
	node_ptr traverse_tree_get_active_plus(node_ptr ptr);
	node_ptr traverse_tree_get_active_mul(node_ptr ptr);
    void swap_nodes_same_plus_branch(node_ptr ptr1, node_ptr ptr2); 

    void sort_mul_branches(node_ptr root);
	void group_ints_pow(node_ptr root); 
	void group_ints_div(node_ptr root); 
public:
	
	
	void simplify_all(node_ptr root);
};

#endif