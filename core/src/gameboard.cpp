#include "gameboard.hpp"
#include <SDL.h>
#include <cassert>

GameBoard::GameBoard() noexcept {
    for (size_t i = 0; i < size*size; i++) {
        data[i] = nullptr;
    }
}

void GameBoard::render(SDL_Renderer* renderer) noexcept {
    SDL_Rect viewport;
    SDL_GetRenderViewport(renderer, &viewport);
    int cellSize = viewport.w/size;
    Position cell = { 0, 0 };
    SDL_Rect cellViewPort = { 0, 0, cellSize, cellSize };
    for ( ; cell.row < size; cell.row++, cellViewPort.y += cellSize) {
        for ( cell.col = 0, cellViewPort.x = 0 ; cell.col < size;
                cell.col++, cellViewPort.x += cellSize) {
            auto figure = getFigure(cell);
            if (!figure) {
                continue;
            }
            SDL_SetRenderViewport(renderer, &cellViewPort);
            figure->render(renderer);
        }
    }
    SDL_SetRenderViewport(renderer, &viewport);
}

size_t GameBoard::getSize() const noexcept {
    return size;
}

std::shared_ptr<Figure>
GameBoard::getFigure(const Position& pos) const noexcept {
    if (pos.row >= size || pos.col >= size) {
        return nullptr;
    }
    return data[pos.row*size + pos.col];
}

bool GameBoard::setFigure(const Position& pos,
        std::shared_ptr<Figure> content) noexcept {
    if (pos.row >= size || pos.col >= size) {
        return false;
    }
    data[pos.row*size + pos.col] = content;
    return true;
}
