#ifndef _ARMY_H_
#define _ARMY_H_

#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>

#include<vector>

#include"include/Creature.h"

using namespace std;

class Army {
    private:
    public:
        vector<Creature *> soldiers;

        Army();
        ~Army();
};

#endif