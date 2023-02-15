#include"include/PathFinding.h"

vector<Tile *> PathFinding::getPath(Tile *initialTile) {

    this->initialTile = initialTile;
    this->path.push_back(initialTile);

    Node initialNode = {
        false,
        calculateInitialCost(initialTile->getCoordinate()),
        calculateFinalCost(initialTile->getCoordinate()),
        calculateInitialCost(initialTile->getCoordinate()),
        gameMap->getTile(initialTile->getCoordinate())
    };

    // cout<< "InitialCost " << calculateInitialCost(initialTile->getCoordinate()) << endl;

    nodes.push_back(initialNode);

    Node finalNode = {
        false,
        calculateInitialCost(initialTile->destinationTile->getCoordinate()),
        calculateFinalCost(initialTile->destinationTile->getCoordinate()),
        calculateInitialCost(initialTile->destinationTile->getCoordinate()),
        gameMap->getTile(initialTile->destinationTile->getCoordinate())
    };

    // cout<< "FinalCost " << calculateFinalCost(initialTile->getCoordinate()) << endl;
 
    calculateNewCosts(initialNode);

    return path;
}

void PathFinding::calculateNewCosts(Node initialNode) {
    Coordinate coordinate = initialNode.tile->getCoordinate();
    
    Node lowerCostNode = {
        true,0,0,0,
        nullptr
    };

    getNodes(getNeighborCoordinates(coordinate));


    while(lowerCostNode.tile != initialNode.tile->destinationTile){
        lowerCostNode = getNodeWithLowestCost();
        getNodes(getNeighborCoordinates(this->lowestCostNode.tile->getCoordinate()));
    }
}

vector<Coordinate> PathFinding::getNeighborCoordinates(Coordinate coordinate) {
    vector<Coordinate> neighbors {};
    
    addCoordinate(neighbors, Coordinate(coordinate.x + 1, coordinate.y));
    addCoordinate(neighbors, Coordinate(coordinate.x + 1, coordinate.y + 1));
    addCoordinate(neighbors, Coordinate(coordinate.x, coordinate.y + 1));
    addCoordinate(neighbors, Coordinate(coordinate.x - 1, coordinate.y + 1));
    addCoordinate(neighbors, Coordinate(coordinate.x - 1, coordinate.y));
    addCoordinate(neighbors, Coordinate(coordinate.x - 1, coordinate.y - 1));
    addCoordinate(neighbors, Coordinate(coordinate.x, coordinate.y - 1));
    addCoordinate(neighbors, Coordinate(coordinate.x + 1, coordinate.y - 1));
    
    return neighbors;  
}

void PathFinding::addCoordinate(vector<Coordinate> &neighbors, Coordinate coordinate) {
    Tile*tile = gameMap->getTile(coordinate);

    if(!tile->blocked) {
        neighbors.push_back(coordinate);
    }

}



vector<Node> PathFinding::getNodes(vector<Coordinate> coordinates) {
    vector<Node> nodesToReturn;

    bool canPushBack = true;

    for(Coordinate coordinate : coordinates) {

        canPushBack = true;

        for(Node node: this->nodes) {
            if(node.tile->getCoordinate() == coordinate) {
                canPushBack = false;
            }
        }

        if(canPushBack) {
            nodes.push_back({
                true,
                calculateInitialCost(coordinate),
                calculateFinalCost(coordinate),
                calculateTotalCost(coordinate),
                gameMap->getTile(coordinate)
            });

            gameMap->getTile(coordinate)->setIsOpen();
        }
    }

    return nodesToReturn;
}

Node PathFinding::getNodeWithLowestCost() {
    Node lowestCostNode = {true, 0,0,0, nullptr};

    
  

    for(Node &node: this->nodes) {

        if(!node.open){
            continue;
        }

        if ((lowestCostNode.tile == nullptr) || (node.totalCost < lowestCostNode.totalCost) ) {
            lowestCostNode = node;
            node.open = false;
        }
    }

    lowestCostNode.tile->setIsClosed();
    this->lowestCostNode = lowestCostNode;
    this->path.push_back(lowestCostNode.tile);
    // cout << "lowestCostNode: (" << this->lowestCostNode.tile->getCoordinate().x <<","<< this->lowestCostNode.tile->getCoordinate().y << ")" << endl;

    return lowestCostNode;
}

PathFinding::PathFinding(Map *map) {
    this->gameMap = map;
}

double PathFinding::absoluteDistanceBetweenTwoPoints(Coordinate pointOne, Coordinate pointTwo){
    return sqrt( pow(pointTwo.x - pointOne.x, 2) + pow(pointTwo.y - pointOne.y, 2)) * 10;;
}

PathFinding::~PathFinding() {}

double PathFinding::calculateInitialCost(Coordinate coordinate) {
    Coordinate initailTileCoordinate = this->initialTile->getCoordinate();
   
    return absoluteDistanceBetweenTwoPoints(initailTileCoordinate, coordinate);
}

double PathFinding::calculateFinalCost(Coordinate coordinate) {
    Coordinate finalTileCoordinate = this->initialTile->destinationTile->getCoordinate();
   
    return absoluteDistanceBetweenTwoPoints(finalTileCoordinate, coordinate);
}

double PathFinding::calculateTotalCost(Coordinate coordinate) {
    Coordinate initailTileCoordinate = this->initialTile->getCoordinate();
    Coordinate finalTileCoordinate = this->initialTile->destinationTile->getCoordinate();
   
    return absoluteDistanceBetweenTwoPoints(finalTileCoordinate, coordinate) + absoluteDistanceBetweenTwoPoints(initailTileCoordinate, coordinate);    
}
