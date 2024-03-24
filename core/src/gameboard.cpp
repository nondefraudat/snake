#include "gameboard.hpp"
#include <SDL.h>
#include <cassert>
#include <cmath>

GameBoard::GameBoard() noexcept {
    for (size_t i = 0; i < size.width*size.height; i++) {
        data[i] = nullptr;
    }
}

void GameBoard::render(SDL_Renderer* renderer) noexcept {
    SDL_Rect viewport;
    SDL_GetRenderViewport(renderer, &viewport);

    Position centerCellRenderOffset = {
        countCellCoord(viewport.h),
        countCellCoord(viewport.w)
    };

    Size renderPart = {
        countRenderSide(centerCellRenderOffset.col)*2 + 1,
        countRenderSide(centerCellRenderOffset.row)*2 + 1
    };

    Position renderStartCoord = {
        (viewport.h - renderPart.height*cellSize)/2,
        (viewport.w - renderPart.width*cellSize)/2
    };

    Position startCellPos {
        camera.row - countRenderSide(centerCellRenderOffset.row),
        camera.col - countRenderSide(centerCellRenderOffset.col)
    };

    SDL_Rect cellViewPort = {
        renderStartCoord.col,
        renderStartCoord.row,
        cellSize, cellSize
    };

    for (Position cell = startCellPos;
            cell.row < (startCellPos.row + renderPart.height);
            cell.row++, cellViewPort.y += cellSize) {
        for (cell.col = startCellPos.col,
                cellViewPort.x = renderStartCoord.col;
                cell.col < (startCellPos.col + renderPart.width);
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

int GameBoard::countCellCoord(float side) noexcept {
    return (side - cellSize)/2;
}

int GameBoard::countRenderSide(float side) noexcept {
    return std::ceilf(side/cellSize);
}
