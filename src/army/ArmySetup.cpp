#include"include/ArmySetup.h"

void ArmySetup::randomizeCreatures() {
    vector<Creature *> creatures;
    
    for(size_t i = 0; i < creaturesAmount; i++) {
        string creatureType = creatureTypes[rand() % creatureTypes.size()];

        if (creatureType == "WIOLAN") {
            creatures.push_back(new Wiolan(this->producer));
        }

        if (creatureType == "AUROPODAS") {
            creatures.push_back(new Auropodas(this->producer));
        }
    }

    backLineCreatures = creatures;
    currentSoldierToDeploy = backLineCreatures[0];

    creatures.clear();
}

ArmySetup::ArmySetup(){}

ArmySetup::ArmySetup(ClickEventProducer *producer){
    this->producer = producer;
    randomizeCreatures();
}

ArmySetup::~ArmySetup() {
    backLineCreatures.clear();
}

void ArmySetup::renderGUI() {
    
}

void ArmySetup::selectCreatureByClick() {}

Creature *ArmySetup::getCurrentSoldierToDeploy() {
    soldiersDeployed += 1;

    return this->currentSoldierToDeploy;
}

void ArmySetup::getNextSoldierToDeploy() {
    backLineCreatures.erase(backLineCreatures.begin());
    currentSoldierToDeploy = backLineCreatures[0];
}

bool ArmySetup::haveSoldiersToDeploy() {
    if (backLineCreatures.size() == 0) {
        return false;
    }

    return true;
}




