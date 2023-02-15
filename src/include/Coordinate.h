#ifndef _COORDINATE_H_
#define _COORDINATE_H_

#include <iostream>
using namespace std;

class Coordinate {
    public:
        int x;
        int y;

        bool operator == (Coordinate const &obj) {
            if(obj.x == this->x && obj.y == this->y) {
                return true;
            }

            return false;
        }

        Coordinate();
        Coordinate(int x, int y);
        virtual ~Coordinate();

        void printCoordinate(char *identifier);
};

#endif