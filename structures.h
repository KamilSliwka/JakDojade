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

void dijkstra(int startVertex, int endVertex, Graph* g,bool question, MyString* Names) {

    Queue pq;

    MyVector<int> distances(g->GetnumVertices(), INT_MAX);
    MyVector<int> parent(g->GetnumVertices(), -1);
    MyVector<bool> visited(g->GetnumVertices(), false);
    Vertex w;
    distances[startVertex] = 0;
    w.distanceFromStart = 0;
    w.vertexNumber = startVertex;
    pq.push(w);

    while (!pq.empty()) {
        int u = pq.top().vertexNumber;
        pq.pop();

        if (visited[u]) {
            continue;
        }

        visited[u] = true;

        GraphNode* temp = g->adjacencyList[u];
        while (temp != nullptr) {
            int v = temp->destination;
            int cost = temp->cost;

            if (distances[u] != INT_MAX && distances[u] + cost < distances[v]) {
                distances[v] = distances[u] + cost;
                parent[v] = u;
                Vertex tmp;
                tmp.distanceFromStart = distances[v];
                tmp.vertexNumber = v;
                pq.push(tmp);
            }

            temp = temp->next;
        }
    }
    if (startVertex== endVertex) {
        cout << 0 << endl;
    }
    else if (parent[endVertex] == -1) {
        cout << "There is no path from vertex " << startVertex << " to vertex " << endVertex << endl;
    }
    else if(question==true) {
        cout<< distances[endVertex]<<" ";
        int vertex = endVertex;
        MyVector<int> path;
        path.push_back(vertex);
        while (vertex != startVertex) {
            vertex = parent[vertex];
            path.push_back(vertex);
        }
        for (int i = path.getSize() - 3; i >= 0; i--) {
            cout << Names[path[i+1]];
            if (i != 0) {
                cout << " ";
            }
        }
        cout << endl;

    }
    else {
        cout << distances[endVertex] << endl;;
    }
}





#endif //JAKDOJADE_STRUCTURES_H
