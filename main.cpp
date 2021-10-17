#include <iostream>
#include <limits>
#include "parser.h"
// #include "includes.h"
// #include "node/lib/math_node.h"

using namespace std;

int main(int argc, char** argv) {
    string default_text = "123 - 341 / _pi 4((23 - 7)* 15) + 34 * 8";
    if(argc == 1) {
        parser parser(default_text);
        cout << parser.test() << endl;
    } else if(argc == 2) {
        parser parser(argv[1]);
        cout << parser.test() << endl;
        
    } else {
        cout << "number of arguments: " << argc << '\n';
        for(int i = 0; i < argc; i++) {
            cout << argv[i] << '\n';
        }
    }
    return 0;
}