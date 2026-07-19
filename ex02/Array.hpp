#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>

template <typename T>
class Array {
    private:
        unsigned int _size;
        T* _arr;
    public:
        Array();
        Array(unsigned int n);
        Array(const Array& other);
        Array& operator=(const Array& other);
        ~Array();
        const T& operator[](unsigned int index) const;
        T& operator[](unsigned int index);
        unsigned int size() const;
};

#include "Array.tpp"
#endif /*ARRAY_HPP*/
