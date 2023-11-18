#pragma once

#include "map.hpp"
#include <vector>

class Snake {
public:
	Snake() noexcept = default;
	Snake(const size_t size, const MapPtr& map) noexcept;

private:
	std::vector<NodePtr> body;
	MapPtr map;
};
