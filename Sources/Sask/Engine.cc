#include "Sask/Window.hpp"
#include <SDL.h>
#include <Sask/Engine.hpp>

namespace sask {
Engine::Engine() { SDL_Init(SDL_INIT_VIDEO); }
Engine::~Engine() { SDL_Quit(); }

Window *Engine::CreateWindow(std::string_view title, uint width, uint height) {
  return new Window(title, width, height);
}
} // namespace sask