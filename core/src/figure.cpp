#include "figure.hpp"
#include <SDL.h>
#include <cassert>

void Figure::render(SDL_Renderer* renderer) const noexcept {
    SDL_Rect viewport;
    SDL_GetRenderViewport(renderer, &viewport);
    SDL_FRect renderRect = {
        0.f, 0.f,
        float(viewport.w), float(viewport.h)
    };
    assert(SDL_SetRenderDrawColor(renderer, 0x1A, 0x1A, 0x1A, 0xFF) == 0);
    assert(SDL_RenderFillRect(renderer, &renderRect) == 0);
}
