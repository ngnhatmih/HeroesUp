#include "game.h"
#include "imgui.h"
#include "imgui_impl_sdl3.h"
#include "imgui_impl_sdlrenderer3.h"

Game::~Game() {
    
}

bool Game::init(const char *title, int width, int height) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Could not init SDL: %s", SDL_GetError());
        return false;
    }

    SDL_Log("Succesfully initialized SDL");

    Uint32 window_flags = 0;
    window = SDL_CreateWindow(title, width, height, window_flags);
    if (!window) {
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Could not create window: %s", SDL_GetError());
        return false;
    }
    SDL_Log("Successfully created window");

    renderer = SDL_CreateRenderer(window, 0);
    if (!renderer) {
        SDL_LogError(SDL_LOG_CATEGORY_RENDER, "Could not create renderer: %s", SDL_GetError());
        return false;
    }
    SDL_Log("Successfully created renderer");

    running = true;
    demo_window = true;
    SDL_ShowWindow(window);

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;         // Enable Docking

    ImGui::StyleColorsClassic();

    ImGui_ImplSDL3_InitForSDLRenderer(window, renderer);
    ImGui_ImplSDLRenderer3_Init(renderer);

    return true;
}

void Game::handleEvent() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        ImGui_ImplSDL3_ProcessEvent(&event);
        Uint32 event_type = event.type;
        if (event_type == SDL_EVENT_WINDOW_CLOSE_REQUESTED && event.window.windowID == SDL_GetWindowID(window)) {
            SDL_Log("Closing window...");
            quit();
            break;
        } else if (event_type == SDL_EVENT_QUIT) {
            SDL_Log("Closing window...");
            quit();
            break;
        }
    }
}

void Game::render() {
    ImGui_ImplSDLRenderer3_NewFrame();
    ImGui_ImplSDL3_NewFrame();
    ImGui::NewFrame();

    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 255,255,255,255);

    if (demo_window) {
        ImGui::ShowDemoWindow(&demo_window);
    }

    ImGui::Render();
    ImGui_ImplSDLRenderer3_RenderDrawData(ImGui::GetDrawData(), renderer);

    SDL_RenderPresent(renderer);
}

void Game::update() {

}

void Game::quit() {
    running = false;
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);

    ImGui_ImplSDLRenderer3_Shutdown();
    ImGui_ImplSDL3_Shutdown();
    ImGui::DestroyContext();

    SDL_Quit();
}