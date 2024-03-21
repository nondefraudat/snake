#include "snake.hpp"
#include <SDL.h>
#include <random>
#include <cassert>

Snake::Snake(std::shared_ptr<GameBoard> gameBoard) noexcept
        : gameBoard(gameBoard), engine(randomDevice()),
        generator(0, gameBoard->getSize() - 1),
        food(std::make_shared<Food>()) {
    auto gameBoardSize = gameBoard->getSize();
    Position pos = { gameBoardSize/2, gameBoardSize/2 };
    for (size_t i = 0; i < size; i++) {
        std::shared_ptr<Node> node = std::make_shared<Node>(pos);
        gameBoard->setFigure(pos, node);
        nodes.push_back(node);
        pos.col++;
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
    auto targetPos = defineNextHeadPosition();
    auto figure = gameBoard->getFigure(targetPos);
    if (std::dynamic_pointer_cast<Node>(figure)) {
        return false;
    }
    if (!figure) {
        normalMove(targetPos);
    }
    else if (figure == food) {
        raiseMove(targetPos);
        respawnFood();
    }
    lastMove = nextMove;
    return true;
}

Position Snake::defineNextHeadPosition() const noexcept {
    auto headPos = nodes.front()->getPos();
    auto mapSize = gameBoard->getSize();
    switch (nextMove) {
        case Direction::Left: {
            headPos.col = headPos.col == 0
                ? mapSize - 1
                : headPos.col - 1;
            break;
        }
        case Direction::Right: {
            headPos.col++;
            if (headPos.col == mapSize) {
                headPos.col = 0;
            }
            break;
        }
        case Direction::Up: {
            headPos.row = headPos.row == 0
                ? mapSize - 1
                : headPos.row - 1;
            break;
        }
        case Direction::Down: {
            headPos.row++;
            if (headPos.row == mapSize) {
                headPos.row = 0;
            }
            break;
        }
    }
    return headPos;
}

void Snake::respawnFood() noexcept {
    Position newFoodPosition;
    newFoodPosition.row = generator(engine);
    newFoodPosition.col = generator(engine);
    while (gameBoard->getFigure(newFoodPosition)) {
        newFoodPosition.row = generator(engine);
        newFoodPosition.col = generator(engine);
    }
    gameBoard->setFigure(newFoodPosition, food);
}

void Snake::raiseMove(const Position& targetCell) noexcept {
    auto node = std::make_shared<Node>(targetCell);
    nodes.push_front(node);
    gameBoard->setFigure(targetCell, node);
}

void Snake::normalMove(const Position& targetCell) noexcept {
    auto node = nodes.back();
    nodes.pop_back();
    gameBoard->setFigure(node->getPos(), nullptr);
    node->setPos(targetCell);
    nodes.push_front(node);
    gameBoard->setFigure(targetCell, node);
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

void Snake::Food::render(SDL_Renderer *renderer) const noexcept {
    SDL_Rect viewport;
    SDL_GetRenderViewport(renderer, &viewport);
    SDL_FRect renderRect = {
        0.f, 0.f,
        float(viewport.w), float(viewport.h)
    };
    assert(SDL_SetRenderDrawColor(renderer, 0xCA, 0xB0, 0x36, 0xFF) == 0);
    assert(SDL_RenderFillRect(renderer, &renderRect) == 0);
}

void Snake::Node::render(SDL_Renderer *renderer) const noexcept {
    SDL_Rect viewport;
    SDL_GetRenderViewport(renderer, &viewport);
    SDL_FRect renderRect = {
        0.f, 0.f,
        float(viewport.w), float(viewport.h)
    };                    
    assert(SDL_SetRenderDrawColor(renderer, 0x87, 0x76, 0x80, 0xFF) == 0);
    assert(SDL_RenderFillRect(renderer, &renderRect) == 0);
}
