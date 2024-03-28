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
    quit = false;
    while (!quit) {
        processEvents();
        updateWindow();
        processBeat();
    }
    return 0;
}

Application::Application() noexcept {
    assert(SDL_Init(SDL_INIT_VIDEO) >= 0);
	window = SDL_CreateWindow("snake", -1, -1,
            SDL_WINDOW_FULLSCREEN);
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
    static SDL_Point touchLocation;
    switch (eventBuffer.type) {
        case SDL_EVENT_QUIT: {
            quit = true;
            return;
        }
        case SDL_EVENT_KEY_DOWN: {
            return processKeycode(eventBuffer.key.keysym.scancode);
        }
        case SDL_EVENT_FINGER_DOWN: {
            touchLocation.x = eventBuffer.tfinger.x;
            touchLocation.y = eventBuffer.tfinger.y;
            return;
        }
        case SDL_EVENT_FINGER_MOTION: {
            if (std::abs(eventBuffer.tfinger.dy) >
                    abs(eventBuffer.tfinger.dx)) {
                if (eventBuffer.tfinger.dy > 0) {
                    snake->setDirection(Snake::Direction::Down);
                }
                else {
                    snake->setDirection(Snake::Direction::Up);
                }
            }
            else {
                if (eventBuffer.tfinger.dx < 0) {
                    snake->setDirection(Snake::Direction::Left);
                }
                else {
                    snake->setDirection(Snake::Direction::Right);
                }
            }
            return;
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
