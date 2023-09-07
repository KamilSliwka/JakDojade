#ifndef JAKDOJADE_STRUCTURES_H
#define JAKDOJADE_STRUCTURES_H

#include <iostream>
#include "MyVector.h"
#include "MyString.h"
#include "Graph.h"
#include "PriorityQueue.h"
#include "array2D.h"
#include "Queue.h"
#include "HashMapc.h"


using namespace std;

struct city {
    MyString name;
    coordinate position;
    int number;
};

struct cityName {
    MyString name;
    coordinate firstL;
    coordinate lastL;
};

struct dijkstraCity {
    int n;
    int source;
    coordinate position;
    int distanceFromSource;

};


bool operator==(dijkstraCity lhs, dijkstraCity rhs) {
    return (lhs.n == rhs.n &&
            lhs.source == rhs.source &&
            lhs.position.x == rhs.position.x &&
            lhs.position.y == rhs.position.y &&
            lhs.distanceFromSource == rhs.distanceFromSource);
}

bool operator>(dijkstraCity a, dijkstraCity b) {
    return a.distanceFromSource < b.distanceFromSource;
}

bool operator<(dijkstraCity a, dijkstraCity b) {
    return a.distanceFromSource > b.distanceFromSource;
}





#endif //JAKDOJADE_STRUCTURES_H
