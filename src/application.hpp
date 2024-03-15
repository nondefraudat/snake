#pragma once

#include "snake.hpp"
#include "map.hpp"
#include <SDL3/SDL.h>
#include <memory>

class Application {
public:
    ~Application() noexcept;
    static Application& getInstance() noexcept;
    int execute() noexcept;

private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    bool quit = false;
    std::shared_ptr<Map> map;
    std::shared_ptr<Snake> snake;

    Application() noexcept;

    void processEvents() noexcept;
    void updateWindow() noexcept;
    void processBeat() noexcept;

    void processEvent(const SDL_Event& eventBuffer) noexcept;
    void processKeycode(SDL_Scancode scancode) noexcept;
};
