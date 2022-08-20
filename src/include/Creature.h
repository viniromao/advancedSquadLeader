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
        void intiVariables();
        void initShape(Vector2f position);

    public:
        Creature();
        Creature(Vector2f position);
        virtual ~Creature();

        virtual void render(RenderTarget *target);
};

#endif