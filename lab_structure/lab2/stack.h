#ifndef STACK_H
#define STACK_H

#include "DynamicArray.h"
#include "stack.cpp"
#include <stdexcept>

template<typename T>
class Stack {
private:
    DynamicArray<T> data;
    size_t maxSize;
    size_t currentSize;

public:
    //Stack(size_t maxStackSize = 100);
    void push(T& value);
    T& top();
    const T& top() const;
    T pop();
    bool isEmpty() const;
    size_t size() const;
    size_t getMaxSize() const;
};

#endif
