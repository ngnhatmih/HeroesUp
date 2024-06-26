#ifndef GAME_H
#define GAME_H
#include <SDL3/SDL.h>
#include "imgui.h"
#include "imgui_test.h"

class Game {
public:
    static Game& GetInstance() {
        static Game instance;
        return instance;
    }

    Game(Game const&) = delete;
    void operator=(Game const&) = delete;

    bool init(const char *title, int width, int height);
    void render();
    void handleEvent();
    void update();
    void quit();

    bool isRunning() { return running; }
    SDL_Window *getWindow() { return window; }
    SDL_Renderer *getRenderer() { return renderer; }
    ~Game();

private:
    Game() {}

    bool running;
    SDL_Window *window;
    SDL_Renderer *renderer;

    State *current_state;
};

#endif /* GAME_H */