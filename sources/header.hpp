
#ifndef CALCULATOR_HEADER_HPP
#define CALCULATOR_HEADER_HPP

#include <string>
#include <iostream>
#include <stack>
#include <cmath>

class Operator {
public:
    int priority;
    char symbol;
};

double Result_Func(std::string expression);
std::string Polish_Entry_Func(std::string expression);
std::string Error_Debugging_Func(std::string expression);

#endif //CALCULATOR_HEADER_HPP
