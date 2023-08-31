#ifndef JAKDOJADE_GRAPH_H
#define JAKDOJADE_GRAPH_H
#include <iostream>

using namespace std;

struct Vertex {
    int vertexNumber;
    int distanceFromStart;
};

bool operator >(Vertex v1, Vertex v2) {
    return !(v1.distanceFromStart > v2.distanceFromStart);
}

bool operator <(Vertex v1, Vertex v2) {
    return v1.distanceFromStart > v2.distanceFromStart;
}


struct GraphNode {
    int source;
    int destination;
    int cost;
    GraphNode* next;

    GraphNode(int source, int destination, int cost) {
        this->source = source;
        this->destination = destination;
        this->cost = cost;
        next = nullptr;
    }
};

struct Graph {
    int numVertices;
    GraphNode** adjacencyList;


    Graph(int numVertices) {
        this->numVertices = numVertices;
        adjacencyList = new GraphNode * [numVertices];
        for (int i = 0; i < numVertices; i++) {
            adjacencyList[i] = nullptr;
        }
    }

    void addEdge(int source, int destination, int cost) {
        GraphNode* newNode = new GraphNode(source, destination, cost);
        newNode->next = adjacencyList[source];
        adjacencyList[source] = newNode;
    }

    int GetnumVertices() {
        return numVertices;
    }

    void printGraph() {
        for (int i = 0; i < numVertices; i++) {
            cout << "Vertex " << i << ": ";
            GraphNode* temp = adjacencyList[i];
            while (temp != nullptr) {
                cout << temp->destination << "(" << temp->cost << ")" << " -> ";
                temp = temp->next;
            }
            cout << "NULL" << endl;
        }
    }
};

#endif //JAKDOJADE_GRAPH_H
