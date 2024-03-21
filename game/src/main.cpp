#include "application.hpp"
#include <SDL.h>
#include <cassert>

int main() {
	auto& application = Application::getInstance();
	int exitStatus = application.execute();
	return exitStatus;
}
