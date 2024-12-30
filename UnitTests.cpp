// UnitTests.cpp
#include <iostream>
#include <cassert>
#include <cmath>
#include "Calculator.cpp"
#include "RPN.h"
#include "Command.cpp"

void testAddition() {
    Calculator calc;
    std::string postfix = "3 5 +";
    std::ostringstream output;
    std::streambuf* oldCoutBuf = std::cout.rdbuf(output.rdbuf());

    calc.execute(postfix);
    std::cout.rdbuf(oldCoutBuf);

    assert(output.str() == "Result: 8\n");
}

void testSubtraction() {
    Calculator calc;
    std::string postfix = "10 4 -";
    std::ostringstream output;
    std::streambuf* oldCoutBuf = std::cout.rdbuf(output.rdbuf());

    calc.execute(postfix);
    std::cout.rdbuf(oldCoutBuf);

    assert(output.str() == "Result: 6\n");
}

void testMultiplication() {
    Calculator calc;
    std::string postfix = "7 6 *";
    std::ostringstream output;
    std::streambuf* oldCoutBuf = std::cout.rdbuf(output.rdbuf());

    calc.execute(postfix);
    std::cout.rdbuf(oldCoutBuf);

    assert(output.str() == "Result: 42\n");
}

void testDivision() {
    Calculator calc;
    std::string postfix = "8 2 /";
    std::ostringstream output;
    std::streambuf* oldCoutBuf = std::cout.rdbuf(output.rdbuf());

    calc.execute(postfix);
    std::cout.rdbuf(oldCoutBuf);

    assert(output.str() == "Result: 4\n");
}

void testPower() {
    Calculator calc;
    std::string postfix = "2 3 ^";
    std::ostringstream output;
    std::streambuf* oldCoutBuf = std::cout.rdbuf(output.rdbuf());

    calc.execute(postfix);
    std::cout.rdbuf(oldCoutBuf);

    assert(output.str() == "Result: 8\n");
}

void testSqrt() {
    Calculator calc;
    std::string postfix = "9 sqrt";
    std::ostringstream output;
    std::streambuf* oldCoutBuf = std::cout.rdbuf(output.rdbuf());

    calc.execute(postfix);
    std::cout.rdbuf(oldCoutBuf);

    assert(output.str() == "Result: 3\n");
}

void testSin() {
    Calculator calc;
    std::string postfix = "0 sin";
    std::ostringstream output;
    std::streambuf* oldCoutBuf = std::cout.rdbuf(output.rdbuf());

    calc.execute(postfix);
    std::cout.rdbuf(oldCoutBuf);

    assert(output.str() == "Result: 0\n");
}

void testCos() {
    Calculator calc;
    std::string postfix = "0 cos";
    std::ostringstream output;
    std::streambuf* oldCoutBuf = std::cout.rdbuf(output.rdbuf());

    calc.execute(postfix);
    std::cout.rdbuf(oldCoutBuf);

    assert(output.str() == "Result: 1\n");
}

void testTan() {
    Calculator calc;
    std::string postfix = "0 tan";
    std::ostringstream output;
    std::streambuf* oldCoutBuf = std::cout.rdbuf(output.rdbuf());

    calc.execute(postfix);
    std::cout.rdbuf(oldCoutBuf);

    assert(output.str() == "Result: 0\n");
}

void testLog() {
    Calculator calc;
    std::string postfix = "2.71828 log";
    std::ostringstream output;
    std::streambuf* oldCoutBuf = std::cout.rdbuf(output.rdbuf());

    calc.execute(postfix);
    std::cout.rdbuf(oldCoutBuf);

    assert(output.str() == "Result: 1\n");
}

void testLog10() {
    Calculator calc;
    std::string postfix = "10 log10";
    std::ostringstream output;
    std::streambuf* oldCoutBuf = std::cout.rdbuf(output.rdbuf());

    calc.execute(postfix);
    std::cout.rdbuf(oldCoutBuf);

    assert(output.str() == "Result: 1\n");
}

void testFactorial() {
    Calculator calc;
    std::string postfix = "5 !";
    std::ostringstream output;
    std::streambuf* oldCoutBuf = std::cout.rdbuf(output.rdbuf());

    calc.execute(postfix);
    std::cout.rdbuf(oldCoutBuf);

    assert(output.str() == "Result: 120\n");
}

void testPi() {
    Calculator calc;
    std::string postfix = "pi";
    std::ostringstream output;
    std::streambuf* oldCoutBuf = std::cout.rdbuf(output.rdbuf());

    calc.execute(postfix);
    std::cout.rdbuf(oldCoutBuf);

    assert(fabs(std::stod(output.str().substr(8)) - M_PI) < 1e-9);
}

void runAllTests() {
    testAddition();
    testSubtraction();
    testMultiplication();
    testDivision();
    testPower();
    testSqrt();
    testSin();
    testCos();
    testTan();
    testLog();
    testLog10();
    testFactorial();
    testPi();

    std::cout << "All tests passed successfully!\n";
}

int main() {
    runAllTests();
    return 0;
}
