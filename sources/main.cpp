
#include <header.hpp>

int main() {
    std::cout << "Attention!" << std::endl <<
    "The expression is entered without spaces." << std::endl <<
    "The expression is entered through a dot, not a comma." << std::endl;

    std::string expression;
    std::cout << "Enter an expression: " << std::endl;
    getline(std::cin, expression);

    // trigonometry
    bool flag = false;
    for (size_t i = 0; i < expression.size(); ++i) {
        if (expression[i - 1] != 'e' && expression[i] == 'x' && expression[i + 1] != 'p') {
            flag = true;
        }
    }
    if (flag) {
        std::cout << "Enter an argument for the trigonometric function:" << std::endl;
        std::string x;
        std::cin >> x;
        for (size_t i = 0; i < expression.size(); ++i) {
            if (expression[i - 1] != 'e' && expression[i] == 'x' && expression[i + 1] != 'p') {
                expression.erase(i,1);
                expression.insert(i,x);
            }
        }
    }

    // checking
    expression = Error_Debugging_Func(expression);
    if (expression == "error_zero") {
        std::cerr << "Division by zero. Operation not defined." << std::endl;
    }
    if (expression == "error_close_br") {
        std::cerr << "Missing closing bracket. Operation not defined." <<
                  std::endl;
    }
    if (expression == "error_open_br") {
        std::cerr << "Missing opening bracket. Operation not defined." <<
                  std::endl;
    }
    if (expression == "error_syntax") {
        std::cerr << "Syntax error at the beginning of an expression." <<
        std::endl;
    }
    if (expression != "error_zero" && expression != "error_close_br"
    && expression != "error_open_br" && expression != "error_syntax") {
        // polish entry
        std::string expression_ = Polish_Entry_Func(expression);
        // final result
        double result = Result_Func(expression_);
        std::cout << "Result:" << result << std::endl;
    }
    return 0;
}
