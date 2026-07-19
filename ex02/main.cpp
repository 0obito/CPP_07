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
    std::cout << "=========================================================\n";
    std::cout << "                   PHASE 1: ALLOCATION                   \n";
    std::cout << "=========================================================\n";

    // 1. Default Constructor
    Array<int> emptyArray;
    std::cout << "Empty array size: " << emptyArray.size() << " (Expected: 0)\n";

    // 2. Parameterized Constructor
    Array<int> intArray(5);
    std::cout << "Parameterized array size: " << intArray.size() << " (Expected: 5)\n";
    
    // Prove default initialization (ints should be 0)
    printArray(intArray, "intArray (default)");

    std::cout << "\n=========================================================\n";
    std::cout << "                 PHASE 2: READ / WRITE                   \n";
    std::cout << "=========================================================\n";

    for (unsigned int i = 0; i < intArray.size(); i++) {
        intArray[i] = (i + 1) * 10; // 10, 20, 30, 40, 50
    }
    printArray(intArray, "intArray (populated)");

    // String array test
    Array<std::string> strArray(3);
    strArray[0] = "Debian";
    strArray[1] = "Arch";
    strArray[2] = "Ubuntu";
    printArray(strArray, "strArray");

    std::cout << "\n=========================================================\n";
    std::cout << "           PHASE 3: DEEP COPY & MEMORY SAFETY            \n";
    std::cout << "=========================================================\n";

    // Copy Constructor Test
    Array<int> copyArray(intArray);
    std::cout << "--> Created copyArray via Copy Constructor.\n";

    // Assignment Operator Test
    Array<int> assignArray;
    assignArray = intArray;
    std::cout << "--> Created assignArray via Assignment Operator.\n\n";

    std::cout << "--> Modifying original intArray...\n";
    intArray[0] = 9999;
    intArray[4] = 9999;

    printArray(intArray, "Original intArray ");
    printArray(copyArray, "copyArray         "); // Should NOT have 9999
    printArray(assignArray, "assignArray       "); // Should NOT have 9999

    std::cout << "\n=========================================================\n";
    std::cout << "                  PHASE 4: EXCEPTIONS                    \n";
    std::cout << "=========================================================\n";

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

    // Testing negative bounds 
    // (Note: -1 casts to the maximum unsigned int value, which is > size)
    std::cout << "Trying to access strArray[-1] (negative index)...\n";
    try {
        strArray[-1] = "Hacked";
        std::cout << "FAIL: Exception was not thrown!\n";
    }
    catch (const std::exception& e) {
        std::cout << "SUCCESS: Exception caught -> " << e.what() << "\n";
    }

    std::cout << "\n=========================================================\n";
    std::cout << "          ALL TESTS EXECUTED. CHECK FOR LEAKS!           \n";
    std::cout << "=========================================================\n";

    return 0;
}