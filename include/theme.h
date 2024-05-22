#include "imgui.h"
#include <vector>

namespace ImGui {
    std::vector<const char *> GetThemes();
    void SetTheme(const char *theme, ImGuiStyle *dst);
    void StyleColorsDarkRuda(ImGuiStyle* dst = nullptr); 
    void StyleColorsDracula(ImGuiStyle* dst = nullptr); 
}