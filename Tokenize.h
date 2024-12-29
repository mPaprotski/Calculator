#ifndef TOKENIZE_H
#define TOKENIZE_H

#include <string>
#include <vector>
#include <cctype>

inline std::vector<std::string> tokenize(const std::string& infix) {
    std::vector<std::string> tokens;
    std::string token;

    for (char ch : infix) {
        if (std::isspace(ch)) {
            continue;
        }

        if (std::isdigit(ch) || ch == '.') {
            token += ch;
        }
        else if (std::isalpha(ch)) {
            token += ch;
            if (token == "sin" || token == "cos" || token == "tan" || token == "sqrt") {
                tokens.push_back(token);
                token.clear();
            }
        }
        else {
            if (!token.empty()) {
                tokens.push_back(token);
                token.clear();
            }
            tokens.push_back(std::string(1, ch));
        }
    }

    if (!token.empty()) {
        tokens.push_back(token);
    }

    return tokens;
}

#endif 
