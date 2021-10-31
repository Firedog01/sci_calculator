#ifndef CALCULATOR
#define CALCULATOR

#include "component/parser.h"
#include "component/checker.h"
#include "component/simplifier.h"
#include "component/displayer.h"

class calculator
{
    f_man_ptr f_man;
    c_man_ptr c_man;
public:
    calculator();
    void parse(std::string str);
};
/*
assumptions:
    2^3*4 = 2^(3*4)
    2/3*4 = (2/3)*4
    2+^3 = 2^3
 */
#endif