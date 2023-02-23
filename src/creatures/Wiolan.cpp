#include"include/Wiolan.h"

void Wiolan::intiVariables() {
    sight = 2;
    size = 30.f;

    if (!texture.loadFromFile("../assets/sprites/wiolan.png")) {
       std::cout << "sprite not loaded";
    }
}

void Wiolan::initShape() {
    shape.setRadius(size);
    shape.setTexture(&texture);
}

void Wiolan::initShape(Vector2f position) {
    shape.setFillColor(Color::Yellow);
    shape.setOutlineColor(Color::Black);
    shape.setOutlineThickness(1.f);
    shape.setRadius(size);
    shape.setPosition(position);
}

void Wiolan::initShadowShape(Vector2f position) {
    shadowShape.setFillColor(Color(254,221,0,170));
    shadowShape.setOutlineColor(Color(0,0,0,170));
    shadowShape.setOutlineThickness(1.f);
    shadowShape.setRadius(size);
    shadowShape.setPosition(Vector2f(position.x - this->size, position.y - this->size));
}

void Wiolan::initDestinationShape(Vector2f position) {
    destinationShape.setFillColor(Color(254,221,0,170));
    destinationShape.setOutlineColor(Color(0,0,0,170));
    destinationShape.setOutlineThickness(1.f);
    destinationShape.setRadius(size);
    destinationShape.setPosition(Vector2f(position.x - this->size, position.y - this->size));
}

Wiolan::Wiolan(ClickEventProducer *producer){
    this->producer = producer;
    this->creatureHud = CreatureHud(producer);
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

void Wiolan::renderHud(RenderTarget *target) {
    if(this->creatureHudIsActive){
        creatureHud.render(target, this->position);
    }
}


void Wiolan::renderDestinationShadow(RenderTarget *target) {
    target->draw(destinationShape);
}

void Wiolan::renderShadow(RenderTarget *target) {
    target->draw(shadowShape);
}


void Wiolan::setPosition(Vector2f position) {
    this->position = Vector2f(position.x - this->size, position.y - this->size);
    shape.setPosition(Vector2f(position.x - this->size, position.y - this->size));
}

void Wiolan::clearShadow() {
    shadowShape.setRadius(0);
}