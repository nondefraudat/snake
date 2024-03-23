#include "application.hpp"
#include <SDL.h>
#include <SDL_main.h>

int main(int argc, char* argv[]) {
	auto& application = Application::getInstance();
	int exitStatus = application.execute();
	return exitStatus;
}
