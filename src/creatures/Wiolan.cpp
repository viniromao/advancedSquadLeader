#include"Wiolan.h"

void Wiolan::intiVariables() {
    size = 30.f;
}

void Wiolan::initShape(Vector2f position) {
    shape.setFillColor(Color::Blue);
    shape.setOutlineColor(Color::Black);
    shape.setOutlineThickness(1.f);
    shape.setRadius(size/2);
    shape.setPosition(position);
}

Wiolan::Wiolan(){

}

Wiolan::~Wiolan() {
    
}