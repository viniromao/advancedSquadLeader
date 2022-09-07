#ifndef _GAMESTATE_H_
#define _GAMESTATE_H_

#include<string>

using namespace std;

class GameState {
    private:
        string gameStates[3] = {"ARMY_SETUP","PLAN","GAME"};

        string currentGameState;
    public:
        GameState();
        virtual ~GameState();

        string getCurrentGameState();
        void evolveState();
};

#endif