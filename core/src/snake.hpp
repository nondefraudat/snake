#pragma once

#include "gameboard.hpp"
#include <list>
#include <random>

class Snake {
public:
    enum class Direction { Left, Right, Up, Down };

    class Food : public Figure {
    public:
        void render(SDL_Renderer* renderer) const noexcept override;
    };
    
    class Node : public Figure {
    public:
        Node(const Position& pos) noexcept : pos(pos) {};
        void render(SDL_Renderer* renderer) const noexcept override;
        inline Position getPos() const noexcept { return pos; };
        inline void setPos(const Position& pos) noexcept { this->pos = pos; };

    private:
        Position pos;
    };

    Snake(std::shared_ptr<GameBoard> gameBoard) noexcept;
    bool setDirection(Direction direction) noexcept;
    bool move() noexcept;

private:
    size_t size = 3;
    Direction nextMove = Direction::Up;
    Direction lastMove = Direction::Up;
    std::shared_ptr<GameBoard> gameBoard;
    std::list<std::shared_ptr<Node>> nodes;
    std::shared_ptr<Food> food;

    std::random_device randomDevice;
    std::default_random_engine engine;
    
    bool isDirectionPossible(Direction direction) const noexcept;
    Position defineNextHeadPosition() const noexcept;

    void respawnFood() noexcept;
    void raiseMove(const Position& targetCell) noexcept;
    void normalMove(const Position& targetCell) noexcept;
};
