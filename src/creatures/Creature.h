#ifndef _CREATURE_H_
#define _CRETURE_H_

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
};

#endif