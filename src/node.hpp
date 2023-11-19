#pragma once

#include <memory>

using NodePtr = std::shared_ptr<struct Node>;

class Node {
public:
	size_t row, col;

	Node(const size_t row = 0, const size_t col = 0) noexcept
			: row(row), col(col) { }
};
