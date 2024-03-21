#pragma once

#include <gameboard.hpp>
#include <memory>
#include <list>
#include <random>

class Snake {
public:
    enum class Direction { Left, Right, Up, Down };

    Snake(std::shared_ptr<GameBoard> map) noexcept;
    bool setDirection(Direction direction) noexcept;
    bool move() noexcept;

private:
    size_t size = 3;
    Direction nextMove = Direction::Up;
    Direction lastMove = Direction::Up;
    std::shared_ptr<GameBoard> map;
    std::list<GameBoard::CellCoordinates> nodes;

    std::random_device randomDevice;
    std::default_random_engine engine;
    std::uniform_int_distribution<size_t> generator;
    
    bool isDirectionPossible(Direction direction) const noexcept;
    GameBoard::CellCoordinates defineNextHeadPosition() const noexcept;

    void respawnFood() noexcept;
    void raiseMove(const GameBoard::CellCoordinates& targetCell) noexcept;
    void normalMove(const GameBoard::CellCoordinates& targetCell) noexcept;
};
