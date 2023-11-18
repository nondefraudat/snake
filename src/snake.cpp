#include "snake.hpp"

using namespace std;

Snake::Snake(const size_t size, const MapPtr& map) noexcept {
	for (size_t i = 0; i < size; i++) {
		NodePtr node = make_shared<Node>(.8);
		body.push_back(node);
		map->setNode(map->getRowCount() / 2 + i, map->getColCount() / 2, node);
	}
}
