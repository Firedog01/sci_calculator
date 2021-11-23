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
	// default operation order: min, none, div, pow

	// p - n plus node, from 1 to n;
	// m - n mul node, from 0 to n-1;
	void get_mul_root(node_ptr& active_mul, int p);
	void get_node(node_ptr& node, node_ptr& root, int p, int m);
	int get_n_plus(node_ptr root);
	int get_n_mul(node_ptr active_plus);
    // gets previous from to_prev node and swaps to_prev with to_set
	void set_prev_node(node_ptr& to_prev, node_ptr& to_set);
	
	void swap_nodes(node_ptr& ptr1, node_ptr& ptr2, node_ptr& root); 
	int get_order_type(node_ptr node);
	int get_order_oper(node_ptr node);

    void sort_mul_branches(node_ptr& root);

	void group_pows(node_ptr& root); 
	void group_ints_div(node_ptr& root); 
public:
	void simplify_all(node_ptr& root);

	// friend class math_node;
};
/*
jak iterować po wszystkich elementach 
funkcje: 
początek mul_branch dla danego i_plus
następny mul_node - jeśli następny poza zakresem to zwróć początek
*/
#endif