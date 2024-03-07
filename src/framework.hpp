#include <SDL3/SDL.h>
#include <memory>

using Renderer = std::shared_ptr<SDL_Renderer>;
using Window = std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)>;
