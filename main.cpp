#include <iostream>
#include <limits>
#include <locale>
#include "lib/calculator.h"
#include "windows.h"

using namespace calculator;

int main(int argc, char** argv) {
	std::string default_text = "1(2-4)/3*9^6/5*-4";
	
	std::cout << "Command line calculator program\n"
			  << "Made by Jan Rubacha\n"
	          << "Version: 0.0.1\n"
			  << "Default input: " << default_text << "\n";
	
	if(argc == 1) {
		calc calc;
		std::string input;
		std::string equation;
		
		
		while(true) {
			std::cout << "# ";
			std::cin >> input;
			
			if(input == "q") {
				break;
			} else if(input == "d") {
				equation = default_text;
			} else {
				equation = input;
			}
			
			try {
				calc.parse(equation);
			} catch(std::logic_error &e) {
				std::cout << e.what() << std::endl;
			}
		}
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
	funkcję która wyświetla wszystkie liczby jako int
	klasy wyjątków
	dołożyć destruktor
 */