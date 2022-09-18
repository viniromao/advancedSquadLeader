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

void Auropodas::initShadowShape(Vector2f position) {
    shadowShape.setFillColor(Color(0,0,255,170));
    shadowShape.setOutlineColor(Color(0,0,0,170));
    shadowShape.setOutlineThickness(1.f);
    shadowShape.setRadius(size);
    shadowShape.setPosition(Vector2f(position.x - this->size, position.y - this->size));
}

void Auropodas::initDestinationShape(Vector2f position) {
    destinationShape.setFillColor(Color(0,0,255,170));
    destinationShape.setOutlineColor(Color(0,0,0,170));
    destinationShape.setOutlineThickness(1.f);
    destinationShape.setRadius(size);
    destinationShape.setPosition(Vector2f(position.x - this->size, position.y - this->size));

}

Auropodas::Auropodas(){
    intiVariables();
    initShape();
}

Auropodas::Auropodas(Vector2f position) {
    intiVariables();
    initShape(position);
}

Auropodas::~Auropodas() {}

void Auropodas::render(RenderTarget *target) {
    target->draw(shape);
}

void Auropodas::renderDestinationShadow(RenderTarget *target) {
    target->draw(destinationShape);
}

void Auropodas::renderShadow(RenderTarget *target) {
    target->draw(shadowShape);
}


void Auropodas::setPosition(Vector2f position) {
    shape.setPosition(Vector2f(position.x - this->size, position.y - this->size));
}

void Auropodas::clearShadow() {
    shadowShape.setRadius(0);
}