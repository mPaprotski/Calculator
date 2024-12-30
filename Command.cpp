#include <cmath>
#include <stack>
#include <stdexcept>

// Базовый класс команды. Все команды должны реализовывать метод execute.
class Command {
public:
    virtual void execute(std::stack<double>& stack) const = 0; // Выполнение команды с использованием стека.
    virtual ~Command() = default;
};

// Команда сложения двух верхних элементов стека.
class AddCommand : public Command {
public:
    void execute(std::stack<double>& stack) const override {
        double b = stack.top(); stack.pop();
        double a = stack.top(); stack.pop();
        stack.push(a + b);
    }
};

// Команда вычитания второго элемента стека из первого.
class SubtractCommand : public Command {
public:
    void execute(std::stack<double>& stack) const override {
        double b = stack.top(); stack.pop();
        double a = stack.top(); stack.pop();
        stack.push(a - b);
    }
};

// Команда умножения двух верхних элементов стека.
class MultiplyCommand : public Command {
public:
    void execute(std::stack<double>& stack) const override {
        double b = stack.top(); stack.pop();
        double a = stack.top(); stack.pop();
        stack.push(a * b);
    }
};

// Команда деления первого элемента стека на второй.
class DivideCommand : public Command {
public:
    void execute(std::stack<double>& stack) const override {
        double b = stack.top(); stack.pop();
        double a = stack.top(); stack.pop();
        if (b == 0) {
            throw std::runtime_error("Division by zero"); // Проверка на деление на ноль.
        }
        stack.push(a / b);
    }
};

// Команда возведения первого элемента стека в степень второго.
class PowerCommand : public Command {
public:
    void execute(std::stack<double>& stack) const override {
        double b = stack.top(); stack.pop();
        double a = stack.top(); stack.pop();
        stack.push(pow(a, b));
    }
};

// Команда вычисления квадратного корня из верхнего элемента стека.
class SqrtCommand : public Command {
public:
    void execute(std::stack<double>& stack) const override {
        double a = stack.top(); stack.pop();
        if (a < 0) {
            throw std::runtime_error("Square root of negative number"); // Проверка на отрицательное число.
        }
        stack.push(sqrt(a));
    }
};

// Команда вычисления синуса верхнего элемента стека (в радианах).
class SinCommand : public Command {
public:
    void execute(std::stack<double>& stack) const override {
        double a = stack.top(); stack.pop();
        stack.push(sin(a));
    }
};

// Команда вычисления косинуса верхнего элемента стека (в радианах).
class CosCommand : public Command {
public:
    void execute(std::stack<double>& stack) const override {
        double a = stack.top(); stack.pop();
        stack.push(cos(a));
    }
};

// Команда вычисления тангенса верхнего элемента стека (в радианах).
class TanCommand : public Command {
public:
    void execute(std::stack<double>& stack) const override {
        double a = stack.top(); stack.pop();
        stack.push(tan(a));
    }
};

// Команда вычисления натурального логарифма верхнего элемента стека.
class LogCommand : public Command {
public:
    void execute(std::stack<double>& stack) const override {
        double a = stack.top(); stack.pop();
        if (a <= 0) {
            throw std::runtime_error("Logarithm of non-positive number");
        }
        stack.push(log(a));
    }
};

// Команда вычисления десятичного логарифма верхнего элемента стека.
class Log10Command : public Command {
public:
    void execute(std::stack<double>& stack) const override {
        double a = stack.top(); stack.pop();
        if (a <= 0) {
            throw std::runtime_error("Logarithm of non-positive number");
        }
        stack.push(log10(a));
    }
};

// Команда вычисления факториала верхнего элемента стека.
class FactorialCommand : public Command {
public:
    void execute(std::stack<double>& stack) const override {
        double a = stack.top(); stack.pop();
        if (a < 0 || floor(a) != a) {
            throw std::runtime_error("Factorial of a non-integer or negative number"); // Проверка на целое и неотрицательное значение.
        }
        double result = 1;
        for (int i = 1; i <= static_cast<int>(a); ++i) {
            result *= i;
        }
        stack.push(result);
    }
};

// Команда добавления числа Пи в стек.
class PiCommand : public Command {
public:
    void execute(std::stack<double>& stack) const override {
        stack.push(M_PI);
    }
};
