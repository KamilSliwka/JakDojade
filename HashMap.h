#ifndef JAKDOJADE_HASHMAP_H
#define JAKDOJADE_HASHMAP_H

#include <iostream>
#include "MyString.h"

struct Node {
    MyString key;
    int value;
    Node* next;

    Node(MyString key, int value) : key(key), value(value), next(nullptr) {}
};


class HashMap {
private:
    static const int SIZE = 100000; // Rozmiar tablicy haszującej
    Node* map[SIZE]; // Tablica haszująca przechowująca wskaźniki na węzły

    // Funkcja haszująca, przekształcająca klucz na indeks w tablicy
    int hashFunction(MyString key) {


        const int base = 61; // wartość stałej baza
        int hashValue = 0;
        int size = key.size();

        for (int i = 0; i < size; i++) {
            char c = key[i];
            hashValue = (hashValue * base + c) % SIZE; // obliczamy wartość nowego hasha dla kolejnego znaku
        }

        return hashValue;


    }



public:
    HashMap() {
        for (int i = 0; i < SIZE; ++i) {
            map[i] = nullptr;
        }
    }

    void add(MyString key, int value) {
        int index = hashFunction(key);
        Node* newNode = new Node(key, value);
        if (map[index] == nullptr) {
            map[index] = newNode;
        }
        else {
            Node* current = map[index];
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    int get(MyString key) {
        int index = hashFunction(key);
        Node* current = map[index];
        while (current != nullptr) {
            if (current->key == key) {
                return current->value;
            }
            current = current->next;
        }
        return -1; // Wartość -1 oznacza, że klucz nie istnieje w mapie
    }

    void remove(MyString key) {
        int index = hashFunction(key);
        Node* current = map[index];
        Node* prev = nullptr;
        while (current != nullptr) {
            if (current->key == key) {
                if (prev == nullptr) {
                    map[index] = current->next;
                }
                else {
                    prev->next = current->next;
                }
                delete current;
                return;
            }
            prev = current;
            current = current->next;
        }
    }
};



#endif //JAKDOJADE_HASHMAP_H
