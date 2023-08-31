#include <iostream>
#include "PriorityQueue.h"
using namespace std;

template <typename T>
void PriorityQueue<T>::heapify_up(int index) {
    if (index == 0) {
        return;
    }
    int parent_index = (index - 1) / 2;
    if (heap[parent_index] < heap[index]) {
        swap(heap[parent_index], heap[index]);
        heapify_up(parent_index);
    }
}

template <typename T>
void PriorityQueue<T>::heapify_down(int index) {
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

template <typename T>
PriorityQueue<T>::PriorityQueue() {}

template <typename T>
bool PriorityQueue<T>::empty() {
    if (heap.getSize() == 0) {
        return true;
    }
    else {
        return false;
    }
}

template <typename T>
void PriorityQueue<T>::push(T& value) {
    heap.push_back(value);
    heapify_up(heap.getSize() - 1);
}

template <typename T>
T& PriorityQueue<T>::pop() {
    T top = heap[0];
    heap[0] = heap.back();
    heap.pop_back();
    heapify_down(0);
    return top;
}

template <typename T>
T& PriorityQueue<T>::top() {
    return heap[0];
}