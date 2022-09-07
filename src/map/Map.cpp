#include "include/Map.h"


void Map::initVariables() {
    map = initMap(10, 10);
}

void Map::getTile(Tile **tileSelected, Vector2f position) {
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

    if(tile != nullptr) {
        tile->setDeadPixel();
        cout << "Tile painted!" << endl;
    } 
}

void Map::selectTileWithCreature(Vector2f position, Tile **tileToBeSelected) {

    cout << "ClickEvent: position(" << position.x << ", " << position.y << ")" << endl;

    Tile *tile = nullptr;

    getTile(&tile, position);

    cout << tile << endl;

    if(tile != nullptr) {
        cout << "CreatureSelection";
        *tileToBeSelected = tile;
        return;
    }  

    *tileToBeSelected = nullptr;
}

void Map::deploySoldier(Vector2f position, Creature *creature) {

    cout << "ClickEvent: position(" << position.x << ", " << position.y << ")" << endl;
    Tile *tile = nullptr;
    
    getTile(&tile, position);

    if(tile != nullptr) {
        tile->deploySoldier(creature);
        cout << "Soldier deployed" << endl;
    }  
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






