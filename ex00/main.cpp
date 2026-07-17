#include "whatever.hpp"
#include <iostream>
#include <string>

class A {
    private:
        int _a;
    public:
        A() : _a(0){};
        A(int val) : _a(val){};
        A(const A& other) : _a(other._a){};
        A& operator=(const A& other) {
            if (this != &other)
                _a = other._a;
            return *this;
        }
        int getVal() {return _a;}
        bool operator<(const A& other) {
            if (_a < other._a) {
                return true;
            }
            else {
                return false;
            }
        }
        bool operator>(const A& other) {
            if (_a > other._a) {
                return true;
            }
            else {
                return false;
            }
        }
};

int main() {
    A aA(99), bA(66);
    int a = 9, b = 10;

    std::cout<<"---------- 1: SWAP tests: ----------\n";

    std::cout<<"a = "<<a<<" and b = "<<b<<"\n";
    swap(a, b);
    std::cout<<"swap performed\n";
    std::cout<<"a = "<<a<<" and b = "<<b<<"\n";

    std::cout<<"aA = "<<aA.getVal()<<" and bA = "<<bA.getVal()<<"\n";
    swap(aA, bA);
    std::cout<<"swap performed\n";
    std::cout<<"aA = "<<aA.getVal()<<" and bA = "<<bA.getVal()<<"\n";


    std::cout<<"---------- 2: MIN tests: ----------\n";
    // back to how it was first
    swap(a, b);
    swap(aA, bA);

    std::cout<<"a = "<<a<<" and b = "<<b<<"\n";
    std::cout<<"The min value between a and b is: "<<min(a, b)<<"\n";

    std::cout<<"aA = "<<aA.getVal()<<" and bA = "<<bA.getVal()<<"\n";
    std::cout<<"The min value between aA and bA is: "<<min(aA, bA).getVal()<<"\n";

    std::cout<<"---------- 3: MAX tests: ----------\n";

    std::cout<<"a = "<<a<<" and b = "<<b<<"\n";
    std::cout<<"The max value between a and b is: "<<max(a, b)<<"\n";

    std::cout<<"aA = "<<aA.getVal()<<" and bA = "<<bA.getVal()<<"\n";
    std::cout<<"The max value between aA and bA is: "<<max(aA, bA).getVal()<<"\n";

    return 0;
}
