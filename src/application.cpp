#include "application.hpp"
#include <cassert>
#include <iostream>

Application& Application::getInstance() noexcept {
    static auto instance = Application();
    return instance;
}

int Application::execute() noexcept {
    auto timer = SDL_AddTimer(1000,
            [](Uint32 interval, void* application) -> Uint32 {
                reinterpret_cast<Application*>(application)
                        ->processBeat();
                return interval;
            }, this);
    quit = false;
    while (!quit) {
        processEvents();
        updateWindow();
    }
    SDL_RemoveTimer(timer);
    return 0;
}

Application::Application() noexcept
    : window(std::move(decltype(window)(SDL_CreateWindow("snake", 500, 500,
			        SDL_WINDOW_BORDERLESS | SDL_WINDOW_OPENGL),
            &SDL_DestroyWindow))) {
    assert(window != nullptr);
    renderer = decltype(renderer)(SDL_CreateRenderer(window.get(), nullptr,
                    SDL_RENDERER_ACCELERATED), &SDL_DestroyRenderer);
    assert(renderer != nullptr);
}

void Application::processEvents() noexcept {
    SDL_Event eventBuffer;
    while (SDL_PollEvent(&eventBuffer)) {
        if (eventBuffer.type == SDL_EVENT_QUIT){
            quit = true;
        }
    }
}

void Application::updateWindow() noexcept {
    
}

void Application::processBeat() noexcept {
    static int beatCounter = 1;
    std::cout << "beat " << beatCounter++ << ";\n";
}
