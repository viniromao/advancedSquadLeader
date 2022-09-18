#ifndef _PATH_H_
#define _PATH_H_

#include<vector>

#include"include/Tile.h"

using namespace std;

class Path {
private:
public:
    vector<Tile*> path;

    Path();
    virtual ~Path();
};

#endif