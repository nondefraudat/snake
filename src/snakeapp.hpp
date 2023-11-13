#pragma once

#include <SDL3/SDL.h>

class SnakeApp {
public:
	static SnakeApp& getInstance() noexcept;
	
	~SnakeApp() noexcept;

	int exec() noexcept;

	void updateWindow() noexcept;
	void processKeycode(const SDL_Keycode keycode) noexcept;

private:
	SDL_Window* window;
	SDL_Renderer* renderer;

	SnakeApp() noexcept;
};