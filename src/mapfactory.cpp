#include "mapfactory.hpp"

using namespace std;

MapPtr MapFactory::testMap() noexcept {
	return make_shared<Map>(10, 10);
}
