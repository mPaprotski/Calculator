#include <iostream>
#include <string>
#include "Calculator.cpp"

int main() {
    Calculator calculator; // Создание объекта калькулятора.

    // Основной цикл программы для обработки пользовательского ввода.
    while (true) {
        std::cout << "Operations:\n1) +\t2) -\t3) *\t4) /\t5) ^\n6) sqrt\t7) sin\t8) cos\t9) tan\n10) !(factorial)\t11) pi\n";
        std::string input;
        std::cout << "Write all operations and numbers separated by spaces\n";
        std::cout << "Enter an expression (or type 'exit' to quit): ";
        std::getline(std::cin, input); // Чтение строки ввода от пользователя.

        // Проверка команды выхода.
        if (input == "exit") {
            std::cout << "Exiting the calculator. Goodbye!" << std::endl;
            break;
        }

        try {
            // Преобразование выражения из инфиксной записи в постфиксную.
            std::string postfix = infixToPostfix(input);
            std::cout << "Postfix expression: " << postfix << std::endl;

            // Вычисление результата постфиксного выражения.
            calculator.execute(postfix);
        } catch (const std::exception& e) {
            // Обработка ошибок, связанных с вводом пользователя.
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }

    return 0; // Завершение программы.
}
