#include "application.hpp"
#include <cassert>
#include <iostream>

Application::~Application() noexcept {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

Application &Application::getInstance() noexcept {
    static Application instance;
    return instance;
}

int Application::execute() noexcept {
    auto timer = SDL_AddTimer(100,
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

Application::Application() noexcept {
    assert(SDL_Init(SDL_INIT_VIDEO) >= 0);
	window = SDL_CreateWindow("snake", 500, 500,
            SDL_WINDOW_BORDERLESS | SDL_WINDOW_OPENGL);
    assert(window != nullptr);
    renderer = SDL_CreateRenderer(window, nullptr,
            SDL_RENDERER_ACCELERATED);
    assert(renderer != nullptr);
    map = std::make_shared<GameBoard>();
    snake = std::make_shared<Snake>(map);
}

void Application::processEvents() noexcept {
    SDL_Event eventBuffer;
    while (SDL_PollEvent(&eventBuffer)) {
        processEvent(eventBuffer);
    }
}

void Application::updateWindow() noexcept {
    SDL_SetRenderDrawColor(renderer, 0x10, 0x15, 0x1D, 0xFF);
    SDL_RenderClear(renderer);
    map->render(renderer);
    SDL_RenderPresent(renderer);
}

void Application::processBeat() noexcept {
    assert(snake->move());
}

void Application::processEvent(const SDL_Event& eventBuffer) noexcept {
    switch (eventBuffer.type) {
        case SDL_EVENT_QUIT: {
            quit = true;
            return;
        }
        case SDL_EVENT_KEY_DOWN: {
            return processKeycode(eventBuffer.key.keysym.scancode);
        }
    }
}

void Application::processKeycode(SDL_Scancode scancode) noexcept {
    switch (scancode) {
        case SDL_SCANCODE_LEFT:
        case SDL_SCANCODE_A: {
            snake->setDirection(Snake::Direction::Left);
            return;
        }
        case SDL_SCANCODE_RIGHT:
        case SDL_SCANCODE_D: {
            snake->setDirection(Snake::Direction::Right);
            return;
        }
        case SDL_SCANCODE_UP:
        case SDL_SCANCODE_W: {
            snake->setDirection(Snake::Direction::Up);
            return;
        }
        case SDL_SCANCODE_DOWN:
        case SDL_SCANCODE_S: {
            snake->setDirection(Snake::Direction::Down);
            return;
        }
    }
}
