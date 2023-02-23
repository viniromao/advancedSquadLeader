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
        
        unsigned int creaturesAmount = 1;
        unsigned int soldiersDeployed = 0;

        void randomizeCreatures();
    public:
        Creature * currentSoldierToDeploy;

        ClickEventProducer *producer;

        ArmySetup();
        ArmySetup(ClickEventProducer *producer);
        virtual ~ArmySetup();

        void getNextSoldierToDeploy();
        Creature *getCurrentSoldierToDeploy();
        bool haveSoldiersToDeploy();
        void renderGUI();
        void selectCreatureByClick();
};

#endif