#ifndef JAKDOJADE_PRIORITYQUEUE_H
#define JAKDOJADE_PRIORITYQUEUE_H
#include <iostream>
#include "MyVector.hxx"

template <typename T>
class PriorityQueue {
private:
    MyVector<T> heap;

    void heapify_up(int index);

    void heapify_down(int index);

public:
    PriorityQueue();

    bool empty();

    void push(T& value);

    T& pop();

    T& top();



};


#endif //JAKDOJADE_PRIORITYQUEUE_H
