#include "Sask/Window.hpp"
#include <SDL.h>
#include <Sask/Engine.hpp>

namespace sask {
Engine::Engine() { SDL_Init(SDL_INIT_VIDEO); }
Engine::~Engine() { SDL_Quit(); }

Window Engine::CreateWindow(std::string_view Title, uint width, uint height) {
  return Window(Title, width, height);
}
} // namespace sask