#include "node.hpp"

Node::Node(const double size) noexcept
		: size(size) { }

double Node::getSize() const noexcept {
	return size;
}

void Node::setSize(const double size) noexcept {
	this->size = size;
}

void SnakeBody::setNextNode(const SnakeBodyPtr& node) noexcept {
	nextNode = node;
}

SnakeBodyPtr SnakeBody::getNextNode() const noexcept {
	return nextNode;
}
