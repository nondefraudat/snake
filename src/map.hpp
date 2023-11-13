#pragma once

#include "cell.hpp"
#include <vector>

using MapPtr = std::shared_ptr<class Map>;

class Map {
public:
	Map(const size_t width, const size_t height) noexcept;

	size_t getWidth() const noexcept;
	size_t getHeight() const noexcept;

	CellPtr getCell(const size_t column, const size_t row) noexcept;

	void setCell(const size_t column, const size_t row, const CellPtr& cell) noexcept;

private:
	size_t width, height, cellCount;
	std::vector<CellPtr> cells;
};