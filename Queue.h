#ifndef JAKDOJADE_QUEUE_H
#define JAKDOJADE_QUEUE_H

#include <iostream>
#include "MyVector.h"
#include "Graph.h"


class Queue {
private:
    MyVector<Vertex> heap;
    void heapify_up(int index) {
        if (index == 0) {
            return;
        }
        int parent_index = (index - 1) / 2;
        if (heap[parent_index] < heap[index]) {
            swap(heap[parent_index], heap[index]);
            heapify_up(parent_index);
        }
    }
    void heapify_down(int index) {
        int left_child_index = 2 * index + 1;
        int right_child_index = 2 * index + 2;
        int largest_index = index;
        if (left_child_index < heap.getSize() && heap[left_child_index] > heap[largest_index]) {
            largest_index = left_child_index;
        }
        if (right_child_index < heap.getSize() && heap[right_child_index] > heap[largest_index]) {
            largest_index = right_child_index;
        }
        if (largest_index != index) {
            swap(heap[index], heap[largest_index]);
            heapify_down(largest_index);
        }
    }
public:
    Queue() {}
    bool empty() {
        if (heap.getSize() == 0) {
            return true;
        }
        else {
            return false;
        }
    }
    void push(Vertex value) {
        heap.push_back(value);
        heapify_up(heap.getSize() - 1);
    }
    Vertex pop() {
        Vertex top = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapify_down(0);
        return top;
    }

    Vertex top() {
        return heap[0];
    }
};

#endif //JAKDOJADE_QUEUE_H
