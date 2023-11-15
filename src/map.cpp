#include "map.hpp"

Map::Map(const size_t rowCount, const size_t colCount) noexcept
		: rowCount(rowCount), colCount(colCount), cellCount(rowCount*colCount) {
	for (size_t i = 0; i < cellCount; i++) {
		data.push_back(nullptr);
	}
}

size_t Map::getRowCount() const noexcept {
	return rowCount;
}

size_t Map::getColCount() const noexcept {
	return colCount;
}

NodePtr Map::getNode(const size_t row, const size_t col) const noexcept {
	if (row > rowCount || col > colCount) {
		return nullptr;
	}
	return data.at(row*colCount + col);
}

void Map::setNode(const size_t row, const size_t col, const NodePtr& node) noexcept {
	if (row > rowCount || col > colCount) {
		return;
	}
	data[row*colCount + col] = node;
}
