#ifndef CHECKER
#define CHECKER

#include "parser.h"

    //other caracters

class checker
{
    std::string str;
    //+^
    //operator bez liczby
    //*na początku
    std::string operator_check();
    //()
    std::string brackets_check();
    //1.2.3
    //czy nie ma dwóch liczb oddzielonych tylko spacją
    std::string numbers_check();
    //czy funkcje mają poprawną ilość argumentów
    //czy dana nazwa funkcji jest poprawna
    std::string functions_check();
    //czy dana nazwa stałej jest poprawna
    std::string constants_check();
    std::string characters_check();

public:
    checker(std::string str);
    bool is_good();
    std::string syntax_check_verboose();
};

#endif