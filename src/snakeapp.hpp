#pragma once

#include "mapfactory.hpp"
#include "snake.hpp"
#include <SDL3/SDL.h>

class SnakeApp {
public:
	static SnakeApp& getInstance() noexcept;
	
	~SnakeApp() noexcept;

	int exec() noexcept;

private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	MapPtr map;
	Snake snake;

	SnakeApp() noexcept;

	void updateWindow() noexcept;
	void processKeycode(const SDL_Keycode keycode) noexcept;

	void renderMap() noexcept;
};