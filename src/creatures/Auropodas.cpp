#include"include/Auropodas.h"

void Auropodas::intiVariables() {
    size = 15.f;
}

void Auropodas::initShape() {
    shape.setFillColor(Color::Blue);
    shape.setOutlineColor(Color::Black);
    shape.setOutlineThickness(1.f);
    shape.setRadius(size);
}

void Auropodas::initShape(Vector2f position) {
    shape.setFillColor(Color::Blue);
    shape.setOutlineColor(Color::Black);
    shape.setOutlineThickness(1.f);
    shape.setRadius(size);
    shape.setPosition(position);
}

Auropodas::Auropodas(){
    intiVariables();
    initShape();
}

Auropodas::Auropodas(Vector2f position) {
    intiVariables();
    initShape(position);
}

Auropodas::~Auropodas() {
    
}

void Auropodas::render(RenderTarget *target) {
    target->draw(shape);
}

void Auropodas::setPosition(Vector2f position) {
    shape.setPosition(position);
}