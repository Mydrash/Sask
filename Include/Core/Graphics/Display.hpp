#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_video.h>
#include <string>

namespace core::graphics {
class Display {
private:
  SDL_Window *Window;

public:
  Display(std::string_view Title, uint width, uint height);
  ~Display();
};
} // namespace core::graphics