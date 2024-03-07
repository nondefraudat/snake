#pragma once

#include "framework.hpp"

class Shape {
public:
    virtual void render(Renderer renderer) noexcept = 0;
};

// int SnakeApp::exec() noexcept {
// 	bool exec = true;
// 	SDL_Event event;
// 	while (exec) {
// 		while (SDL_PollEvent(&event)) {
// 			if (event.type == SDL_EVENT_QUIT) {
// 				exec = false;
// 			}
// 			else if (event.type == SDL_EVENT_KEY_DOWN)
// 			{
// 				processKeycode(event.key.keysym.sym);
// 			}
// 		}
// 		updateWindow();
// 	}
// 	return 0;
// }

// void SnakeApp::processKeycode(const SDL_Keycode keycode) noexcept {
// 	switch (keycode) {
// 		case SDLK_UP: {
// 			return snake.move(-1, 0);
// 		}
// 		case SDLK_DOWN: {
// 			return snake.move(1, 0);
// 		}
// 		case SDLK_LEFT: {
// 			return snake.move(0, -1);
// 		}
// 		case SDLK_RIGHT: {
// 			return snake.move(0, 1);
// 		}
// 	}
// }

// void SnakeApp::updateWindow() noexcept {
// 	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
// 	SDL_RenderClear(renderer);
// 	renderMap();
// 	SDL_RenderPresent(renderer);
// }

// void SnakeApp::renderMap() noexcept {
// 	for (const SDL_FRect& rect : map.getRects()) {
// 		SDL_SetRenderDrawColor(renderer, 0xAF, 0xAF, 0xAF, 0xFF);
// 		SDL_RenderFillRect(renderer, &rect);
// 	}
// }
