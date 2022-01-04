#ifndef CALCULATOR_NODEOBSERVEE;
#define CALCULATOR_NODEOBSERVEE;

#include "update_tree.h"
#include "../../includes.h"

#include <vector>
#include <algorithm>
//https://www.dreamincode.net/forums/topic/197421-the-listener-pattern/
namespace calculator::node::observer {

    class node_observee { //node being observed
        std::vector<update_tree_ptr> observers;

		//disabled
	    node_observee(const node_observee& yRef);                                
	    node_observee& operator=(const node_observee& yRef);
	protected:
	    //constructor is protected because this class is abstract, it’s only meant to be inherited!
	    node_observee();

    public:
	    virtual ~node_observee() {}        //destructor
	 
	    bool add_observer(update_tree_ptr observer);
	    bool remove_observer(update_tree_ptr observer);
	    bool notify();
    };
    
}

#endif