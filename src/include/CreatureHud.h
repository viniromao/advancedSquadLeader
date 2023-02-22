#ifndef _CREATURE_HUD_H_
#define _CREATURE_HUD_H_

#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include "include/CreatureInfo.h"
#include "include/Coordinate.h"

using namespace sf;

class CreatureHud{
    private:

        CircleShape circleShape;

        Vector2f getHudPosition(Vector2f position);
        void initShapes();
    public:
        CreatureHud();
        virtual ~CreatureHud();
        void render(RenderTarget *target, Vector2f position);
};

#endif