#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include <stdexcept>

template<typename T>
class DynamicArray {
private:
    T* data;
    size_t capacity;
    size_t length;

public:

    DynamicArray(size_t initialCapacity = 10);
    ~DynamicArray();
    DynamicArray(const DynamicArray& other);
    DynamicArray& operator=(const DynamicArray& other);
    void push_back(const T& value);
    void pop_back();
    T& operator[](size_t index);
    const T& operator[](size_t index) const;
    T& back();
    const T& back() const;
    size_t size() const;
    bool empty() const;
    void resize(size_t newSize);
};

#include "DynamicArray.cpp"
#endif

