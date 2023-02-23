#include "include/Game.h"
#include "include/ClickEventObserver.h"

int ClickEventObserver::static_number_ = 0;

int main() {

    srand(time(nullptr));

    Game game;

    while(game.running()) {
        game.update();
        game.render();
    }

    return 0;
}
