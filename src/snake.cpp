#include "snake.hpp"

using namespace std;

Snake::Snake(const size_t size) noexcept {
	SnakeNodePtr node = head = make_shared<SnakeNode>(0, 0);
	for (int i = 0; i < size; i++) {
		node->next = make_shared<SnakeNode>(node->col + 1, node->row, node);
		node = node->next;
	}
	tail = node;
}

void Snake::setPos(const size_t row, const size_t col) noexcept {
	SnakeNodePtr node = tail;
	while (node != head) {
		node->row = node->prev->row;
		node->col = node->prev->col;
		node = node->prev;
	}
	node->row = row;
	node->col = col;
}

void Snake::move(const int rowOffset, const int colOffset) noexcept {
	SnakeNodePtr node = tail;
	while (node != head) {
		node->row = node->prev->row;
		node->col = node->prev->col;
		node = node->prev;
	}
	node->row += rowOffset;
	node->col += colOffset;
}

std::list<NodePtr> Snake::getNodes() const noexcept {
	std::list<NodePtr> nodes;
	SnakeNodePtr node = head;
	while (node) {
		nodes.push_back(node);
		node = node->next;
	}
	return nodes;
}
