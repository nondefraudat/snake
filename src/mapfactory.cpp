#include "mapfactory.hpp"

using namespace std;

MapFactory::MapFactory() noexcept {

}

MapPtr MapFactory::generateMap() noexcept {
	MapPtr map = make_shared<Map>(5, 5);

	map->setCell(2, 0, make_shared<Cell>());

	map->setCell(0, 1, make_shared<Cell>());
	map->setCell(1, 1, make_shared<Cell>());
	map->setCell(2, 1, make_shared<Cell>());
	map->setCell(3, 1, make_shared<Cell>());

	map->setCell(0, 2, make_shared<Cell>());
	map->setCell(1, 2, make_shared<Cell>());
	map->setCell(2, 2, make_shared<Cell>());
	map->setCell(3, 2, make_shared<Cell>());
	map->setCell(4, 2, make_shared<Cell>());

	map->setCell(0, 3, make_shared<Cell>());
	map->setCell(1, 3, make_shared<Cell>());
	map->setCell(3, 3, make_shared<Cell>());
	map->setCell(4, 3, make_shared<Cell>());

	map->setCell(0, 4, make_shared<Cell>());
	map->setCell(1, 4, make_shared<Cell>());
	map->setCell(2, 4, make_shared<Cell>());
	map->setCell(3, 4, make_shared<Cell>());

	return map;
}
