#include"include/GameState.h"

GameState::GameState(){
    currentGameState = gameStates[0];
}

GameState::~GameState() {
    
}

string GameState::getCurrentGameState() {
    return currentGameState;
}

void GameState::evolveState(string state) {
    currentGameState = state;
}