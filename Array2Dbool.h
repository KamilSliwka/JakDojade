#ifndef JAKDOJADE_ARRAY2DBOOL_H
#define JAKDOJADE_ARRAY2DBOOL_H

#include <iostream>
#include <cstring>

using namespace std;

class Array2Dbool {
public:
    bool** p;
    int w = 0;
    int h = 0;

    void SetBoolOnMap(int x, int y,bool t) {
        p[x][y]=t;

    }


    bool GetBoolOnMap(int x, int y) {
        return p[x][y];

    }

    void clear() {
        for (int i = 0; i < h; i++) {
            memset(p[i], false, w);
        }
    }

    Array2Dbool(int ww, int hh) {

        w = ww;
        h = hh;
        p = new bool* [h];
        for (int i = 0; i < h; i++) {
            p[i] = new bool[w];
            memset(p[i], false, w);
        }
    }


    ~Array2Dbool() {
        for (int i = 0; i < h; i++) {
            delete[] p[i];
        }
        delete[] p;
    }

};


#endif //JAKDOJADE_ARRAY2DBOOL_H
