#pragma once

#include "Sask/Window.hpp"
#include <Sask/Renderer.hpp>

namespace sask {
class Application {
public:
  Window *window;

  virtual void Update() = 0;

  virtual void Render(sask::Renderer render) = 0;
};
} // namespace sask