#include "../../lib/func/sin_f.h"

using namespace std;

calculator::dong calculator::func::sin_f::enumerate(vector<_node_ptr> args) {
	if(args.size() == 0) {
		throw logic_error("Wrong initialisation");
	}
	if(args.size() != 1) {
		throw logic_error("wrong number of arguments in function sin");
	} else {
		return sinl(args.at(0)->enumerate());
	}
}