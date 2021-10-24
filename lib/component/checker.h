#ifndef CHECKER
#define CHECKER

#include "parser.h"
#include "str_hdl.h"
#include "../manager/constant_manager.h"

#include <iostream>

class checker
{
    std::string str;
    std::string operator_check();
    std::string brackets_check();
    //todo: 1.2.3
    std::string numbers_check();
    //todo
    //  czy funkcje mają poprawną ilość argumentów
    //  czy dana nazwa funkcji jest poprawna
    std::string functions_check();
    std::string constants_check();
    std::string characters_check();

public:
    checker(std::string str);
    std::string get_err();
};

#endif