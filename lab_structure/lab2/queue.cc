#ifndef QUEUE_CPP
#define QUEUE_CPP

#include "queue.h"

template<typename T>
void Queue<T>::transferElements() {
    while (!stackIn.isEmpty()) {
        stackOut.push(stackIn.pop());
    }
}

template<typename T>
Queue<T>::Queue(size_t maxQueueSize) {
    stackIn = Stack<T>(maxQueueSize);
    stackOut = Stack<T>(maxQueueSize);
    queueSize = 0;
}

template<typename T>
void Queue<T>::enqueue( T& value) {
    if (queueSize >= stackIn.getMaxSize()) {
        throw std::overflow_error("Queue overflow");
    }
    stackIn.data[stackIn.top] = value;
    stackIn.top++;
    queueSize++;
}

template<typename T>
T Queue<T>::dequeue() {
    if (isEmpty()) {
        throw std::invalid_argument("Queue is empty");
    }

    if (stackOut.isEmpty()) {
        transferElements();
    }
    
    T value = stackOut.pop();
    queueSize--;
    return value;
}

template<typename T>
bool Queue<T>::isEmpty() const {
    return queueSize == 0;
}

template<typename T>
size_t Queue<T>::size() const {
    return queueSize;
}

template<typename T>
T& Queue<T>::front() {
    if (isEmpty()) {
        throw std::invalid_argument("Queue is empty");
    }
    
    if (stackOut.isEmpty()) {
        transferElements();
    }
    
    return stackOut.top();
}

template<typename T>
const T& Queue<T>::front() const {
    if (isEmpty()) {
        throw std::invalid_argument("Queue is empty");
    }
    
    Queue<T>* nonConstThis = const_cast<Queue<T>*>(this);
    if (stackOut.isEmpty()) {
        nonConstThis->transferElements();
    }
    
    return stackOut.top();
}

#endif 
