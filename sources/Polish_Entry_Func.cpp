
#include <header.hpp>

std::string Polish_Entry_Func(std::string expression) {
    std::string output_str;
    std::string number; // for numbers
    std::stack<Operator> stack_oper;
    for (char i = 0; i < expression.size(); ++i) {
        char temp = expression[i];
        if (((temp >= 48) && (temp <= 57)) || temp == '.') {
            number += temp;
            if (!((expression[i + 1] >= 48) && (expression[i + 1] <= 57)) && expression[i + 1] != '.') {
                output_str += number;
                output_str += ' ';
                number = "";
            }
        }
        // Block "basic operations"
        else if (temp == '*' || temp == '/' || temp == '+' || temp == '-') {
            Operator symbols;
            symbols.symbol = temp;
            if (temp == '*' || temp == '/') {
                symbols.priority = 3;
                symbols.symbol = temp == '*' ? '*' : '/';
            } else {
                symbols.priority = 2;
                symbols.symbol = temp == '+' ? '+' : '-';
            }
            if (stack_oper.empty() || (stack_oper.top().priority <
                    symbols.priority)) {
                stack_oper.push(symbols);
                } else {
                while (!stack_oper.empty() && (stack_oper.top().priority >=
                        symbols.priority)) {
                    output_str += stack_oper.top().symbol;
                    stack_oper.pop();
                }
                stack_oper.push(symbols);
            }
        // Block "brackets"
        } else if (temp == '(') {
            Operator symbols;
            symbols.symbol = temp;
            symbols.priority = 1;
             stack_oper.push(symbols);
        } else if (temp == ')') {
            while (stack_oper.top().symbol != '(') {
                output_str += stack_oper.top().symbol;
                stack_oper.pop();
            }
            stack_oper.pop();
        // Block "trigonometry" and "exhibitor"
        } else if (expression[i] == 's' && expression[i + 1] == 'i' && expression[i + 2] == 'n') {
            Operator trigonometry;
            trigonometry.priority = 4;
            trigonometry.symbol = 's';
            if (stack_oper.empty() || (stack_oper.top().priority < trigonometry.priority)) {
                stack_oper.push(trigonometry);
            } else {
                while (stack_oper.top().priority >= trigonometry.priority) {
                    output_str += stack_oper.top().symbol;
                    stack_oper.pop();
                }
                stack_oper.push(trigonometry);
            }
        } else if (expression[i] == 'c' && expression[i + 1] == 'o' && expression[i + 2] == 's') {
            Operator trigonometry;
            trigonometry.priority = 4;
            trigonometry.symbol = 'c';
            if (stack_oper.empty() || (stack_oper.top().priority < trigonometry.priority)) {
                stack_oper.push(trigonometry);
            } else {
                while (stack_oper.top().priority >=
                        trigonometry.priority) {
                    output_str += stack_oper.top().symbol;
                    stack_oper.pop();
                }
                stack_oper.push(trigonometry);
            }
        } else if (expression[i] == 't' && expression[i + 1] == 'g' && expression[i - 1] != 'c') {
            Operator trigonometry;
            trigonometry.priority = 4;
            trigonometry.symbol = 't';
            if (stack_oper.empty() || (stack_oper.top().priority < trigonometry.priority)) {
                stack_oper.push(trigonometry);
            } else {
                while (!stack_oper.empty() && stack_oper.top().priority >= trigonometry.priority) {
                    output_str += stack_oper.top().symbol;
                    stack_oper.pop();
                }
                stack_oper.push(trigonometry);
            }
        } else if (expression[i] == 'c' && expression[i + 1] == 't' && expression[i + 2] == 'g') {
            Operator trigonometry;
            trigonometry.priority = 4;
            trigonometry.symbol = 'q';
            if (stack_oper.empty() || (stack_oper.top().priority < trigonometry.priority)) {
                stack_oper.push(trigonometry);
            } else {
                while (stack_oper.top().priority >= trigonometry.priority) {
                    output_str += stack_oper.top().symbol;
                    stack_oper.pop();
                }
                stack_oper.push(trigonometry);
            }
        } else if (expression[i] == 'e' && expression[i + 1] == 'x' && expression[i + 2] == 'p') {
            Operator trigonometry;
            trigonometry.priority = 4;
            trigonometry.symbol = 'e';
            if (stack_oper.empty() || (stack_oper.top().priority < trigonometry.priority)) {
                stack_oper.push(trigonometry);
            } else {
                while (stack_oper.top().priority >= trigonometry.priority) {
                    output_str += stack_oper.top().symbol;
                    stack_oper.pop();
                }
                stack_oper.push(trigonometry);
            }
        }
    }
    output_str += number; //last number
    while (!stack_oper.empty()) {
        output_str += stack_oper.top().symbol;
        stack_oper.pop();
    }
    return output_str;
}
