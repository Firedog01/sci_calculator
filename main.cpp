#include <iostream>
#include <limits>
#include "lib/parser.h"

using namespace std;

int main(int argc, char** argv) {
    // ~90,935
    string default_text = "1 - 2/_pi^3 + 5(2(3^2))2";
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