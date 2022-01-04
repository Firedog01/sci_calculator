#ifndef CALCULATOR_UPDATETREE
#define CALCULATOR_UPDATETREE

#include "../../includes.h"

namespace calculator::node::observer {

    class node_observer {
        // -------------------------
        // Disabling default copy constructor and default 
        // assignment operator.
        // -------------------------
        node_observer(const node_observer& yRef);	
        node_observer& operator=(const node_observer& yRef);	

    public:
        virtual ~node_observer();		// Destructor
        virtual void Notify(node_observee_ptr observee) = 0; //Pure Virtual
        node_observer();
    };

}

#endif