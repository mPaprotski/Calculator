#include <iostream>
#include <map>
#include <sstream>
#include <cmath>
#include <stack>
#include <memory>
#include "RPN.h"
#include "Command.cpp"

// Класс калькулятора, поддерживающий вычисления в постфиксной (обратной польской) записи.
class Calculator {
private:
    std::map<std::string, std::unique_ptr<Command>> commands; // Словарь доступных команд.

public:
    Calculator() {
        // Инициализация доступных команд.
        commands["+"] = std::make_unique<AddCommand>();
        commands["-"] = std::make_unique<SubtractCommand>();
        commands["*"] = std::make_unique<MultiplyCommand>();
        commands["/"] = std::make_unique<DivideCommand>();
        commands["^"] = std::make_unique<PowerCommand>();
        commands["sqrt"] = std::make_unique<SqrtCommand>();
        commands["sin"] = std::make_unique<SinCommand>();
        commands["cos"] = std::make_unique<CosCommand>();
        commands["tan"] = std::make_unique<TanCommand>();
        commands["log"] = std::make_unique<LogCommand>();
        commands["log10"] = std::make_unique<Log10Command>();
        commands["!"] = std::make_unique<FactorialCommand>();
        commands["pi"] = std::make_unique<PiCommand>();
    }

    // Выполнение выражения в постфиксной записи.
    void execute(const std::string& postfix) {
        std::stack<double> stack; // Стек для хранения промежуточных значений.
        std::istringstream tokens(postfix);
        std::string token;

        while (tokens >> token) {
            if (commands.count(token)) {
                // Проверка, хватает ли значений в стеке для выполнения команды.
                if (stack.size() < 1 && token != "sqrt" && token != "sin" && token != "cos" && token != "tan" && token != "log" && token != "log10" && token != "pi") {
                    throw std::runtime_error("Insufficient values in the expression");
                }
                commands[token]->execute(stack);
            }
            else {
                try {
                    stack.push(std::stod(token)); // Преобразование строки в число.
                }
                catch (const std::invalid_argument&) {
                    throw std::runtime_error("Invalid number: " + token);
                }
            }
        }

        if (stack.empty()) {
            throw std::runtime_error("Empty result: invalid expression");
        }

        // Вывод результата вычисления.
        std::cout << "Result: " << stack.top() << std::endl <<  std::endl;
        stack.pop();
    }
};
