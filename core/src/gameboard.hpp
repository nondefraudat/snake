#pragma once
#include <array>

struct SDL_Renderer;

class GameBoard {
public:
    enum class CellContent { None = 0, Static, Movable, Food, SnakeNode };
    struct CellCoordinates {
        size_t row; size_t column;
    };

    GameBoard() noexcept;
    void render(SDL_Renderer* renderer) noexcept;
    size_t getSize() const noexcept;
    CellContent getCellContent(
            const CellCoordinates& coordinates) const noexcept;
    bool setCellContent(const CellCoordinates& coordinates,
            CellContent content) noexcept;

private:
    static constexpr size_t size = 50;
    std::array<CellContent, size*size> data;
};
