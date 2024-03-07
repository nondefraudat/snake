#pragma once

#include "framework.hpp"
#include <memory>

class Application {
public:
    static Application& getInstance() noexcept;
    int execute() noexcept;

private:
    Window window;
    Renderer renderer;
    bool quit = false;

    Application() noexcept;

    void processEvents() noexcept;
    void updateWindow() noexcept;
    void processBeat() noexcept;

};
