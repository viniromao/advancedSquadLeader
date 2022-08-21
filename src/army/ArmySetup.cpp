#include"include/ArmySetup.h"

void ArmySetup::randomizeCreatures() {
    vector<Creature *> creatures;
    
    for(size_t i = 0; i < 4; i++) {
        string creatureType = creatureTypes[rand() % creatureTypes.size()];


        if (creatureType == "WIOLAN") {
            creatures.push_back(new Wiolan());
        }

        if (creatureType == "AUROPODAS") {
            creatures.push_back(new Auropodas());
        }
    }

    backLineCreatures = creatures;

    creatures.clear();
}

ArmySetup::ArmySetup(){
    randomizeCreatures();
}

ArmySetup::~ArmySetup() {
    backLineCreatures.clear();
}

void ArmySetup::renderGUI() {
    
}

void ArmySetup::selectCreatureByClick() {
    
}

Creature *ArmySetup::getNextSoldierToDeploy() {
    if (backLineCreatures.size() == soldiersDeployed) {
        return nullptr;
    }
    soldiersDeployed++;

    return backLineCreatures.at(soldiersDeployed - 1);
}

bool ArmySetup::haveSoldiersToDeploy() {
    if (backLineCreatures.size() == soldiersDeployed) {
        return false;
    }

    return true;
}




