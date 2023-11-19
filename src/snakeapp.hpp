#pragma once

#include "map.hpp"
#include "snake.hpp"
#include <SDL3/SDL.h>

class SnakeApp {
public:
	static SnakeApp& getInstance() noexcept;
	
	~SnakeApp() noexcept;

	int exec() noexcept;

private:
	Snake snake;
	Map map;
	SDL_Window* window;
	SDL_Renderer* renderer;

	SnakeApp() noexcept;

	void updateWindow() noexcept;
	void processKeycode(const SDL_Keycode keycode) noexcept;

	void renderMap() noexcept;
};