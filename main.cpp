#include <iostream>
#include <limits>
#include <locale>
#include "lib/calculator.h"
#include "windows.h"

using namespace std;

void display_help();

int main(int argc, char** argv) {
	string default_text = "1(2-4)/3*9^6/5*-4";
	
	cout << "Command line calculator program\n"
         << "Made by Jan Rubacha\n"
         << "Version: 0.0.2\n"
         << "\n"
         << "For help type h\n";
	
	fstream constants;
	constants.open("../memory/constants", ios::in);
	bool installed = false;
	if(constants.good()) {
		installed = true;
	}
	
	if(argc == 1) {
		calculator::calc calc;
		string input;
		string equation;
		
		try {
			calc.parse(default_text);
		} catch(logic_error &e) {
			cout << e.what() << endl;
		}
		
		while(true) {
			break;
			if(installed) {
				cout << "<I>: ";
			} else {
				cout << "<S>: ";
			}
			
            getline(cin, input);
			
			if(input == "q") {
				break;
			} else if(input == "d") {
				equation = default_text;
			} else if(input == "h") {
                display_help();
                continue;
            } else {
                equation = input;
            }
			
			try {
				calc.parse(equation);
			} catch(logic_error &e) {
				cout << e.what() << endl;
			}
		}
//		system("pause");
	} else {
		cout << "number of arguments: " << argc << '\n';
		for(int i = 0; i < argc; i++) {
			cout << argv[i] << '\n';
		}
	}
	return 0;
}

void display_help() {

    cout << "d  - default input (for debugging purposes)\n"
         << "h  - display help\n"
         << "q  - quit program\n"
         << "\n"

         << "Input different than those above will be parsed\n"
         << "That is, just type calculation you want to do\n"
         << "\n"

         << "Available operators:\n"
         << "\t\'+\'  addition\n"
         << "\t\'-\'  subtraction\n"
         << "\t\'*\'  multiplication\n"
         << "\t\'/\'  division\n"
         << "\t\'^\'  power\n"
         << "\t\'^/\' root\n"
         << "\n"

         << "Rules of syntax:\n"
         << "\t- every constant needs to be preceded with \'_\'\n"
         << "\t  ex. _pi\n"
         << "\t- every function needs to be preceded with \'?\'\n"
         << "\t  ex. ?sin(_pi)\n"
         << "\t- operators can be combined in any order and quantity, -* = ++*---\n"
         << "\t- for use of brackets use only (), they can be freely nested\n"
         << "\t- in floating point decimals use \'.\' as separator\n"
         << "\t- in functions with many arguments separate them with \',\'\n"
         << "\n"
		 
		 << "Modes:\n"
		 << "<I>  - installed, you will be able to save your own constants\n"
		 << "<S>  - standalone, all changes will be lost upon exit\n"
		 << "\n"

         << "Implemented constants:\n"
         << "pi, e\n"
         << "Implemented functions\n"
         << "sin\n"

         << "\n";
}

/*
todo:
	zaimplementować obsługę funkcji
	zaimplementować funkcje optymalizujące drzewo
	funkcję która wyświetla wszystkie liczby jako int
	klasy wyjątków
	dołożyć destruktor
 */