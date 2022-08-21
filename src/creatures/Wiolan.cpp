#include"include/Wiolan.h"

void Wiolan::intiVariables() {
    size = 15.f;
}

void Wiolan::initShape() {
    shape.setFillColor(Color::Yellow);
    shape.setOutlineColor(Color::Black);
    shape.setOutlineThickness(1.f);
    shape.setRadius(size);
}

void Wiolan::initShape(Vector2f position) {
    shape.setFillColor(Color::Yellow);
    shape.setOutlineColor(Color::Black);
    shape.setOutlineThickness(1.f);
    shape.setRadius(size);
    shape.setPosition(position);
}

Wiolan::Wiolan(){
    intiVariables();
    initShape();
}

Wiolan::Wiolan(Vector2f position) {
    intiVariables();
    initShape(position);
}

Wiolan::~Wiolan() {
    
}

void Wiolan::render(RenderTarget *target) {
    target->draw(shape);
}

void Wiolan::setPosition(Vector2f position) {
    shape.setPosition(position);
}