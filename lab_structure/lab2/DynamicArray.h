#ifndef DYN_ARR_CPP
#define DYN_ARR_CPP

#include "DynamicArray.h"

template<typename T>
DynamicArray<T>::DynamicArray(size_t initialCapacity) : capacity(initialCapacity), length(0) {
    data = new T[capacity];
}

template<typename T>
DynamicArray<T>::~DynamicArray() {
    delete[] data;
}

template<typename T>
DynamicArray<T>::DynamicArray(const DynamicArray& other){
    length = other.length;
    capacity = other.capacity;
    data = new T[capacity];
    
    for (size_t i = 0; i < length; ++i) {
        data[i] = other.data[i];
    }
}

template<typename T>
DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray& other) {
    if (this != &other) {
        delete[] data;
        capacity = other.capacity;
        length = other.length;
        data = new T[capacity];
        for (size_t i = 0; i < length; ++i) {
            data[i] = other.data[i];
        }
    }
    return *this;
}

template<typename T>
void DynamicArray<T>::push_back(const T& value) {
    if (length >= capacity) {
        capacity *= 2;
        
        T* tempArray = new T[capacity];
        for (size_t i = 0; i < length; ++i) {
            tempArray[i] = data[i];
        }
        
        delete[] data;
        data = tempArray;
    }
    data[++length] = value;
}

template<typename T>
void DynamicArray<T>::pop_back() {
    if (length >= capacity) {
        capacity *= 2;
        
        T* tempArray = new T[capacity];
        for (size_t i = 0; i < length - 1; ++i) {
            tempArray[i] = data[i];
        }
        
        delete[] data;
        data = tempArray;
        --length;
    }
}

template<typename T>
T& DynamicArray<T>::operator[](size_t index) {
    if (index >= length) {
        throw std::invalid_argument("capacity out of range !!");
    }
    return data[index];
}

template<typename T>
const T& DynamicArray<T>::operator[](size_t index) const {
    if (index >= length) {
        throw std::invalid_argument("capacity out of range !!");
    }
    return data[index];
}

template<typename T>
T& DynamicArray<T>::back() {
    if (length == 0) {
        throw std::invalid_argument("Array is empty");
    }
    return data[length - 1];
}

template<typename T>
const T& DynamicArray<T>::back() const {
    if (length == 0) {
        throw std::invalid_argument("Array is empty");
    }
    return data[length - 1];
}

template<typename T>
size_t DynamicArray<T>::size() const {
    return length;
}

template<typename T>
bool DynamicArray<T>::empty() const {
    return length == 0;
}

template<typename T>
void DynamicArray<T>::resize(size_t newSize) {
    if (newSize > capacity) {
        capacity = newSize;
        T* newData = new T[capacity];
        for (size_t i = 0; i < length; ++i) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
    }
    length = newSize;
}

#endif 
