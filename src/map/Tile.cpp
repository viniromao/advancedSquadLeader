#include "include/Tile.h"

void Tile::initVariables() {
    creature = nullptr;
}

void Tile::initCreatureShape(Vector2f position) {
    // creature = new Auropodas(position);
}

Tile::Tile(Vector2f position){
    initVariables();
    initTileShape(position);
    this->position = position;
    // initCreatureShape(position);
}

Tile::~Tile() {
    delete creature;
}

void Tile::initTileShape(Vector2f position) {
    shape.setFillColor(Color::Green);
    shape.setOutlineColor(Color::Black);
    shape.setOutlineThickness(1.f);
    shape.setSize(Vector2f(tileSize, tileSize));
    shape.setPosition(position);
}

void Tile::render(RenderTarget *target) {  
    target->draw(shape);

    if (creature != nullptr) {
        creature->render(target);
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

void Tile::setDeadPixel() {
    shape.setFillColor(Color::Red);
}

void Tile::deploySoldier(Creature *creature) {
    this->creature = creature;
    this->creature->setPosition(Vector2f(this->position.x + this->tileSize/2, this->position.y + this->tileSize/2));
}

RectangleShape Tile::getShape() {
    return shape;
}

void Tile::castShadow(Creature *creature) {
    if(creature == nullptr) {
        return;
    }

    creature->initShadowShape(this->position);
}

void Tile::clearShadow() {
    if(this->creature == nullptr) {
        return;
    }

    this->creature->clearShadow();
}