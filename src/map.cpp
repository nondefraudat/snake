#include "map.hpp"

using namespace std;

Map::Map(const double rowCount, const double colCount) noexcept
		: rowCount(rowCount), colCount(colCount) { }

std::list<SDL_FRect> Map::getRects() const noexcept {
	static const double factor = 10.;
	list<SDL_FRect> rects;
	for (const NodePtr& node : nodes) {
		const SDL_FRect rect {
			factor*node->col, factor*node->row, factor, factor
		};
		rects.push_back(rect);
	}
	return rects;
}

void Map::addNode(const NodePtr& node) noexcept {
	nodes.push_back(node);
}

void Map::addNodes(const std::list<NodePtr>& nodes) noexcept {
	for (const NodePtr node : nodes) {
		addNode(node);
	}
}
