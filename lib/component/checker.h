#ifndef CHECKER
#define CHECKER

#include "parser.h"
#include "string_handling.h"

#include <iostream>

    //other caracters

class checker
{
    std::string str;
    std::string operator_check();
    std::string brackets_check();
    //todo: 1.2.3
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
    std::string get_err();
};

#endif