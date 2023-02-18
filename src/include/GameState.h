#ifndef _GAMESTATE_H_
#define _GAMESTATE_H_

#include<string>

using namespace std;

enum GameStateEnum {
    ARMY_SETUP,
    PLAN,
    GAME
};

class GameState {
    private:
        GameStateEnum gameStates[3] = {ARMY_SETUP,PLAN,GAME};
        GameStateEnum currentGameState;
    public:
        GameState();
        virtual ~GameState();

        GameStateEnum getCurrentGameState();
        void evolveState(GameStateEnum state);
};

#endif