#include "iter.hpp"
#include <iostream>
#include <string>

void incrementFT(int& n) {
    n += 42;
}

template <typename T>
void display(const T& item) {
    std::cout << "[ " << item << " ] ";
}

int main() {
    std::cout << "========== TEST 1: int array ==========\n";
    int intArray[] = {0, 10, 20, 30};
    size_t intLen = sizeof(intArray) / sizeof(intArray[0]);

    std::cout << "Before: ";
    ::iter(intArray, intLen, display<int>);
    std::cout << "\n";

    ::iter(intArray, intLen, incrementFT);
    std::cout << "After:  ";
    ::iter(intArray, intLen, display<int>);
    std::cout << "\n\n";


    std::cout << "========== TEST 2: std::string array ==========\n";
    std::string strArray[] = {"Debian", "Arch", "Ubuntu", "Fedora"};
    size_t strLen = sizeof(strArray) / sizeof(strArray[0]);

    std::cout << "Strings: ";
    ::iter(strArray, strLen, display<std::string>);
    std::cout << "\n\n";


    std::cout << "========== TEST 3: CONST int array ==========\n";
    const int constArray[] = {42, -42, 21, -21};
    size_t constLen = sizeof(constArray) / sizeof(constArray[0]);

    std::cout << "Const Array: ";
    ::iter(constArray, constLen, display<int>);
    std::cout << "\n\n";

    std::cout << "================= ALL TESTS PASSED =================\n";

    return 0;
}
