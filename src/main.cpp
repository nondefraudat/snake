#include "snakeapp.hpp"
#include <iostream>

using namespace std;

int main() {
	SnakeApp app = SnakeApp::getInstance();
	return app.exec();
}
