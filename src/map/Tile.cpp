#include "include/Tile.h"

void Tile::initVariables() {
    creature = nullptr;
    destinationTile = nullptr;
    blocked = false;
    this->fogOfWarState = SHADOWED;
        
    int treeNumber = rand() % 10;

    if (!grassTexture.loadFromFile("../assets/sprites/grass.png"))
            std::cout << "sprite not loaded";   

    switch (treeNumber) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
           if (!texture.loadFromFile("../assets/sprites/tree1.png"))
                std::cout << "sprite not loaded";   
            break;
        case 5:
        case 6:
        case 7:
        case 8:
           if (!texture.loadFromFile("../assets/sprites/tree3.png")) 
            std::cout << "sprite not loaded";   
            break;

        case 9:
            if (!texture.loadFromFile("../assets/sprites/tree2.png"))
                std::cout << "sprite not loaded";   
            break;
        
        default:
            if (!texture.loadFromFile("../assets/sprites/tree4.png"))
                std::cout << "sprite not loaded"; 
            
    }
}

void Tile::initCreatureShape(Vector2f position) {}

void Tile::setPosition(Vector2f position) {
    this->position = position;
    this->center = Vector2f(position.x + tileSize/2, position.y + tileSize/2);

    this->upperLeftCorner = Vector2f(position.x, position.y); 
    this->upperRightCorner = Vector2f(position.x + tileSize, position.y); 
    this->bottomRightCorner = Vector2f(position.x + tileSize, position.y + tileSize); 
    this->bottomLeftCorner = Vector2f(position.x , position.y + tileSize); 
}

Tile::Tile(Vector2f position, Vector2i discretePosition){
    initVariables();
    initTileShape(position, discretePosition);
    setPosition(position);
}

Tile::~Tile() {
    delete creature;
}

void Tile::initTileShape(Vector2f position, Vector2i discretePosition) {
    shape.setFillColor(Color(4,45,9,255));
    shape.setOutlineColor(Color::Black);
    shape.setOutlineThickness(0.5f);
    shape.setSize(Vector2f(tileSize, tileSize));
    shape.setPosition(position);
    shape.setTexture(&grassTexture);


    float treeSize = tileSize * 1.5;

    treeShape.setSize(Vector2f(treeSize, treeSize * 2));
    treeShape.setPosition(Vector2f(position.x - (treeSize - tileSize)/2, position.y - treeSize * 1.3));
    treeShape.setTexture(&texture);

    this->discretePosition = discretePosition;
}

void Tile::render(RenderTarget *target) {  
    target->draw(shape);

    if (creature != nullptr && this->fogOfWarState == VISIBLE) {
        creature->render(target);
    } 
}

void Tile::renderTree(RenderTarget *target) {
    if(this->hasTree) {
        target->draw(treeShape);
    }
}

void Tile::renderCreatureHud(RenderTarget *target) {  
    if (creature != nullptr && this->fogOfWarState == VISIBLE) {
        creature->renderHud(target);
    } 
}

void Tile::renderDestinationShadow(RenderTarget *target) {  
    if (creature != nullptr) {
        creature->renderDestinationShadow(target);
    } 
}

void Tile::renderShadow(RenderTarget *target) {  
    if (creature != nullptr) {
        creature->renderShadow(target);
    } 
}

float Tile::getTileSize() {
    return shape.getGlobalBounds().width;
}

Coordinate Tile::getCoordinate() {
    Coordinate coordinate = {this->discretePosition.x, this->discretePosition.y};
    return coordinate;
}

void Tile::setSelected() {
    shape.setFillColor(Color::Red);
}

void Tile::removeSelectedRender() {
    shape.setFillColor(Color(131,196,33,255));
}

void Tile::deploySoldier(Creature *creature) {
    this->creature = creature;
    this->creature->setPosition(Vector2f(this->position.x + this->tileSize/2, this->position.y + this->tileSize/2));
    this->creature->discreteActualTilePosition = Vector2i(this->discretePosition);
}

RectangleShape Tile::getShape() {
    return shape;
}

void Tile::castShadow(Creature *creature) {
    if(creature == nullptr) {
        return;
    }

    creature->initShadowShape(this->center);
}

void Tile::clearShadow() {
    if(this->creature == nullptr) {
        return;
    }

    this->creature->clearShadow();
}

void Tile::setIsFaded() {
    this->fogOfWarState = FADED;
    shape.setFillColor(Color(75,138,39,255)); 
}


void Tile::setIsVisible(bool visible) {
    this->fogOfWarState = VISIBLE;
    shape.setFillColor(Color(131,196,33,255));
}

void Tile::setIsBlocked(bool blocked) {
    this->blocked = true;
}

void Tile::setIsClosed() {
     if(this->blocked) {
        return;
    }
    // shape.setFillColor(Color(0,0,0,255));
}

void Tile::setIsOpen(){
    if(this->blocked) {
        return;
    }
    // shape.setFillColor(Color(255,255,255,255));
}

bool Tile::isBlocked() {
    return blocked;
}

void Tile::setTree() {
    setIsBlocked(true);
    this->hasTree = true;
    shape.setFillColor(Color(0,249,16,255));
}
