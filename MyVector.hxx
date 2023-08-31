#include "MyVector.h"
#include <iostream>

using namespace std;

template <typename T>
MyVector<T>::MyVector() {
    elements = new T[10]; // domyślna pojemność to 10
    capacity = 10;
    size = 0;
}

template <typename T>
MyVector<T>::MyVector(int n, T val) {
    elements = new T[n];
    capacity = n;
    size = n;
    for (int i = 0; i < n; i++) {
        elements[i] = val;
    }
}

// Konstruktor kopiujący
template <typename T>
MyVector<T>::MyVector(const MyVector& other) {
    elements = new T[other.capacity];
    capacity = other.capacity;
    size = other.size;
    for (int i = 0; i < size; i++) {
        elements[i] = other.elements[i];
    }
}

template <typename T>
MyVector<T>::~MyVector() {
    delete[] elements;
}

template <typename T>
void MyVector<T>::push_back(const T& x) {
    if (size == capacity) {
        capacity *= 2;
        T* newElements = new T[capacity];
        for (int i = 0; i < size; i++) {
            newElements[i] = elements[i];
        }
        delete[] elements;
        elements = newElements;
    }
    elements[size] = x;
    size++;
}

template <typename T>
T& MyVector<T>::operator[](int index) {
    if (index < 0 || index >= size) {
        cerr << "Index out of range" << std::endl;
        exit(1);
    }
    return elements[index];
}

template <typename T>
T& MyVector<T>::back() {
    if (size == 0) {
        cerr << "Vector is empty" << std::endl;
        exit(1);
    }
    return elements[size - 1];
}

template <typename T>
void MyVector<T>::remove(T& x) {
    int index = -1;
    for (int i = 0; i < size; i++) {
        if (elements[i] == x) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        cerr << "Element not found" << std::endl;
        exit(1);
    }
    for (int i = index; i < size - 1; i++) {
        elements[i] = elements[i + 1];
    }
    size--;
}
template <typename T>
void MyVector<T>::pop_back() {
    if (size == 0) {
        cerr << "Vector is empty" << std::endl;
        exit(1);
    }
    size--;
}

template <typename T>
int MyVector<T>::getSize() const {
    return size;
}
