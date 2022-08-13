#include "Tile.h"

void Tile::initVariables() {
    creature = nullptr;
}

Tile::Tile(){
    initVariables();
    initTileShape();
}

Tile::~Tile() {
    delete creature;
}

void Tile::initTileShape() {
    shape.setFillColor(Color::Green);
    shape.setOutlineColor(Color::Black);
    shape.setOutlineThickness(1.f);
    shape.setSize(Vector2f(tileSize, tileSize));
}

void Tile::render(RenderTarget *target, Vector2f position) {
    shape.setPosition(position);
    target->draw(shape);
}

float Tile::getTileSize() {
    return shape.getGlobalBounds().width;
}