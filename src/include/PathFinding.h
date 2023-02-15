#ifndef _PATH_FINDING_H_
#define _PATH_FINDING_H_

#include <limits.h>
#include <stdio.h>
#include <math.h>
#include "include/Tile.h"
#include "include/Coordinate.h"
#include "include/Map.h"

using namespace sf;

struct Node {   
  bool open = true;
  unsigned int initialCost = 0;
  unsigned int finalCost = 0;
  unsigned int totalCost = 0;    
  Tile *tile = nullptr;
};


class PathFinding {
  private:
    Map *gameMap = nullptr;
    Node lowestCostNode;
    Tile *initialTile;
    vector<Tile *> path;

    void initNodes();
    void calculateNewCosts(Node node);
    vector<Coordinate> getNeighborCoordinates(Coordinate coordinate);
    vector<Node> getNodes(vector<Coordinate> coordinates);
    double calculateInitialCost(Coordinate coordinate);
    double calculateFinalCost(Coordinate coordinate);
    double calculateTotalCost(Coordinate coordinate);
    Node getNodeWithLowestCost();
    double absoluteDistanceBetweenTwoPoints(Coordinate pointOne, Coordinate pointTwo);
    void addCoordinate(vector<Coordinate> &neighbors, Coordinate coordinate);

  public:

    vector<Node> nodes;

    PathFinding();
    PathFinding(Map *map);
    virtual ~PathFinding();

    vector<Tile *> getPath(Tile *initialTile);
};

#endif