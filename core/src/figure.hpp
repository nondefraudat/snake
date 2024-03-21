#pragma once

struct SDL_Renderer;

class Figure {
public:
    virtual void render(SDL_Renderer* renderer) const noexcept;
};
