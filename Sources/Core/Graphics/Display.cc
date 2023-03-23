#include "SDL_video.h"
#include <Core/Graphics/Display.hpp>

using core::graphics::Display;

Display::Display(std::string_view title, uint width, uint height) {
  this->Window = SDL_CreateWindow(title.data(), SDL_WINDOWPOS_CENTERED,
                                  SDL_WINDOWPOS_CENTERED, width, height, 0);
}

Display::~Display() { SDL_DestroyWindow(Window); }