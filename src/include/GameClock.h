#ifndef _GAME_CLOCK_H_
#define _GAME_CLOCK_H_

#include <chrono>

using namespace std;

class GameClock {
private:
    chrono::high_resolution_clock::time_point begin;

    void initVariables();
    void initClockShape();

public:
    unsigned elapsedTime = 0;
    int timerSeconds = 1;
    unsigned timerDuration = 5;

    GameClock();
    virtual ~GameClock();

    void startClock();
    unsigned getPassedSeconds();
    void render();
    void update();
};

#endif