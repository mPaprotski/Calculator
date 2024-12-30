#ifndef TOKENIZE_H
#define TOKENIZE_H

#include <string>
#include <vector>
#include <sstream>
#include <cctype>

// Функция tokenize:
// Разбивает строку на отдельные токены (числа, операторы, скобки).
// Токены разделяются пробелами или специальными символами, такими как операторы и скобки.
//
// Параметры:
//   expression - входная строка выражения.
//
// Возвращает:
//   Вектор строк, где каждая строка является токеном выражения.
inline std::vector<std::string> tokenize(const std::string& expression) {
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream stream(expression);

    while (stream >> token) {
        tokens.push_back(token);
    }

    return tokens;
}

#endif // TOKENIZE_H
