#ifndef JAKDOJADE_ARRAY2D_H
#define JAKDOJADE_ARRAY2D_H
#include <iostream>
#include <cstring>

using namespace std;

class Array2D {
    char** p;
    int w = 0;
    int h = 0;
public:
    char GetSignFromMap(int x, int y) {
        if (x < 0 || y < 0 || y >= w || x >= h) {
            return('.');
        }
        else {
            return p[x][y];
        }
    }
private:
    Array2D(int ww, int hh) {

        w = ww;
        h = hh;
        p = new char* [h];
        for (int i = 0; i < h; i++) {
            p[i] = new char[w];
            memset(p[i], '.', w);
        }
    }

    void Print() {
        for (int i = 0; i < h; i++) {

            for (int j = 0; j < w; j++) {
                cout << p[i][j];
            }
            cout << endl;
        }
    }


    ~Array2D() {
        for (int i = 0; i < h; i++) {
            delete[] p[i];
        }
        delete[] p;
    }

};


#endif //JAKDOJADE_ARRAY2D_H
