#include"include/GameClock.h"

void GameClock::initClockShape() {
    
}

void GameClock::initVariables() {}

GameClock::GameClock() {
    initVariables();
    startClock();
}

GameClock::~GameClock() {}

unsigned GameClock::getPassedSeconds() {
   return chrono::duration_cast<chrono::seconds>(chrono::high_resolution_clock::now() - begin).count();
}

void GameClock::render() {
    
}

void GameClock::startClock() {
    this->begin = chrono::high_resolution_clock::now();

}

void GameClock::update() {
    elapsedTime = getPassedSeconds();
    timerSeconds = timerDuration - elapsedTime;
}

