#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "include/Army.h"
#include "include/ArmySetup.h"

class Player{
    private:
    public:
     Army army {};
     ArmySetup armySetup {};
     vector<Player> enemies;

     Player();
     virtual ~Player();

};

#endif