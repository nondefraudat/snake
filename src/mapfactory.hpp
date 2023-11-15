#pragma once

#include "map.hpp"

class MapFactory {
public:
	MapFactory() noexcept = default;

	MapPtr testMap() noexcept;
};