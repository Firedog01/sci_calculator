#include <iostream>
#include <limits>
#include <locale>
#include "lib/calculator.h"

using namespace std;

int main(int argc, char** argv) {
    setlocale(LC_CTYPE, "Polish");

    // ~90,935
    string default_text = "1 - 2/_pi^3 + 5(2(3^2))";
    if(argc == 1) {
        calculator calc;
        try {
            calc.parse(default_text);
        } catch(logic_error e) {
            cout << e.what() << endl;
        }
    } else if(argc == 2) {
        calculator calc;
        calc.parse(argv[1]);
    } else {
        cout << "number of arguments: " << argc << '\n';
        for(int i = 0; i < argc; i++) {
            cout << argv[i] << '\n';
        }
    }
    return 0;
}

/*
todo:
    zaimplementować obsługę funkcji
    zaimplementować funkcje optymalizujące drzewo
    funkcję która wyświelta wszystkie liczby jako inty
    checker składni <-
    klasy wyjątków
    dołożyć destruktor
 */