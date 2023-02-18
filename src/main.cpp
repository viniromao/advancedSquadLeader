#include "include/Game.h"

int main() {

    srand(time(nullptr));

    Game game;

    while(game.running()) {
        game.update();
        game.render();
    }

    return 0;
}
