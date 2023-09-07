#include <iostream>
#include "MyVector.hxx"
#include "structures.h"
#include "HashMap.h"
#include "HashMapc.h"
#include "PriorityQueue.hxx"

using namespace std;

void parse(MyString* buffor, MyString* source, MyString* destination, int* time) {
    *buffor = (*buffor).removeSpaces(*buffor);
    *source = (*buffor).substringUntil(' ');
    *destination = (*buffor).substringAfter(' ');
    MyString t = (*destination).substringAfter(' ');
    *time = t.toInt(t);
    *destination = (*destination).substringUntil(' ');
    *buffor = " ";
}

bool index(int h, int w, int x, int y) {
    if (x >= h) {
        return false;
    }
    if (x < 0) {
        return false;
    }
    if (y >= w) {
        return false;
    }
    if (y < 0) {
        return false;
    }

    return true;

}

MyString findName(char sign, Array2D* map, int xx, int yy, int w) {
    while (sign != '.' && sign != '#' && sign != '*' && yy > 0) {
        yy--;
        sign = map->p[xx][yy];


    }
    if (sign == '.' || sign == '#' || sign == '*') {
        yy++;
        sign = map->p[xx][yy];
    }

    MyString town;
    while (sign != '.' && sign != '#' && sign != '*' && yy < w) {

        town.append(sign);
        yy++;
        sign = map->p[xx][yy];

    }
    return town;
}

int main() {

    char sign;
    MyString width, high, buffor;
    MyVector<city>allCity;
    MyVector<coordinate>star;

    while (cin.get(sign)) {
        if (sign == '\n') {
            break;
        }
        buffor.append(sign);
    }
    buffor = buffor.removeSpaces(buffor);
    width = buffor.substringUntil(' ');
    high = buffor.substringAfter(' ');
    int h = high.toInt(high);
    int w = width.toInt(width);
    int j, i = 0;
    bool ifname = false;
    coordinate starPosition;
    cityName  nameOfCity;
    Array2D* map = new Array2D(w + 1, h);

    for (int i = 0; i < h; i++) {
        cin.getline(map->p[i], w + 1);
    }
    i = 0;
    j = 0;
    while (i < h) {
        sign = map->p[i][j];
        if (sign == '*') {
            starPosition.x = i;
            starPosition.y = j;
            star.push_back(starPosition);
        }
        j++;
        if (j == w) {
            j = 0;
            i++;
        }
    }
    int number = 0;
    cityName a;
    coordinate b;
    city c;
    int x, y;
    int r = star.getSize();

    for (int l = 0; l < r; l++) {
        b = star[l];
        x = b.x;
        y = b.y;
        bool flag = false;

        if (index(h, w, x + 1, y)) {
            sign = map->p[x + 1][y];
            if (sign != '.' && sign != '#' && sign != '*') {
                c.name = findName(sign, map, x + 1, y, w);
                c.number = number;
                c.position = b;
                allCity.push_back(c);
                flag = true;
            }
        }

        if (flag == false && index(h, w, x, y + 1)) {
            sign = map->p[x][y + 1];
            if (sign != '.' && sign != '#' && sign != '*') {
                c.name = findName(sign, map, x, y + 1, w);
                c.number = number;
                c.position = b;
                allCity.push_back(c);
                flag = true;
            }
        }
        if (flag == false && index(h, w, x + 1, y - 1)) {
            sign = map->p[x + 1][y - 1];
            if (sign != '.' && sign != '#' && sign != '*') {
                c.name = findName(sign, map, x + 1, y - 1, w);
                c.number = number;
                c.position = b;
                allCity.push_back(c);
                flag = true;

            }
        }
        if (flag == false && index(h, w, x, y - 1)) {
            sign = map->p[x][y - 1];
            if (sign != '.' && sign != '#' && sign != '*') {
                c.name = findName(sign, map, x, y - 1, w);
                c.number = number;
                c.position = b;
                allCity.push_back(c);
                flag = true;
            }
        }
        if (flag == false && index(h, w, x - 1, y)) {
            sign = map->p[x - 1][y];
            if (sign != '.' && sign != '#' && sign != '*') {
                c.name = findName(sign, map, x - 1, y, w);
                c.number = number;
                c.position = b;
                allCity.push_back(c);
                flag = true;
            }
        }
        if (flag == false && index(h, w, x + 1, y + 1)) {
            sign = map->p[x + 1][y + 1];
            if (sign != '.' && sign != '#' && sign != '*') {
                c.name = findName(sign, map, x + 1, y + 1, w);
                c.number = number;
                c.position = b;
                allCity.push_back(c);
                flag = true;

            }
        }
        if (flag == false && index(h, w, x - 1, y - 1)) {
            sign = map->p[x - 1][y - 1];
            if (sign != '.' && sign != '#' && sign != '*') {
                c.name = findName(sign, map, x - 1, y - 1, w);
                c.number = number;
                c.position = b;
                allCity.push_back(c);
                flag = true;
            }
        }
        if (flag == false && index(h, w, x - 1, y + 1)) {
            sign = map->p[x - 1][y + 1];
            if (sign != '.' && sign != '#' && sign != '*') {
                c.name = findName(sign, map, x - 1, y + 1, w);
                c.number = number;
                c.position = b;
                allCity.push_back(c);
                flag = true;
            }
        }
        flag = false;
        number++;
    }


    HashMap* mapOfCity = new HashMap;
    HashMapc* mapOfCoordinates = new HashMapc;
    Graph* g = new Graph(number);
    dijkstraCity* arrayCity = new dijkstraCity[number];
    MyString* Names = new MyString[number];
    int sizeOfarrayCity = number;
    for (int ii = 0; ii < sizeOfarrayCity; ii++) {
        c = allCity[ii];
        int u = c.number;
        Names[u] = c.name;
        mapOfCoordinates->add(c.position, c.number);
        mapOfCity->add(c.name, c.number);
        arrayCity[u].distanceFromSource = -1;
        arrayCity[u].n = u;
        arrayCity[u].source = -1;
        arrayCity[u].position = c.position;
    }

    Array2Dbool* visited = new Array2Dbool(w, h);

    for (int ii = 0; ii < sizeOfarrayCity; ii++) {
        timeBeetwenCity(map, arrayCity[ii], arrayCity, sizeOfarrayCity, g, visited, mapOfCoordinates);
        visited->clear();
    }
    delete mapOfCoordinates;
    delete visited;
    delete map;
    delete[] arrayCity;

    buffor = " ";
    while (cin.get(sign)) {
        if (sign == '\n') {
            break;
        }
        buffor.append(sign);
    }
    buffor = buffor.removeSpaces(buffor);
    int fly = buffor.toInt(buffor);
    if (fly != 0) {
        buffor = " ";
        MyString source;
        MyString destination;
        int time;
        while (sign = getchar()) {
            if (sign != '\n') {
                buffor.append(sign);
            }
            else {
                parse(&buffor, &source, &destination, &time);
                fly--;
                int n1;
                int n2;
                n1 = mapOfCity->get(source);
                n2 = mapOfCity->get(destination);
                g->addEdge(n1, n2, time);
                if (fly == 0) {
                    break;
                }
            }
        }
    }
    buffor = " ";
    while (cin.get(sign)) {
        if (sign == '\n') {
            break;
        }
        buffor.append(sign);
    }
    buffor = buffor.removeSpaces(buffor);
    int question = buffor.toInt(buffor);
    if (question != 0) {
        buffor = " ";
        MyString source;
        MyString destination;
        int road;
        while (cin.get(sign)) {
            if (sign != '\n') {
                buffor.append(sign);
            }
            else {
                parse(&buffor, &source, &destination, &road);
                question--;
                int n1;
                int n2;
                n1 = mapOfCity->get(source);
                n2 = mapOfCity->get(destination);
                if (road == 0) {
                    dijkstra(n1, n2, g, false, Names);
                }
                else {
                    dijkstra(n1, n2, g, true, Names);
                }
                if (question == 0) {
                    break;
                }
            }
        }
    }

    delete mapOfCity;
    delete g;
    delete[] Names;
    return 0;

}
