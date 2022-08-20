#ifndef _ARMY_SETUP_H_
#define _ARMY_SETUP_H_

#include<vector>

#include"include/Creature.h"
#include"include/Army.h"

using namespace std;

class ArmySetup {
    private:
        vector<Creature> backLineCreatures;

        vector<Creature> randomizeCreatures();
    public:
        ArmySetup();
        virtual ~ArmySetup();

        void renderGUI();
        void selectCreatureByClick();
};

#endif