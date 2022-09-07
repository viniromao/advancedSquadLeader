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

void Wiolan::initShadowShape(Vector2f position) {
    shadowShape.setFillColor(Color::Black);
    shadowShape.setOutlineColor(Color::Black);
    shadowShape.setOutlineThickness(1.f);
    shadowShape.setRadius(size);
    shadowShape.setPosition(Vector2f(position.x + this->size, position.y + this->size));
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

void Wiolan::renderShadow(RenderTarget *target) {
    target->draw(shadowShape);
}


void Wiolan::setPosition(Vector2f position) {
    shape.setPosition(Vector2f(position.x - this->size, position.y - this->size));
}

void Wiolan::clearShadow() {
    shadowShape.setRadius(0);
}