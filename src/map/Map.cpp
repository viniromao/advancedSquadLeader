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
            map[i].push_back(new Tile(Vector2f(i * Tile::totalTileSize, j * Tile::totalTileSize), Vector2i(i,j)));
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

vector<Tile *> Map::getPath(Tile *initialTile) {
    vector<Tile *> path {};

    if (initialTile == nullptr) {
        return path;
    }

    Tile *finalTile = initialTile->destinationTile; 

    if(finalTile == nullptr || initialTile->creature == nullptr) {
        return path;
    }

    Vector2i initialPosition = initialTile->discretePosition;
    Vector2i finalPosition = finalTile->discretePosition;
    Vector2i actualPosition = initialTile->discretePosition;

    path.push_back(initialTile);

        // cout <<"ACTUAL POSITION: ("<<actualPosition.x<<","<<actualPosition.y<<")"<< endl;
        // cout <<"FINal POSITION: ("<<finalPosition.x<<","<<finalPosition.y<<")"<< endl;


    while((actualPosition.x != finalPosition.x) || (actualPosition.y != finalPosition.y)) {
        if(actualPosition.x < finalPosition.x ) {  
            if(!map[actualPosition.x + 1][actualPosition.y]->blocked) {
                // path.push_back(map[actualPosition.x + 1][actualPosition.y]);
                actualPosition.x++; 
            }
        }

        if(actualPosition.x > finalPosition.x ) {  
            if (actualPosition.x != 0) {
                if(!map[actualPosition.x - 1][actualPosition.y]->blocked) {
                    // path.push_back(map[actualPosition.x - 1][actualPosition.y]);
                    actualPosition.x--; 
                }
            }
        }

         if(actualPosition.y < finalPosition.y) {   
            if(!map[actualPosition.x][actualPosition.y + 1]->blocked) {
                // path.push_back(map[actualPosition.x][actualPosition.y + 1]);
                actualPosition.y++; 
            }
        } 
        
        if(actualPosition.y > finalPosition.y) {  
            if (actualPosition.y != 0) {
                if(!map[actualPosition.x][actualPosition.y - 1]->blocked) {
                    // path.push_back(map[actualPosition.x][actualPosition.y - 1]);
                    actualPosition.y--; 
                }
            } 
        }

        path.push_back(map[actualPosition.x][actualPosition.y]);

    }

    for (Tile * tile: path)
       cout<<tile->discretePosition.x<<" "<<tile->discretePosition.y<< endl;

        cout <<"THE END"<< endl;

    for (auto i = 0; i < paths.size(); i++) {
        if(paths[i][0] == initialTile) {
            paths.erase(paths.begin() + i);
        }
    }
    
        paths.push_back(path);

    return path;

}

void Map::renderPaths(RenderTarget *target) {
    // for (auto path: paths) {
    //     cout<<endl;

    //     for (auto tile: path)
    //         cout<<"("<<tile->discretePosition.x<<" "<<tile->discretePosition.y<<") ";
    // }

    

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

void Map::makeOneStepMovementTroops() {
    cout<<"function called"<< endl;
    for (int i = 0; i < paths.size(); i++) {
        for(int j = 0; j < paths[i].size() - 1; j++) {
            if (paths[i][j + 1] != nullptr) {
                Tile *tile = paths[i][j];
                Tile *nextTile = paths[i][j + 1];   

                nextTile->deploySoldier(tile->creature);
                tile->creature = nullptr;
                paths[i].erase(paths[i].begin());
                break;
            }
        }
    }
}





