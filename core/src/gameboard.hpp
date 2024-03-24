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
    
    Size getSize() const noexcept;
    std::shared_ptr<Figure>
    getFigure(const Position& pos) const noexcept;
    void setFigure(const Position& pos,
            std::shared_ptr<Figure> content) noexcept;
    void setCameraPos(const Position& pos) noexcept;

private:
    static constexpr int cellSize = 10;
    static constexpr int width = 500;
    static constexpr int height = 500;
    std::array<std::shared_ptr<Figure>,
            height*width> data;
    Position camera;

    static int countCellCoord(float side) noexcept;
    static int countRenderSide(float side) noexcept;

    static int translate(int value, int limit) noexcept;
    int translate(const Position& pos) const noexcept;    
};
