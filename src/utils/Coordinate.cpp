#include"include/Coordinate.h"

Coordinate::Coordinate(){}

Coordinate::Coordinate(int x, int y){
    this->x = x;
    this->y = y;
}

Coordinate::~Coordinate() {
    
}

void Coordinate::printCoordinate(char *identifier) {
    cout << "coordinate "<< identifier <<": (" << x <<","<< y << ")" << endl;
}