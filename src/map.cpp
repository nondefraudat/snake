#include "map.hpp"

Map::Map(const size_t width, const size_t height) noexcept 
		: width(width), height(height), cellCount(width*height) {
	for (int i = 0; i < cellCount; i++) {
		cells.push_back(nullptr);
	}
}

size_t Map::getWidth() const noexcept {
	return width;
}

size_t Map::getHeight() const noexcept {
	return height;
}

CellPtr Map::getCell(const size_t column, const size_t row) noexcept {
	if (column > width || row > height) {
		return nullptr;
	}
	return cells[column*height + row];
}

void Map::setCell(const size_t column, const size_t row, const CellPtr& cell) noexcept {
	if (column > width || row > height) {
		return;
	}
	cells[column * height + row] = cell;
}
