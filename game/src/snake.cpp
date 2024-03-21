#include "snake.hpp"
#include <random>

Snake::Snake(std::shared_ptr<GameBoard> map) noexcept
        : map(map), engine(randomDevice()), generator(0, map->getSize()) {
    auto mapSize = map->getSize();
    GameBoard::CellCoordinates node = { mapSize/2, mapSize/2 };
    for (size_t i = 0; i < size; i++) {
        map->setCellContent(node, GameBoard::CellContent::Static);
        nodes.push_back(node);
        node.row++;
    }
    respawnFood();
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
    auto targetCell = defineNextHeadPosition();
    auto nextCellContent = map->getCellContent(targetCell);
    if (nextCellContent == GameBoard::CellContent::SnakeNode) {
        return false;
    }
    if (nextCellContent == GameBoard::CellContent::Food) {
        respawnFood();
        raiseMove(targetCell);
    }
    else if (nextCellContent == GameBoard::CellContent::None) {
        normalMove(targetCell);
    }
    lastMove = nextMove;
    return true;
}

GameBoard::CellCoordinates Snake::defineNextHeadPosition() const noexcept {
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

void Snake::respawnFood() noexcept {
    GameBoard::CellCoordinates newFoodPosition;
    newFoodPosition.row = generator(engine);
    newFoodPosition.column = generator(engine);
    while (map->getCellContent(newFoodPosition) != GameBoard::CellContent::None) {
        newFoodPosition.row = generator(engine);
        newFoodPosition.column = generator(engine);
    }
    map->setCellContent(newFoodPosition, GameBoard::CellContent::Food);
}

void Snake::raiseMove(const GameBoard::CellCoordinates& targetCell) noexcept {
    nodes.push_front(targetCell);
    map->setCellContent(targetCell, GameBoard::CellContent::SnakeNode);
}

void Snake::normalMove(const GameBoard::CellCoordinates& targetCell) noexcept {
    map->setCellContent(nodes.back(), GameBoard::CellContent::None);
    nodes.pop_back();
    nodes.push_front(targetCell);
    map->setCellContent(targetCell, GameBoard::CellContent::SnakeNode);
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
