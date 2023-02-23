#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "include/Army.h"
#include "include/ArmySetup.h"
#include "include/Coordinate.h"

class Player{
    private:
    public:
        Army army {DeployRegion{Coordinate(0,0), Coordinate(2,2)}};
        ArmySetup armySetup;
        vector<Player> enemies;

        ClickEventProducer *producer;

        Player(ClickEventProducer *producer);
        virtual ~Player();

};

#endif