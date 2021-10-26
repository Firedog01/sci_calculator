#include "../../lib/func/sin_f.h"

using namespace std;

dong sin_f::enumerate(vector<node_ptr> args) {
    if(args.size() == 0) {
        throw logic_error("Wrong initialisation");
    }
    if(args.size() != 1) {
        throw logic_error("wrong number of arguments in function sin");
    } else {
        return sinl(args.at(0)->enumerate());
    }
}