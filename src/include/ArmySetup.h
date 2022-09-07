#ifndef _ARMY_SETUP_H_
#define _ARMY_SETUP_H_

#include<vector>
#include<string>
#include<random>

#include"include/Creature.h"
#include"include/Wiolan.h"
#include"include/Auropodas.h"
#include"include/Army.h"

using namespace std;

class ArmySetup {
    private:
        vector<string> creatureTypes{"WIOLAN", "AUROPODAS"};
        vector<Creature *> backLineCreatures;
        Creature * currentSoldierToDeploy;

        unsigned int soldiersDeployed = 0;

        void randomizeCreatures();
    public:
        ArmySetup();
        virtual ~ArmySetup();

        void getNextSoldierToDeploy();
        Creature *getCurrentSoldierToDeploy();
        bool haveSoldiersToDeploy();
        void renderGUI();
        void selectCreatureByClick();
};

#endif