#ifndef CALCULATOR_NODEOBSERVEE;
#define CALCULATOR_NODEOBSERVEE;

#include <vector>
//https://www.dreamincode.net/forums/topic/197421-the-listener-pattern/
namespace calculator::node::observer {

    class node_observee {
        std::vector<update_tree*> m_ObserverVec;
	    // -------------------------
	    // Disabling default copy constructor and default
	    // assignment operator.
	    // -------------------------
	    node_observee(const node_observee& yRef);                                
	    node_observee& operator=(const node_observee& yRef);
	protected:
	    //constructor is protected because this class is abstract, it’s only meant to be inherited!
	    node_observee();

    public:
	    virtual ~node_observee();        //destructor
	 
	    bool Addnode_observee(update_tree* observer);
	    bool RemoveObserver(update_tree* observer);
	    bool NotifyObservers();
    }
    
}

#endif