#include <cstddef>
#include <stdexcept>

template <typename T>
Array<T>::Array() : _size(0), _arr(NULL) {
}

template <typename T>
Array<T>::Array(unsigned int n) : _size(n), _arr(n == 0 ? NULL : new T[n]()) {
}

template <typename T>
Array<T>::Array(const Array& other) : _size(other._size), _arr(_size == 0 ? NULL : new T[_size]()) {
    for (size_t i = 0; i < _size; i++)
        _arr[i] = other._arr[i];
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other) {
    if (this != &other) {
        Array<T> tmp(other);
        T* arrAdd = tmp._arr;
        tmp._arr = _arr;
        _arr = arrAdd;

        _size = other._size;
    }
    return *this;
}

template <typename T>
Array<T>::~Array() {
    delete[] _arr;
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const {
    if (_arr == NULL) {
        throw std::out_of_range("Array has 0 elements.");
    }
    if (index >= _size) {
        throw std::out_of_range("Index out of bounds.");
    }
    return _arr[index];
}

template <typename T>
T& Array<T>::operator[](unsigned int index) {
    if (_arr == NULL) {
        throw std::out_of_range("Array has 0 elements.");
    }
    if (index >= _size) {
        throw std::out_of_range("Index out of bounds.");
    }
    return _arr[index];
}

template <typename T>
unsigned int Array<T>::size() const {
    return _size;
}
