#include "application.hpp"
#include <cassert>

int main() {
	assert(SDL_Init(SDL_INIT_VIDEO) >= 0);
	
	auto& application = Application::getInstance();
	int exitStatus = application.execute();
	
	SDL_Quit();
	return exitStatus;
}
