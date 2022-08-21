#ifndef _GAMESTATE_H_
#define _GAMESTATE_H_

#include<string>

using namespace std;

class GameState {
    private:
        string gameStates[2] = {"ARMY_SETUP","GAME"};

        string currentGameState;
    public:
        GameState();
        virtual ~GameState();

        string getCurrentGameState();
        void evolveState();
};

#endif