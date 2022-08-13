#include "Map.h"


void Map::initVariables() {
    map = initMap(15, 15);
}

vector<vector<Tile>> Map::initMap(int x, int y) {
    vector<vector<Tile>> map;


    for(int i = 0; i<x ; i++){
         map.push_back(vector<Tile>(y, Tile()));
    }

    return map;
}
    

Map::Map(){
    initVariables();
}

Map::~Map() {
    
}

void Map::render(RenderTarget *target) {
    for(size_t i = 0; i < map.size(); i++){
        for(size_t j = 0; j < map[i].size(); j++) {
            Tile tile = map[i][j];
            tile.render(target, Vector2f(tile.getTileSize() * i, tile.getTileSize() * j));
        }
    }
}

