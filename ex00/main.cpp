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
        ~A(){};
        int getValue() const {return _a;}
        bool operator<(const A& other) const {
            return (_a < other._a);
        }
        bool operator>(const A& other) const {
            return (_a > other._a);
        }
};

class B {
    private:
        int _b;
    public:
        B():_b(0){}
        B(int value):_b(value){}
        B(const B& other): _b(other._b){}
        B& operator=(const B& other){
            if (this != &other)
                _b = other._b;
            return *this;
        }
        ~B(){}
        int getValue() const {return _b;}
};

int main() {
    int x = 9, y = 10;
    A aA(99), bA(66);

    std::cout<<"---------- 1: SWAP tests: ----------\n\n";

    std::cout<<"x = "<<x<<" and y = "<<y<<"\n";
    ::swap(x, y);
    std::cout<<"swap performed\n";
    std::cout<<"x = "<<x<<" and y = "<<y<<"\n\n";

    std::cout<<"aA = "<<aA.getValue()<<" and bA = "<<bA.getValue()<<"\n";
    ::swap(aA, bA);
    std::cout<<"swap performed\n";
    std::cout<<"aA = "<<aA.getValue()<<" and bA = "<<bA.getValue()<<"\n\n";


    std::cout<<"---------- 2: MIN tests: ----------\n\n";
    // back to how it was first
    ::swap(x, y);
    ::swap(aA, bA);

    std::cout<<"x = "<<x<<" and y = "<<y<<"\n";
    std::cout<<"The min value between x and y is: "<<::min(x, y)<<"\n\n";

    std::cout<<"aA = "<<aA.getValue()<<" and bA = "<<bA.getValue()<<"\n";
    std::cout<<"The min value between aA and bA is: "<<::min(aA, bA).getValue()<<"\n\n";

    std::cout<<"---------- 3: MAX tests: ----------\n\n";

    std::cout<<"x = "<<x<<" and y = "<<y<<"\n";
    std::cout<<"The max value between x and y is: "<<::max(x, y)<<"\n\n";

    std::cout<<"aA = "<<aA.getValue()<<" and bA = "<<bA.getValue()<<"\n";
    std::cout<<"The max value between aA and bA is: "<<::max(aA, bA).getValue()<<"\n\n";

    std::cout<<"---------- end of my personal tests ----------\n";


    std::cout<<"\n\n---------- subject suggested tests ----------\n\n";

    int a = 2;
    int b = 3;
    ::swap( a, b );
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
    std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
    std::string c = "chaine1";
    std::string d = "chaine2";
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

    std::cout<<"\n---------- end of subject tests ----------\n";

    return 0;
}



