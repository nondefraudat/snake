#pragma once

#include "node.hpp"
#include <memory>
#include <list>

using SnakeNodePtr = std::shared_ptr<class SnakeNode>;

class SnakeNode : public Node {
public:
	SnakeNodePtr prev = nullptr, next = nullptr;

	SnakeNode(const size_t row = 0, const size_t col = 0,
			SnakeNodePtr prev = nullptr,
			SnakeNodePtr next = nullptr) noexcept
			: Node(row, col), prev(prev), next(next) { }
};

class Snake {
public:
	Snake(const size_t size) noexcept;

	void setPos(const size_t row, const size_t col) noexcept;
	void move(const int rowOffset, const int colOffset) noexcept;

	std::list<NodePtr> getNodes() const noexcept;

private:
	SnakeNodePtr head, tail;
};