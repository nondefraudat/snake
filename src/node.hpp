#pragma once

#include <memory>

using NodePtr = std::shared_ptr<class Node>;
using SnakeBodyPtr = std::shared_ptr<class SnakeBody>;

class Node {
public:
	Node(const double size = .5) noexcept;

	double getSize() const noexcept;
	void setSize(const double size) noexcept;

private:
	double size = .5;
};

class SnakeBody : public Node {
public:
	SnakeBody() noexcept = default;

	void setNextNode(const SnakeBodyPtr& node) noexcept;
	SnakeBodyPtr getNextNode() const noexcept;

private:
	SnakeBodyPtr nextNode = nullptr;
};
