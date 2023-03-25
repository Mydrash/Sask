#pragma once

#include <Sask/Renderer.hpp>
#include <Sask/Window.hpp>

namespace sask
{
  class Application
  {
   public:
    Window *window;
    unsigned int shaders;

    virtual void Setup() = 0;

    virtual void Update() = 0;

    virtual void Render(sask::Renderer render) = 0;
  };
}  // namespace sask