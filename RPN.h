#ifndef RPN_H
#define RPN_H

#include <string>
#include <map>
#include <sstream>
#include <stdexcept>
#include <vector>
#include "Tokenize.h"

inline std::string infixToPostfix(const std::string& infix) {
    std::map<std::string, int> precedence = {
        {"+", 1}, {"-", 1}, {"*", 2}, {"/", 2}, {"^", 3},
        {"sin", 4}, {"cos", 4}, {"tan", 4}, {"sqrt", 4}
    };

    std::vector<std::string> operators;
    std::ostringstream output;
    std::vector<std::string> tokens = tokenize(infix);

    for (const std::string& token : tokens) {
        if (std::isdigit(token[0]) || (token[0] == '-' && token.size() > 1 && std::isdigit(token[1])) || token.find('.') != std::string::npos) {
            output << token << ' ';
        }
        else if (precedence.count(token)) {
            while (!operators.empty() && operators.back() != "(" &&
                precedence[operators.back()] >= precedence[token]) {
                output << operators.back() << ' ';
                operators.pop_back();
            }
            operators.push_back(token);
        }
        else if (token == "(") {
            operators.push_back(token);
        }
        else if (token == ")") {
            while (!operators.empty() && operators.back() != "(") {
                output << operators.back() << ' ';
                operators.pop_back();
            }
            if (operators.empty()) {
                throw std::runtime_error("Mismatched parentheses");
            }
            operators.pop_back();
        }
        else {
            throw std::runtime_error("Unknown token: " + token);
        }
    }

    while (!operators.empty()) {
        if (operators.back() == "(") {
            throw std::runtime_error("Mismatched parentheses");
        }
        output << operators.back() << ' ';
        operators.pop_back();
    }

    return output.str();
}

#endif // RPN_H