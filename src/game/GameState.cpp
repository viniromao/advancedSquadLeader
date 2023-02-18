#include"include/GameState.h"

GameState::GameState(){
    currentGameState = gameStates[0];
}

GameState::~GameState() {
    
}

GameStateEnum GameState::getCurrentGameState() {
    return currentGameState;
}

void GameState::evolveState(GameStateEnum state) {
    currentGameState = state;
}