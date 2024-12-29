#include <iostream>
#include <map>
#include <sstream>
#include <cmath>
#include <stack>
#include <memory>
#include "RPN.h"
#include "Command.cpp"

class Calculator {
private:
    std::map<std::string, std::unique_ptr<Command>> commands;

public:
    Calculator() {
        commands["+"] = std::make_unique<AddCommand>();
        commands["-"] = std::make_unique<SubtractCommand>();
        commands["*"] = std::make_unique<MultiplyCommand>();
        commands["/"] = std::make_unique<DivideCommand>();
        commands["^"] = std::make_unique<PowerCommand>();
        commands["sqrt"] = std::make_unique<SqrtCommand>();
        commands["sin"] = std::make_unique<SinCommand>();
        commands["cos"] = std::make_unique<CosCommand>();
        commands["tan"] = std::make_unique<TanCommand>();
    }

    void execute(const std::string& postfix) {
        std::stack<double> stack;
        std::istringstream tokens(postfix);
        std::string token;

        while (tokens >> token) {
            if (commands.count(token)) {
                if (stack.size() < 1 && token != "sqrt" && token != "sin" && token != "cos" && token != "tan") {
                    throw std::runtime_error("Insufficient values in the expression");
                }
                commands[token]->execute(stack);
            }
            else {
                try {
                    stack.push(std::stod(token));
                }
                catch (const std::invalid_argument&) {
                    throw std::runtime_error("Invalid number: " + token);
                }
            }
        }

        if (stack.empty()) {
            throw std::runtime_error("Empty result: invalid expression");
        }

        std::cout << "Result: " << stack.top() << std::endl;
        stack.pop();
    }
};
