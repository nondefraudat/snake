#pragma once

#include "map.hpp"
#include <memory>
#include <vector>

class Snake {
public:
    enum class Direction { Left, Right, Up, Down };

    Snake(std::shared_ptr<Map> map) noexcept;
    bool setDirection(Direction direction) noexcept;
    bool move() noexcept;

private:
    size_t size = 12;
    Direction nextMove = Direction::Up;
    Direction lastMove = Direction::Up;
    std::shared_ptr<Map> map;
    std::vector<Map::CellCoordinates> nodes;

    bool isDirectionPossible(Direction direction) const noexcept;
    Map::CellCoordinates defineNextHeadPosition() const noexcept;
};
