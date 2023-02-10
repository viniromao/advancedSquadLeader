#ifndef _PATH_FINDING_H_
#define _PATH_FINDING_H_


#include <limits.h>
#include <stdio.h>
#include"include/Map.h"
#include"include/Tile.h"
#include"Coordinate.h"

using namespace sf;

class PathFinding {
private:
    
    struct Node {   
      unsigned int gCost = 0;
      unsigned int hCost = 0;
      unsigned int fCost = 0;    
      Tile *tile;
    };

    void initNodes(Map *map);
    void calculateNewCosts(Node node);
public:
    vector<Node> nodes;

    PathFinding();
    virtual ~PathFinding();

    vector<Coordinate> getPath(Coordinate from, Coordinate to, Map &map);
};

#endif