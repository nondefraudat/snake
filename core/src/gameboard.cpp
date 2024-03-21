#include "gameboard.hpp"
#include <SDL.h>
#include <cassert>

GameBoard::GameBoard() noexcept {
    for (size_t i = 0; i < size*size; i++) {
        data[i] = CellContent::None;
    }
}

void GameBoard::render(SDL_Renderer* renderer) noexcept {
    SDL_Rect viewport;
    SDL_GetRenderViewport(renderer, &viewport);
    auto cellSize = float(viewport.w)/size;
    CellCoordinates cell = { 0, 0 };
    SDL_FRect rect = { 0.f, 0.f, cellSize, cellSize };
    for ( ; cell.row < size; cell.row++, rect.y += cellSize) {
        for ( cell.column = 0, rect.x = 0 ; cell.column < size;
                cell.column++, rect.x += cellSize) {
            auto content = getCellContent(cell);
            if (content == CellContent::None) {
                continue;
            }
            switch (content) {
                case CellContent::SnakeNode: {
                    SDL_SetRenderDrawColor(renderer, 0x87, 0x76, 0x80, 0xFF);
                    break;
                }
                case CellContent::Static: {
                    SDL_SetRenderDrawColor(renderer, 0x1A, 0x1A, 0x1A, 0xFF);
                    break;
                }
                case CellContent::Food: {
                    SDL_SetRenderDrawColor(renderer, 0xCA, 0xB0, 0x36, 0xFF);
                    break;
                }
            }
            assert(SDL_RenderFillRect(renderer, &rect) == 0);
        }
    }
}

size_t GameBoard::getSize() const noexcept {
    return size;
}

GameBoard::CellContent
GameBoard::getCellContent(const CellCoordinates &coordinates) const noexcept {
    if (coordinates.row >= size || coordinates.column >= size) {
        return CellContent::None;
    }
    return data[coordinates.row*size + coordinates.column];
}

bool GameBoard::setCellContent(const CellCoordinates &coordinates,
        CellContent content) noexcept {
    if (coordinates.row >= size || coordinates.column >= size) {
        return false;
    }
    data[coordinates.row*size + coordinates.column] = content;
    return true;
}