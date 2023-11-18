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
	map = MapFactory().testMap();
	snake = Snake(5, map);
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
	const float magicNumber = 50;
	for (int row = 0; row < map->getRowCount(); row++) {
		for (int col = 0; col < map->getColCount(); col++) {
			SDL_SetRenderDrawColor(renderer, 0x1F, 0x1F, 0x1F, 0xFF);
			SDL_FRect rect = {
				col*magicNumber, row*magicNumber, magicNumber, magicNumber
			};
			SDL_RenderRect(renderer, &rect);
			NodePtr node = map->getNode(row, col);
			if (node) {
				SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
				const double newMagic = node->getSize()*magicNumber;
				const double offset = (magicNumber - newMagic)/2.;
				SDL_FRect rect = {
					col*magicNumber + offset, row*magicNumber + offset, newMagic, newMagic
				};
				SDL_RenderFillRect(renderer, &rect);
			}
		}
	}
}
