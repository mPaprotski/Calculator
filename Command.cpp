#include <cmath>
#include <stack>
#include <stdexcept>

class Command {
public:
    virtual void execute(std::stack<double>& stack) const = 0;
    virtual ~Command() = default;
};

class AddCommand : public Command {
public:
    void execute(std::stack<double>& stack) const override {
        double b = stack.top(); stack.pop();
        double a = stack.top(); stack.pop();
        stack.push(a + b);
    }
};

class SubtractCommand : public Command {
public:
    void execute(std::stack<double>& stack) const override {
        double b = stack.top(); stack.pop();
        double a = stack.top(); stack.pop();
        stack.push(a - b);
    }
};

class MultiplyCommand : public Command {
public:
    void execute(std::stack<double>& stack) const override {
        double b = stack.top(); stack.pop();
        double a = stack.top(); stack.pop();
        stack.push(a * b);
    }
};

class DivideCommand : public Command {
public:
    void execute(std::stack<double>& stack) const override {
        double b = stack.top(); stack.pop();
        double a = stack.top(); stack.pop();
        if (b == 0) {
            throw std::runtime_error("Division by zero");
        }
        stack.push(a / b);
    }
};

class PowerCommand : public Command {
public:
    void execute(std::stack<double>& stack) const override {
        double b = stack.top(); stack.pop();
        double a = stack.top(); stack.pop();
        stack.push(pow(a, b));
    }
};

class SqrtCommand : public Command {
public:
    void execute(std::stack<double>& stack) const override {
        double a = stack.top(); stack.pop();
        if (a < 0) {
            throw std::runtime_error("Square root of negative number");
        }
        stack.push(sqrt(a));
    }
};

class SinCommand : public Command {
public:
    void execute(std::stack<double>& stack) const override {
        double a = stack.top(); stack.pop();
        stack.push(sin(a));
    }
};

class CosCommand : public Command {
public:
    void execute(std::stack<double>& stack) const override {
        double a = stack.top(); stack.pop();
        stack.push(cos(a));
    }
};

class TanCommand : public Command {
public:
    void execute(std::stack<double>& stack) const override {
        double a = stack.top(); stack.pop();
        stack.push(tan(a));
    }
};
