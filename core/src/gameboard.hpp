#pragma once
#include "figure.hpp"
#include "position.hpp"
#include <memory>
#include <array>

struct SDL_Renderer;

class GameBoard {
public:
    GameBoard() noexcept;
    void render(SDL_Renderer* renderer) noexcept;
    size_t getSize() const noexcept;
    std::shared_ptr<Figure> getFigure(
            const Position& pos) const noexcept;
    bool setFigure(const Position& pos,
            std::shared_ptr<Figure> content) noexcept;

private:
    static constexpr size_t size = 50;
    std::array<std::shared_ptr<Figure>, size*size> data;
};
