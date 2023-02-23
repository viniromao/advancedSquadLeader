#include"include/Player.h"

Player::Player(ClickEventProducer *producer){
    this->producer = producer;
    this->armySetup = ArmySetup(producer);

}

Player::~Player() {}