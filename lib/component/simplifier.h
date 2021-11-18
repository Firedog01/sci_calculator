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
	const node_type type_order[5] {
		Int, Constant, Variable, Embedded, Function
	};
    
	void handle_prev_nodes(node_ptr& ptr1, node_ptr& ptr2);
	void swap_nodes(node_ptr& ptr1, node_ptr& ptr2, node_ptr& root); 
	int get_order_type(node_ptr node);
	int get_order_oper(node_ptr node);
    void sort_mul_branches(node_ptr& root);

	void group_ints_pow(node_ptr& root); 
	void group_ints_div(node_ptr& root); 
public:
	void simplify_all(node_ptr& root);

	// friend class math_node;
};

#endif