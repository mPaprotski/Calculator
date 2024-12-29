#include <iostream>
#include <string>
#include "RPN.h"
#include "Calculator.cpp"

int main() {
    try {
        std::cout << "Operations:\n1) +\t2) -\t3) *\t4) /\t5) ^\n6) sqrt\t7) sin\t8) cos\t9) tan\n";
        std::cout << "Enter an expression (infix): ";
        std::string input;
        std::getline(std::cin, input);

        if (input.empty()) {
            throw std::runtime_error("Expression cannot be empty");
        }

        std::string postfix = infixToPostfix(input);
        std::cout << "Postfix notation: " << postfix << std::endl;

        Calculator calc;
        calc.execute(postfix);
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}