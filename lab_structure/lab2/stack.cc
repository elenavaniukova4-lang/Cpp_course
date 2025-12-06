#ifndef STACK_CPP
#define STACK_CPP

#include "stack.h"

template<typename T>
Stack<T>::Stack(size_t maxStackSize) : data(maxStackSize), maxSize(maxStackSize), currentSize(0) {}

template<typename T>
void Stack<T>::push(T& value) {
    if (currentSize >= maxSize) {
        throw std::overflow_error("Stack overflow");
    }
    data.push_back(value);
    currentSize = data.size();
}

template<typename T>
T& Stack<T>::top() {
    if (isEmpty()) {
        throw std::out_of_range("Stack is empty");
    }
    return data.back();
}

template<typename T>
const T& Stack<T>::top() const {
    if (isEmpty()) {
        throw std::out_of_range("Stack is empty");
    }
    return data.back();
}

template<typename T>
T Stack<T>::pop() {
    if (isEmpty()) {
        throw std::out_of_range("Stack is empty");
    }
    T value = data.back();
    data.pop_back();
    currentSize = data.size();
    return value;
}

template<typename T>
bool Stack<T>::isEmpty() const {
    return data.empty();
}

template<typename T>
size_t Stack<T>::size() const {
    return currentSize;
}

template<typename T>
size_t Stack<T>::getMaxSize() const {
    return maxSize;
}

#endif // STACK_CPP
