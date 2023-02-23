#include"include/MainHud.h"

MainHud::MainHud(RenderWindow *window, ClickEventProducer *producer){
    this->observer = new ClickEventObserver(*producer);
    this->mainHudBackground = RectangleShape (Vector2f(window->getSize().x,this->mainHudHeight));
    this->mainHudBackground.setOutlineColor(Color(255,0,0,255));
    this->mainHudBackground.setOutlineThickness(2.0);
    this->mainHudBackground.setFillColor(Color(255,0,0,255));
    this->mainHudBackground.setPosition(Vector2f(0,window->getSize().y - this->mainHudHeight));
}

MainHud::MainHud() {}

MainHud::~MainHud() {}

void MainHud::renderMainHud(RenderTarget *target) {
    target->draw(this->mainHudBackground);
}

