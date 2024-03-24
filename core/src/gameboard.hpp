#pragma once
#include "figure.hpp"
#include "position.hpp"
#include "size.hpp"
#include <memory>
#include <array>

struct SDL_Renderer;
struct SDL_Rect;

class GameBoard {
public:
    GameBoard() noexcept;
    
    void render(SDL_Renderer* renderer) noexcept;
    
    inline Size getSize() const noexcept {
        return size;
    }
    inline std::shared_ptr<Figure> getFigure(
            const Position& pos) const noexcept {
        return data[translate(pos)];
    }
    inline void setFigure(const Position& pos,
            std::shared_ptr<Figure> content) noexcept {
        data[translate(pos)] = content;
    }
    inline void setCameraPos(const Position& pos) noexcept {
        camera = pos;
    }

private:
    static constexpr int cellSize = 10;
    static constexpr Size size = { 150, 150 };
    std::array<std::shared_ptr<Figure>,
            size.height*size.width> data;
    Position camera;

    static int countCellCoord(float side) noexcept;
    static int countRenderSide(float side) noexcept;

    inline static int
    translate(int value, int limit) noexcept {
        value %= limit;
        return value < 0 ? limit + value : value;
    }
    inline int translate(const Position& pos) const noexcept {
        return (translate(pos.row, size.height)*size.width +
                translate(pos.col, size.width));
    }
    
};
