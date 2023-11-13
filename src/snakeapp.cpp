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
			//else if (event.type == SDL_EVENT_KEY_DOWN)
			//{
			//	processKeycode(event.key.keysym.sym);
			//}
		}
		updateWindow();
	}
	return 0;
}

SnakeApp::SnakeApp() noexcept {
	map = MapFactory().generateMap();
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
	 
}

void SnakeApp::renderMap() noexcept {
	const float magicNumber = 100;
	for (int i = 0; i < map->getHeight(); i++) {
		for (int j = 0; j < map->getWidth(); j++) {
			if (!map->getCell(i, j)) {
				continue;
			}
			SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
			SDL_FRect rect = {
				i*magicNumber, j*magicNumber, magicNumber, magicNumber
			};
			SDL_RenderFillRect(renderer, &rect);
		}
	}
}