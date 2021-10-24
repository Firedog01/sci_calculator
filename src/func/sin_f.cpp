#include "../../lib/func/sin_f.h"

using namespace std;

dong sin_f::enumerate(vector<node_ptr> args) {
    if(args.size() == 0) {
        throw logic_error("Wrong initialisation");
    }
    if(args.size() != 1) {
        throw logic_error("wrong number of arguments in function sin_class");
    } else {
        return 0;
//        tree_manager t_man;
//        return sinl(t_man.enumerate_tree(args.at(0)));
    }
}