#include "../../../lib/node/observer/node_observee.h"

using namespace calculator::node::observer;

bool node_observee::add_observer(update_tree_ptr observer) {
    std::vector<update_tree_ptr>::iterator temp = std::find(observers.begin(), observers.end(), observer);
	//Return false if the observer is already in the vector. This is not expected. But there is nothing really wrong either
	if ( temp != observers.end() )
		return false;

	observers.push_back(observer);
	return true;
}

bool node_observee::remove_observer(update_tree_ptr observer) {
    std::vector<update_tree_ptr>::iterator temp = std::find(observers.begin(), observers.end(), observer);
	//Return false if the observer could not be found (and evidently can’t be removed.
	if ( temp == observers.end() )
		return false;
	else
		observers.erase(remove(observers.begin(), observers.end(), observer));
	return true;
}

bool node_observee::notify() {
    std::for_each(observers.begin(), observers.end(), std::Notifier(this));
	//Return false if there are no observers in the vector
	return (observers.size() > 0);
}