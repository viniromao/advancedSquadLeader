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
    private:
    public:
        Creature();
        virtual ~Creature();

        virtual void render(RenderTarget *target) = 0;
        virtual void initShape(Vector2f position) = 0;
        virtual void setPosition(Vector2f position) = 0;
};

#endif