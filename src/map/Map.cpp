#include "include/Map.h"


void Map::initVariables() {
    map = initMap(10, 10);
}

Vector2f Map::getTile(Tile **tileSelected, Vector2f position) {
    for(size_t i = 0; i < map.size(); i++){
        for(size_t j = 0; j < map[i].size(); j++) {
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
            map[i].push_back(new Tile(Vector2f(i * Tile::totalTileSize, j * Tile::totalTileSize)));
        } 
    }

    return map;
}
    

Map::Map(){
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

void Map::clickEvent(Vector2f position) {

    cout << "ClickEvent: position(" << position.x << ", " << position.y << ")" << endl;
    Tile *tile = nullptr;

    getTile(&tile, position);

    if(tile != nullptr && tile->creature != nullptr) {
    //     tile->setSelected();
    //     cout << "Tile painted!" << endl;
    } 
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

void Map::setCreatureDestination(Vector2f position, Tile **destinationTile) {

    Tile *creatureVerifier = *destinationTile;

    if(creatureVerifier->creature == nullptr) {
        return;
    }

    Tile *tile = nullptr;
    getTile(&tile, position);

    if(tile != nullptr) {
        tile->destinationTile = *destinationTile;
        tile->destinationTile->creature->initDestinationShape(tile->center);
    }  
}

bool Map::deploySoldierToTile(Vector2f position, ArmySetup &armySetup) {

    cout << "ClickEvent: position(" << position.x << ", " << position.y << ")" << endl;
    Tile *tile = nullptr;
    
    getTile(&tile, position);

    if(tile != nullptr && tile->creature == nullptr) {
        tile->deploySoldier(armySetup.getCurrentSoldierToDeploy());
        armySetup.getNextSoldierToDeploy();
        cout << "Soldier deployed" << endl;
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






