#pragma once

#include "map.hpp"

class MapFactory {
public:
	MapFactory() noexcept;

	MapPtr generateMap() noexcept;
};