#ifndef _CREATURE_H_
#define _CREATURE_H_

#include <iostream>
#include <vector>
#include <ctime>
#include <sstream>

#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>

using namespace sf;

class Creature {
    protected:
        float size;

    public:
        Creature();
        virtual ~Creature();

        Vector2i discreteActualTilePosition;

        virtual void render(RenderTarget *target);
        virtual void renderDestinationShadow(RenderTarget *target);
        virtual void renderShadow(RenderTarget *target);
        virtual void initShape(Vector2f position);
        virtual void initDestinationShape(Vector2f position);
        virtual void initShadowShape(Vector2f position);
        virtual void setPosition(Vector2f position);
        virtual void clearShadow();
};

#endif