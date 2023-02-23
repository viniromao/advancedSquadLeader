#ifndef _CREATURE_H_
#define _CREATURE_H_

#include <iostream>
#include <vector>
#include <sstream>

#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>

#include"include/CreatureInfo.h"
#include"include/CreatureHud.h"

using namespace sf;

class Creature {
    protected:
        float size;
        Vector2f position = Vector2f(0,0);

    public:
        Creature();
        virtual ~Creature();

        ClickEventProducer *producer = nullptr;

        bool creatureHudIsActive = false;
        Vector2i discreteActualTilePosition;
        unsigned sight = 1;
        CreatureInfo creatureInfo{};
        CreatureHud creatureHud;

        virtual void render(RenderTarget *target);
        virtual void renderHud(RenderTarget *target);
        virtual void renderDestinationShadow(RenderTarget *target);
        virtual void renderShadow(RenderTarget *target);
        virtual void initShape(Vector2f position);
        virtual void initDestinationShape(Vector2f position);
        virtual void initShadowShape(Vector2f position);
        virtual void setPosition(Vector2f position);
        virtual void clearShadow();
};

#endif