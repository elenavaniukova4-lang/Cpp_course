#ifndef QUEUE_H
#define QUEUE_H

#include "stack.h"
#include "queue.cpp"
#include <stdexcept>

template<typename T>
class Queue {
private:
    Stack<T> stackIn;
    Stack<T> stackOut;
    size_t queueSize;
    void transferElements();

public:

    //Queue(size_t maxQueueSize = 100);
    void enqueue( T& value);
    T dequeue();
    bool isEmpty() const;
    size_t size() const;
    T& front();
    const T& front() const;
};

#endif
