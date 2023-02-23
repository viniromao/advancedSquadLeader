#include"include/CreatureHud.h"

void CreatureHud::render(RenderTarget *target, Vector2f position) {
    circleShape.setPosition(getHudPosition(position));
    target->draw(circleShape);
}

CreatureHud::CreatureHud(){}

CreatureHud::CreatureHud(ClickEventProducer *producer){
    initShapes();
    initClickEventObserver(producer);
}

CreatureHud::~CreatureHud() {}

Vector2f CreatureHud::getHudPosition(Vector2f position) {
    return Vector2f(position.x, position.y - 60.f);
}

void CreatureHud::initShapes() {
    circleShape.setFillColor(Color(0,0,0,255));
    circleShape.setRadius(30.f);
}

void CreatureHud::initClickEventObserver(ClickEventProducer *producer) {
    observer = new ClickEventObserver(*producer);

}