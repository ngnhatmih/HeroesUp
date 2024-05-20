#include "game.h"
#include <iostream>

int main() {
    Game &game = Game::GetInstance();
    if (!game.init("HelloWorld", 1280, 720)) {
        return EXIT_FAILURE;
    }

    while (game.isRunning()) {
        game.update();
        game.render();
        game.handleEvent();
    }

    return EXIT_SUCCESS;
}