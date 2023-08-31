#ifndef JAKDOJADE_MYVECTOR_H
#define JAKDOJADE_MYVECTOR_H

template <typename T>
class MyVector {
private:
    T* elements;
    int capacity;
    int size;

public:

    MyVector();

    MyVector(int n, T val);

    MyVector(const MyVector& other);

    ~MyVector();

    void push_back(const T& x);

    T& operator[](int index);

    T& back();

    void remove(T& x);

    void pop_back();

    int getSize() const;
};


#endif //JAKDOJADE_MYVECTOR_H
