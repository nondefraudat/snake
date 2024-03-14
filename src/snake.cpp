#include "snake.hpp"

Snake::Snake(std::shared_ptr<Map> map) noexcept : map(map) {
    nodes.reserve(100);
    auto mapSize = map->getSize();
    Map::CellCoordinates node = { mapSize/2, mapSize/2 };
    for (size_t i = 0; i < size; i++) {
        map->setCellContent(node, Map::CellContent::Static);
        nodes.push_back(node);
        node.row++;
    }
}

bool Snake::setDirection(Direction direction) noexcept {
    if (isDirectionPossible(direction)) {
        nextMove = direction;
        return true;
    }
    nextMove = lastMove;
    return false;
}

bool Snake::move() noexcept {
    auto prevNode = defineNextHeadPosition();
    for (auto& node : nodes) {
        auto nodeBuffer = node;
        if (node.row == prevNode.row) {
            node.column = prevNode.column;
        }
        else {
            node.row = prevNode.row;
        }
        map->setCellContent(node, Map::CellContent::SnakeNode);
        prevNode = nodeBuffer;
    }
    map->setCellContent(prevNode, Map::CellContent::None);
    lastMove = nextMove;
    return true;
}

Map::CellCoordinates Snake::defineNextHeadPosition() const noexcept {
    auto head = nodes.front();
    auto mapSize = map->getSize();
    switch (nextMove) {
        case Direction::Left: {
            head.column = head.column == 0
                ? mapSize - 1
                : head.column - 1;
            break;
        }
        case Direction::Right: {
            head.column++;
            if (head.column == mapSize) {
                head.column = 0;
            }
            break;
        }
        case Direction::Up: {
            head.row = head.row == 0
                ? mapSize - 1
                : head.row - 1;
            break;
        }
        case Direction::Down: {
            head.row++;
            if (head.row == mapSize) {
                head.row = 0;
            }
            break;
        }
    }
    return head;
}

bool Snake::isDirectionPossible(Direction direction) const noexcept {
    if (
            (direction == Direction::Left &&
                    lastMove == Direction::Right) ||
            (direction == Direction::Right &&
                    lastMove == Direction::Left) ||
            (direction == Direction::Up &&
                    lastMove == Direction::Down) ||
            (direction == Direction::Down &&
                    lastMove == Direction::Up)) {
        return false;
    }
    return true;
}
