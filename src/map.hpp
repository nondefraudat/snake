#pragma once

#include "node.hpp"
#include <SDL3/SDL.h>
#include <list>

class Map {
public:
	Map(const double rowCount, const double colCount) noexcept;

	std::list<SDL_FRect> getRects() const noexcept;

	void addNode(const NodePtr& node) noexcept;
	void addNodes(const std::list<NodePtr>& nodes) noexcept;

private:
	size_t rowCount, colCount;
	std::list<NodePtr> nodes;
};
