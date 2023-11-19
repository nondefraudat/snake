#include "snakeapp.hpp"
#include <vector>

SnakeApp& SnakeApp::getInstance() noexcept {
	static SnakeApp instance;
	return instance;
}

SnakeApp::~SnakeApp() noexcept {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

int SnakeApp::exec() noexcept {
	bool exec = true;
	SDL_Event event;
	while (exec) {
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_EVENT_QUIT) {
				exec = false;
			}
			else if (event.type == SDL_EVENT_KEY_DOWN)
			{
				processKeycode(event.key.keysym.sym);
			}
		}
		updateWindow();
	}
	return 0;
}

SnakeApp::SnakeApp() noexcept : snake(3), map(10, 10) {
	map.addNodes(snake.getNodes());
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		// TODO: Error
	}
	window = SDL_CreateWindow("Reframing", 500, 500,
			SDL_WINDOW_BORDERLESS | SDL_WINDOW_OPENGL);
	if (!window) {
		// TODO: Error
	}
	renderer = SDL_CreateRenderer(window, nullptr, SDL_RENDERER_ACCELERATED);
	if (!renderer) {
		// TODO: Error
	}
}

void SnakeApp::updateWindow() noexcept {
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
	renderMap();
	SDL_RenderPresent(renderer);
}

void SnakeApp::processKeycode(const SDL_Keycode keycode) noexcept {
	switch (keycode) {
		case SDLK_UP: {
			return snake.move(-1, 0);
		}
		case SDLK_DOWN: {
			return snake.move(1, 0);
		}
		case SDLK_LEFT: {
			return snake.move(0, -1);
		}
		case SDLK_RIGHT: {
			return snake.move(0, 1);
		}
	}
}

void SnakeApp::renderMap() noexcept {
	for (const SDL_FRect& rect : map.getRects()) {
		SDL_SetRenderDrawColor(renderer, 0xAF, 0xAF, 0xAF, 0xFF);
		SDL_RenderFillRect(renderer, &rect);
	}
}
