#include <SDL.h>
#include <Sask/Engine.hpp>

namespace sask {
void Init() { SDL_Init(SDL_INIT_VIDEO); }
} // namespace sask