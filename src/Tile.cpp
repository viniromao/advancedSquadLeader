#include "Tile.h"

void Tile::initVariables() {
    creature = nullptr;
}

Tile::Tile(Vector2f position){
    initVariables();
    initTileShape(position);
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
}

float Tile::getTileSize() {
    return shape.getGlobalBounds().width;
}

void Tile::setDeadPixel() {
    shape.setFillColor(Color::Red);
}

RectangleShape Tile::getShape() {
    return shape;
}