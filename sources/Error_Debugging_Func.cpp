
#include <header.hpp>

std::string Error_Debugging_Func(std::string expression) {
    // brackets count
    int openBracket = 0, closeBracket = 0;

    // the first number is negative
    if (expression[0] == '-') {
        expression.replace(0, 1, "(0-1)*");
    }
    if (expression[0] == '+') {
        expression.erase(0, 1);
    }
    if (expression[0] == '*' || expression[0] == '/') {
        return "error_syntax";
    }
    for (size_t i = 0; i < expression.size(); ++i) {
        // division by zero
        if (expression[i] == '/' && expression[i + 1] == '0'
        && (!isdigit(expression[i + 2]) ||
        expression[i + 2] != '.') && ((i + 2) < expression.size())) {
            return "error_zero";
        }
        // delete spaces
        if (expression[i] == ' ') {
            expression.erase(i, 1);
            --i;
        }
        // replace ',' to '.'
        if (expression[i] == ',') {
            expression.replace(i, 1, ".");
        }
        // brackets
        if (expression[i] == '(') {
            if (expression[i + 1] == '-' && ((i + 1) < expression.size())) {
                expression.replace(i, 1, "0-");
            }
            ++openBracket;
        } else if (expression[i] == ')') {
            ++closeBracket;
        }
    }
    if (openBracket > closeBracket) {
        return "error_close_br";
    } else if (openBracket < closeBracket) {
        return "error_open_br";
    } else {
        return expression;
    }
}
