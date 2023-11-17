#include "mapfactory.hpp"

using namespace std;

MapPtr MapFactory::testMap() noexcept {
	MapPtr map = make_shared<Map>(10, 10);

	map->setNode(4, 3, make_shared<Node>(.8));
	map->setNode(4, 2, make_shared<Node>(.8));
	map->setNode(4, 1, make_shared<Node>(.8));
	map->setNode(3, 0, make_shared<Node>(.8));

	return map;
}
