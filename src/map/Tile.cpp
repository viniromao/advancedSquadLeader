#include "include/Tile.h"

void Tile::initVariables() {
    creature = nullptr;
    destinationTile = nullptr;
    blocked = false;
    isVisible = false;
}

void Tile::initCreatureShape(Vector2f position) {}

void Tile::setPosition(Vector2f position) {
    this->position = position;
    this->center = Vector2f(position.x + tileSize/2, position.y + tileSize/2); 
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
    shape.setFillColor(Color(131,196,33,255));
    shape.setOutlineColor(Color::Black);
    shape.setOutlineThickness(1.f);
    shape.setSize(Vector2f(tileSize, tileSize));
    shape.setPosition(position);
    this->discretePosition = discretePosition;
}

void Tile::render(RenderTarget *target) {  
    target->draw(shape);

    if (creature != nullptr) {
        creature->render(target);
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
