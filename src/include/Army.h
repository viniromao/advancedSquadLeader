#ifndef _ARMY_H_
#define _ARMY_H_

#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>

#include<vector>

#include"include/Creature.h"
#include"include/Coordinate.h"

using namespace std;

struct DeployRegion {
    Coordinate begin {};
    Coordinate end {};
};


class Army {
    private:
    public:
        DeployRegion deployRegion {};
        vector<Creature *> soldiers;

        Army(DeployRegion deployRegion);
        ~Army();

};

#endif