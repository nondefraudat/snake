#pragma once

#include "framework.hpp"
#include "shape.hpp"

class Map : public Shape {
public:
    Map() noexcept;

    virtual void render(Renderer renderer) noexcept override;

private:

};
