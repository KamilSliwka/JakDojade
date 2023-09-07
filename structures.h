#ifndef JAKDOJADE_STRUCTURES_H
#define JAKDOJADE_STRUCTURES_H

#include <iostream>
#include "MyVector.h"
#include "MyString.h"
#include "Graph.h"
#include "PriorityQueue.h"
#include "Array2D.h"
#include "Array2Dbool.h"
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

int GetNumberOfCity( coordinate c,HashMapc*p) {
    return p->get(c);
}


void timeBeetwenCity(Array2D *map, dijkstraCity city, dijkstraCity* arrayCity, int sizeOfarrayCity, Graph* p, Array2Dbool* wsk,HashMapc* h) {
    coordinate position = city.position;

    PriorityQueue<dijkstraCity>queue;
    dijkstraCity tmp;
    dijkstraCity main;
    tmp.n = -1;
    tmp.source = city.n;
    tmp.distanceFromSource = 0;
    tmp.position = city.position;
    int road = 0;
    int distance = 0;
    main = tmp;
    queue.push(main);
    while (!queue.empty()) {
        main = queue.pop();
        position = main.position;
        distance = main.distanceFromSource;
        road = main.n;
        if (road != 2&&map->GetSignFromMap(position.x - 1, position.y) == '#'&& wsk->GetBoolOnMap(position.x - 1, position.y)==false ) {

            tmp.n = 1;
            tmp.distanceFromSource=distance+1;
            tmp.position.x = position.x - 1;
            tmp.position.y = position.y;
            queue.push(tmp);
            wsk->SetBoolOnMap(tmp.position.x, tmp.position.y, true);


        }
        if (road != 1&&map->GetSignFromMap(position.x + 1, position.y) == '#' && wsk->GetBoolOnMap(position.x + 1, position.y) == false ) {

            tmp.n = 2;
            tmp.distanceFromSource = distance + 1;
            tmp.position.x = position.x+1;
            tmp.position.y = position.y;
            queue.push(tmp);
            wsk->SetBoolOnMap(tmp.position.x, tmp.position.y, true);
        }
        if (road != 3&&map->GetSignFromMap(position.x, position.y - 1) == '#'&& wsk->GetBoolOnMap(position.x , position.y - 1) == false ) {
            tmp.n = 4;
            tmp.distanceFromSource = distance + 1;
            tmp.position.x = position.x;
            tmp.position.y = position.y-1;
            queue.push(tmp);
            wsk->SetBoolOnMap(tmp.position.x, tmp.position.y, true);
        }

        if (road != 4&&map->GetSignFromMap(position.x, position.y + 1) == '#' && wsk->GetBoolOnMap(position.x, position.y + 1) == false ) {
            tmp.n = 3;
            tmp.distanceFromSource = distance + 1;
            tmp.position.x = position.x;
            tmp.position.y = position.y+1;
            queue.push(tmp);
            wsk->SetBoolOnMap(tmp.position.x, tmp.position.y, true);
        }



        if (road != 2&&map->GetSignFromMap(position.x - 1, position.y) == '*' ) {


            tmp.distanceFromSource = distance + 1;
            tmp.position.x = position.x-1;
            tmp.position.y = position.y;
            tmp.n = GetNumberOfCity(tmp.position,h);
            p->addEdge(tmp.source, tmp.n, tmp.distanceFromSource);

        }
        if (road != 1&&map->GetSignFromMap(position.x + 1, position.y) == '*' ) {

            tmp.distanceFromSource = distance + 1;
            tmp.position.x = position.x+1;
            tmp.position.y = position.y;
            tmp.n = GetNumberOfCity(tmp.position,h);
            p->addEdge(tmp.source, tmp.n, tmp.distanceFromSource);


        }
        if (road != 3&&map->GetSignFromMap(position.x, position.y - 1) == '*' ) {

            tmp.distanceFromSource = distance + 1;
            tmp.position.x = position.x;
            tmp.position.y = position.y-1;
            tmp.n = GetNumberOfCity(tmp.position,h);
            p->addEdge(tmp.source, tmp.n, tmp.distanceFromSource);

        }
        if (road != 4&&map->GetSignFromMap(position.x, position.y + 1) == '*' ) {

            tmp.distanceFromSource = distance + 1;
            tmp.position.x = position.x;
            tmp.position.y = position.y+1;
            tmp.n = GetNumberOfCity(tmp.position,h);
            p->addEdge(tmp.source, tmp.n, tmp.distanceFromSource);
        }
    }
}





#endif //JAKDOJADE_STRUCTURES_H
