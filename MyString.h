#ifndef JAKDOJADE_MYSTRING_H
#define JAKDOJADE_MYSTRING_H

#include <iostream>
using namespace std;

class MyString {
private:
    char* data;
    int length;

public:
    MyString();

    MyString(const MyString& other);

    ~MyString();

    MyString& operator=(const MyString& other);

    char& operator[](int index);

    const char& operator[](int index) const;

    bool operator==(const MyString& other);

    MyString(const char* str);

    int size() const;

    int toInt(const MyString &str);

    MyString removeSpaces(const MyString &str);

    MyString substringUntil(char c);

    MyString substringAfter(char c);

    int find(char c);

    void append(char c);

    MyString deleteLeadingSpaces();

    MyString deletesEnter();

    MyString deletesSpace();

    bool equals(MyString a, MyString b);

    friend ostream& operator<<(ostream& os, const MyString& str);
};


#endif //JAKDOJADE_MYSTRING_H
