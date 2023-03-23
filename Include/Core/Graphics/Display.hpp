#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_video.h>
#include <string>

namespace core::graphics {
class Display {
private:
  SDL_Window *Window;

public:
  Display(std::string Title, uint width, uint height);
};
} // namespace core::graphics