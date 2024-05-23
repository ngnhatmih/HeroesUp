#ifndef TEST_H
#define TEST_H
#include "state.h"
#include "imgui.h"

class ImGuiTest: public State {
public:
    ImGuiTest();
    ~ImGuiTest() {}
    void update();
    void render();
    void onEnter();
    void onExit();

private:
    bool demo_window;
    ImVec4 clear_color;
};

#endif /* TEST_H */