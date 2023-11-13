#include "snakeapp.hpp"

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

void SnakeApp::updateWindow() noexcept {
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);
}

void SnakeApp::processKeycode(const SDL_Keycode keycode) noexcept {
	// 
}

SnakeApp::SnakeApp() noexcept {
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		// TODO: Error
	}
	window = SDL_CreateWindow("Reframing", 640, 480,
		SDL_WINDOW_BORDERLESS | SDL_WINDOW_OPENGL);
	if (!window) {
		// TODO: Error
	}
	renderer = SDL_CreateRenderer(window, nullptr, SDL_RENDERER_ACCELERATED);
	if (!renderer) {
		// TODO: Error
	}
	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
}
