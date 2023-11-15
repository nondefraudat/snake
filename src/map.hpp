#pragma once

#include "node.hpp"
#include <vector>
#include <memory>

using MapPtr = std::shared_ptr<class Map>;

class Map {
public:
	Map(const size_t rowCount, const size_t colCount) noexcept;

	size_t getRowCount() const noexcept;
	size_t getColCount() const noexcept;
	NodePtr getNode(const size_t row, const size_t col) const noexcept;

	void setNode(const size_t row, const size_t col, const NodePtr& node) noexcept;

private:
	size_t rowCount, colCount, cellCount;
	std::vector<NodePtr> data;
};