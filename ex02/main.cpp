#include <iostream>
#include <string>
#include <cstdlib>
#include "Array.hpp"

template <typename T>
void printArray(const Array<T>& arr, const std::string& name) {
    std::cout << name << " (size " << arr.size() << "): [ ";
    for (unsigned int i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << (i < arr.size() - 1 ? ", " : "");
    }
    std::cout << " ]\n";
}

int main() {
    std::cout << "================ Test 1: ALLOCATION ================\n";

    Array<int> emptyArray;
    std::cout << "Empty array size: " << emptyArray.size() << "\n";
    printArray(emptyArray, "empty array");

    Array<int> intArray(5);
    std::cout << "Parameterized array size: " << intArray.size() << "\n";
    printArray(intArray, "intArray");

    std::cout << "\n================ Test 2: READ / WRITE ================\n";

    for (unsigned int i = 0; i < intArray.size(); i++) {
        intArray[i] = i + 13;
    }
    printArray(intArray, "modified intArray");

    Array<std::string> strArray(3);
    strArray[0] = "AAA";
    strArray[1] = "BBB";
    strArray[2] = "CCC";
    printArray(strArray, "strArray");

    std::cout << "\n================ Test 3: DEEP COPY & MEMORY SAFETY ================\n";

    Array<int> copyArray(intArray);
    std::cout << "-- Created copyArray via Copy Constructor\n";

    Array<int> assignArray;
    assignArray = intArray;
    std::cout << "-- Created assignArray via Assignment Operator.\n\n";

    std::cout << "-- Modifying original intArray...\n";
    intArray[0] = 9191;
    intArray[4] = 9191;

    printArray(intArray, "Original intArray");
    printArray(copyArray, "copyArray");
    printArray(assignArray, "assignArray");

    std::cout << "\n================ Test 4: EXCEPTIONS ================\n";

    std::cout << "Trying to access intArray[10] (out of bounds)...\n";
    try {
        intArray[10] = 42;
        std::cout << "FAIL: Exception was not thrown!\n";
    }
    catch (const std::exception& e) {
        std::cout << "SUCCESS: Exception caught -> " << e.what() << "\n";
    }

    std::cout << "Trying to access emptyArray[0] (out of bounds)...\n";
    try {
        std::cout << emptyArray[0] << "\n";
        std::cout << "FAIL: Exception was not thrown!\n";
    }
    catch (const std::exception& e) {
        std::cout << "SUCCESS: Exception caught -> " << e.what() << "\n";
    }

    std::cout << "Trying to access strArray[-1] (negative index)...\n";
    try {
        strArray[-1] = "Hacked";
        std::cout << "FAIL: Exception was not thrown!\n";
    }
    catch (const std::exception& e) {
        std::cout << "SUCCESS: Exception caught -> " << e.what() << "\n";
    }

    std::cout << "\n================ ALL TESTS EXECUTED! ================\n";

    return 0;
}