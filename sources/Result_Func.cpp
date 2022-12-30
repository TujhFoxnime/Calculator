
#include <header.hpp>

double Result_Func(std::string expression) {
    std::string str;
    double result;
    std::stack<double> stack_numb;
    for (size_t i = 0; i < expression.size(); ++i) {
        char temp = expression[i];
        if (((temp >= 48) && (temp <= 57)) || temp == '.') {
            str += temp;
            if (expression[i + 1] == ' ' || expression[i + 1] == '+' ||
            expression[i + 1]
            == '-' || expression[i + 1] == '*' || expression[i + 1] == '/') {

                stack_numb.push(std::stod(str));
                str = "";
            }
        } else if (temp == '+' || temp == '-' || temp == '*' || temp == '/') {
            double num_2 = stack_numb.top();
            stack_numb.pop();
            double num_1 = stack_numb.top();
            stack_numb.pop();
            if (temp == '+') {result = num_1 + num_2;}
            else if (temp == '-') {result = num_1 - num_2;}
            else if (temp == '*') {result = num_1 * num_2;}
            else {result = num_1 / num_2;}

            stack_numb.push(result);

        } else if (temp == 's' || temp == 'c' || temp == 't' || temp == 'q'
        || temp == 'e') {
            double x = stack_numb.top(); // angle trigonometry
            stack_numb.pop();
            if (temp == 's') {result = sin(x);}
            else if (temp == 'c') {result = cos(x);}
            else if (temp == 't') {result = tan(x);}
            else if (temp == 'q') {result = (cos(x)) / (sin(x));}
            else {result = exp(x);}

            stack_numb.push(result);
        }
    }
    // the value of the last calculated expression
    result = stack_numb.top();
    return result;
}
