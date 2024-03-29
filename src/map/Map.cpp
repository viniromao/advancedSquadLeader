#include "include/Map.h"


void Map::initVariables() {
    int size = 20;

    this->map = initMap(size, size);
    this->size = Coordinate(size,size);
}

Vector2f Map::getTile(Tile **tileSelected, Vector2f position) {
    for(size_t i = 0; i < (size_t) map.size(); ++i){
        for(size_t j = 0; j < (size_t) map[i].size(); ++j) {
            Tile *tile = map[i][j];
            FloatRect bounds = tile->getShape().getGlobalBounds();
            if (position.x > bounds.left && position.x < bounds.left + bounds.width) {
                if (position.y > bounds.top && position.y < bounds.top + bounds.height) {
                   *tileSelected = tile;
                }   
            }
        }
    }
}

vector<vector<Tile *>> Map::initMap(int x, int y) {
    vector<vector<Tile *>> map;


    for(int i = 0; i<x ; i++){
        map.push_back(vector<Tile *>());
        for(int j = 0; j<y; j++){
            map[i].push_back(new Tile(Vector2f(i * Tile::totalTileSize, j * Tile::totalTileSize), Vector2i(i,j)));
            if (rand() % 100 < 10) {
                map[i][j]->setTree();
            }
        } 
    }

    return map;
}
    

Map::Map(ClickEventProducer *producer){
    this->producer = producer;
    initVariables();
}

Map::~Map() {
    map.clear();
}

void Map::render(RenderTarget *target) {
    for(size_t i = 0; i < map.size(); i++){
        for(size_t j = 0; j < map[i].size(); j++) {
            Tile *tile = map[i][j];
            tile->render(target);
        }
    }
}

void Map::renderCreatureHud(RenderTarget *target) {
    for(size_t i = 0; i < map.size(); i++){
        for(size_t j = 0; j < map[i].size(); j++) {
            Tile *tile = map[i][j];
            tile->renderCreatureHud(target);
        }
    }
}

void Map::renderTree(RenderTarget *target) {
    for(size_t i = 0; i < map.size(); i++){
        for(size_t j = 0; j < map[i].size(); j++) {
            Tile *tile = map[i][j];
            tile->renderTree(target);
        }
    }
}

void Map::renderDestinationShadows(RenderTarget *target) {
     for(size_t i = 0; i < map.size(); i++){
        for(size_t j = 0; j < map[i].size(); j++) {
            Tile *tile = map[i][j];
            tile->renderDestinationShadow(target);
        }
    }
}

void Map::renderShadows(RenderTarget *target) {
     for(size_t i = 0; i < map.size(); i++){
        for(size_t j = 0; j < map[i].size(); j++) {
            Tile *tile = map[i][j];
            tile->renderShadow(target);
        }
    }
}

Coordinate Map::clickEvent(Vector2f position) {

    cout << "ClickEvent: position(" << position.x << ", " << position.y << ")" << endl;
    Tile *tile = nullptr;
    
    producer->createMessage("lambadadee");

    getTile(&tile, position);

    return tile->getCoordinate();
}

void Map::selectTileWithCreature(Vector2f position, Tile **tileToBeSelected) {

    Tile *tile = nullptr;
    getTile(&tile, position);

    if(tile != nullptr && tile->creature != nullptr) {
        *tileToBeSelected = tile;
        tile->setSelected();
        return;
    }  

    *tileToBeSelected = nullptr;
}

void Map::setCreatureDestination(Vector2f position, Tile *originTile) {

    if(originTile->creature == nullptr) {
        return;
    }

    for(size_t i = 0; i < map.size(); i++){
        for(size_t j = 0; j < map[i].size(); j++) {
            Tile *destinationTile = map[i][j];
            FloatRect bounds = destinationTile->getShape().getGlobalBounds();
            if (position.x > bounds.left && position.x < bounds.left + bounds.width) {
                if (position.y > bounds.top && position.y < bounds.top + bounds.height) {
                    originTile->destinationTile = destinationTile;
                    originTile->creature->initDestinationShape(destinationTile->center);
                }   
            }
        }
    }

}

bool Map::deploySoldierToTile(Vector2f position, ArmySetup &armySetup, Army &army) {
    cout << "ClickEvent: position(" << position.x << ", " << position.y << ")" << endl;

    Tile *tile = nullptr;
    
    this->getTile(&tile, position);

    if (tile->getCoordinate().x < army.deployRegion.begin.x || tile->getCoordinate().x > army.deployRegion.end.x ||
        tile->getCoordinate().y < army.deployRegion.begin.y || tile->getCoordinate().y > army.deployRegion.end.y) {
        cout<<"Soldier deploy out of deploy bounds"<<endl;
        return false;
    }

    if(tile != nullptr && tile->creature == nullptr) {
        tile->deploySoldier(armySetup.getCurrentSoldierToDeploy());
        army.soldiers.push_back(armySetup.currentSoldierToDeploy);
        armySetup.getNextSoldierToDeploy();
    }  

    return !armySetup.haveSoldiersToDeploy();
}

bool Map::deploySoldierToTile(Coordinate position, ArmySetup &armySetup, Army &army) { 
    if (position.x < army.deployRegion.begin.x || position.x > army.deployRegion.end.x ||
        position.y < army.deployRegion.begin.y || position.y > army.deployRegion.end.y) {
        cout<<"Soldier deploy out of deploy bounds"<<endl;
        return false;
    }

    Tile *tile = this->getTile(position);

    if(tile != nullptr && tile->creature == nullptr) {
        tile->deploySoldier(armySetup.getCurrentSoldierToDeploy());
        army.soldiers.push_back(armySetup.currentSoldierToDeploy);
        armySetup.getNextSoldierToDeploy();
    }  

    return !armySetup.haveSoldiersToDeploy();
}

void Map::castShadowOnTile(Vector2f position, Tile *tileSelected) {

    Tile *tile = nullptr;

    getTile(&tile, position);

    
    if(tile != nullptr) {
        tile->castShadow(tileSelected->creature);
    }  
}

void Map::clearShadows() {
      for(size_t i = 0; i < map.size(); i++){
        for(size_t j = 0; j < map[i].size(); j++) {
            Tile *tile = map[i][j];
            tile->clearShadow();
        }
    }
}

void Map::setPath(vector<Tile *> path) {
    Tile * initialTile = path[0];

    for (auto i = 0; i < paths.size(); i++) {
        if(paths[i][0] == initialTile) {
            paths.erase(paths.begin() + i);
        }
    }
    
    paths.push_back(path);
}

void Map::renderPaths(RenderTarget *target) {
    Vertex currentCenter;
    Vertex nextCenter;

    for (int i = 0; i < paths.size(); i++) {
        for(int j = 0; j < paths[i].size(); j++) {
            if(j + 1 < paths[i].size()) {
                currentCenter = Vertex(Vector2f(paths[i][j]->center));
                nextCenter = Vertex(Vector2f(paths[i][j+1]->center));
                
                Vertex line[] = {currentCenter, nextCenter};
                target->draw(line, 2, Lines);
            }

        }
    }
}

void Map::renderDeployRegions(RenderTarget *target, DeployRegion deployRegion) {
    Tile* beginTile = this->getTile(deployRegion.begin);
    Tile* endTile = this->getTile(deployRegion.end);

    RectangleShape rectangle(sf::Vector2f(endTile->bottomRightCorner + Vector2f(endTile->tileSize, endTile->tileSize) - beginTile->bottomRightCorner));
    rectangle.setOutlineColor(Color(255,0,0,255));
    rectangle.setOutlineThickness(2.0);
    rectangle.setFillColor(Color(0,0,0,0));
    rectangle.setPosition(Vector2f(beginTile->upperLeftCorner));
   
    target->draw(rectangle);
}

bool Map::makeOneStepMovementTroops() {
    bool hasMovedTroops = false;

    for (int i = 0; i < paths.size(); i++) {
        for(int j = 0; j < paths[i].size() - 1; j++) {
            if (paths[i][j + 1] != nullptr) {
                hasMovedTroops = true;

                Tile *tile = paths[i][j];
                Tile *nextTile = paths[i][j + 1];   

                nextTile->deploySoldier(tile->creature);
                tile->creature = nullptr;
                paths[i].erase(paths[i].begin());
                break;
            }
        }
    }

    return hasMovedTroops;
}

void Map::setFogOfWar(Army *army) {
    for(Creature *creature : army->soldiers) {
        unsigned sight = creature->sight;
        Vector2i discretePosition = creature->discreteActualTilePosition;

        for(size_t i = 0; i < (size_t) map.size(); ++i){
            for(size_t j = 0; j < (size_t) map[i].size(); ++j) {
                if(map[i][j]->fogOfWarState == VISIBLE){
                    map[i][j]->setIsFaded();
                }
                
            }
        }
    
        

        for(int i = discretePosition.x - sight; i <= discretePosition.x + sight ; i++){
            for(int j = discretePosition.y - sight; j <= discretePosition.y + sight ; j++) {
                if(i > -1 && j > -1 && i < this->size.x && j < this->size.y){

                    map[i][j]->setIsFaded();
                    if(!map[i][j]->isBlocked()) {
                        map[i][j]->setIsVisible(); 
                    }
                }
            }
        }     
    }
}

Tile *Map::getTile(Coordinate tileCoordinate) {
    return map[tileCoordinate.x][tileCoordinate.y];
}





