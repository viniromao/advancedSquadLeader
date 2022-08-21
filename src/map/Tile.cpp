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

    if (creature == nullptr) {
        return;
    } 
    creature->render(target);
}

float Tile::getTileSize() {
    return shape.getGlobalBounds().width;
}

void Tile::setDeadPixel() {
    shape.setFillColor(Color::Red);
}

void Tile::deploySoldier(Creature *creature) {
    this->creature = creature;
    this->creature->setPosition(position);
}

RectangleShape Tile::getShape() {
    return shape;
}