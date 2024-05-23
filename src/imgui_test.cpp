#include "imgui_test.h"
#include "theme.h"
#include "game.h"

ImGuiTest::ImGuiTest() {
    demo_window = false;
    clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
}

void ImGuiTest::render() {
    if (demo_window) {
        ImGui::ShowDemoWindow(&demo_window);
    }

    {
        ImGui::Begin("test", 0, ImGuiWindowFlags_MenuBar);

        ImGui::BeginMenuBar();
        if (ImGui::BeginMenu("Themes")) {
            for (auto theme : ImGui::GetThemes()) {
                if (ImGui::MenuItem(theme)) {
                    ImGui::SetTheme(theme);
                }
            }
            ImGui::EndMenu();
        }
        ImGui::EndMenuBar();

        ImGui::ColorEdit4("Color", (float*)&clear_color);
        ImGui::End();

    }

    SDL_SetRenderDrawColor(Game::GetInstance().getRenderer(), (Uint8)(clear_color.x * 255.0f), (Uint8)(clear_color.y * 255.0f), (Uint8)(clear_color.z * 255.0f), (Uint8)(clear_color.w * 255.0f));
}

void ImGuiTest::update() {
    SDL_Log("Updating ImGuiTest");
}

void ImGuiTest::onEnter() {
    demo_window = true;
}

void ImGuiTest::onExit() {
    
    demo_window = false;
}