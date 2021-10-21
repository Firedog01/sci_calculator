#include "../../lib/component/checker.h"

using namespace std;

string checker::operator_check() {
    string err;
    
    if(true) { // nie zaczyna się liczbą
        err += "Początkowy operator będzie zignorowany\n";
    }
    for(int i = 0; i < str.length(); i++) {

    }
    return err;
}

checker::checker(string str) : str(str) {}