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
/*
jak iterować po wszystkich elementach
funkcje:
początek mul_branch dla danego i_plus
następny mul_node - jeśli następny poza zakresem to zwróć początek
*/
namespace calculator {

	class simplifier
	{
		const old_node_type type_order[5] {
			Int, Constant, Variable, Embedded, Function
		};
		// default operation order: min, none, div, pow

		// p - n plus node, from 1 to n;
		// m - n mul node, from 0 to n-1;
		void get_mul_root(_node_ptr& active_mul, int p);
		void get_node(_node_ptr& node, _node_ptr& root, int p, int m);
		int get_n_plus(_node_ptr root);
		int get_n_mul(_node_ptr active_plus);
		// gets previous from to_prev node and swaps to_prev with to_set
		void set_prev_node(_node_ptr& to_prev, _node_ptr& to_set);
		
		void swap_nodes(_node_ptr& ptr1, _node_ptr& ptr2, _node_ptr& root);
		int get_order_type(_node_ptr node);
		int get_order_oper(_node_ptr node);

		void sort_mul_branches(_node_ptr& root);

		void group_pows(_node_ptr& root);
		void group_ints_div(_node_ptr& root);
	public:
		void simplify_all(_node_ptr& root);

		// friend class math_node;
	};
}
#endif