#ifndef JAKDOJADE_HASHMAPC_H
#define JAKDOJADE_HASHMAPC_H

#include <iostream>

struct coordinate {
    int x;
    int y;
};


bool operator==(coordinate lhs, coordinate rhs) {
    return lhs.x == rhs.x && lhs.y == rhs.y;
}


struct Nodex {
    coordinate key;
    int value;
    Nodex* next;

    Nodex(coordinate key, int value) : key(key), value(value), next(nullptr) {}
};


class HashMapc {
private:
    static const int SIZE = 100000; // Rozmiar tablicy haszującej
    Nodex* map[SIZE]; // Tablica haszująca przechowująca wskaźniki na węzły

    // Funkcja haszująca, przekształcająca klucz na indeks w tablicy

    int hashFunction(coordinate key) {
        const int base = 61;
        int hashValue = 0;

        hashValue = (hashValue * base + key.x) % SIZE;
        hashValue = (hashValue * base + key.y) % SIZE;

        return hashValue;
    }

public:
    HashMapc() {
        for (int i = 0; i < SIZE; ++i) {
            map[i] = nullptr;
        }
    }

    void add(coordinate key, int value) {
        int index = hashFunction(key);
        Nodex* newNode = new Nodex(key, value);
        if (map[index] == nullptr) {
            map[index] = newNode;
        }
        else {
            Nodex* current = map[index];
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    int get(coordinate key) {
        int index = hashFunction(key);
        Nodex* current = map[index];
        while (current != nullptr) {
            if (current->key == key) {
                return current->value;
            }
            current = current->next;
        }
        return -1; // Wartość -1 oznacza, że klucz nie istnieje w mapie
    }

    void remove(coordinate key) {
        int index = hashFunction(key);
        Nodex* current = map[index];
        Nodex* prev = nullptr;
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


#endif //JAKDOJADE_HASHMAPC_H
