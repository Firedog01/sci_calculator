#include <iostream>
#include <limits>
#include <locale>
#include "lib/calculator.h"

using namespace calculator;

int main(int argc, char** argv) {
	setlocale(LC_CTYPE, "Polish");
	//   1
	// ------ = 0,0445
	// pi ^ e
	std::string default_text = "1(2-4)/3*9^6/5*-4";
	if(argc == 1) {
		calc calc;
		try {
			calc.parse(default_text);
		} catch(std::logic_error e) {
			std::cout << e.what() << std::endl;
		}
	} else if(argc == 2) {
		calc calc;
		calc.parse(argv[1]);
	} else {
		std::cout << "number of arguments: " << argc << '\n';
		for(int i = 0; i < argc; i++) {
			std::cout << argv[i] << '\n';
		}
	}
	return 0;
}

/*
todo:
	zaimplementować obsługę funkcji
	zaimplementować funkcje optymalizujące drzewo
	funkcję która wyświelta wszystkie liczby jako inty
	klasy wyjątków
	dołożyć destruktor
 */