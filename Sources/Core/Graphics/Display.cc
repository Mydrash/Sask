#include "SDL_video.h"
#include <Core/Graphics/Display.hpp>

using core::graphics::Display;

Display::Display(std::string Title, uint width, uint height) {
  this->Window = SDL_CreateWindow(Title.c_str(), SDL_WINDOWPOS_CENTERED,
                                  SDL_WINDOWPOS_CENTERED, width, height, 0);
}