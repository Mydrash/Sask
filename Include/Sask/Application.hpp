#pragma once

#include <Sask/Renderer.hpp>
#include <Sask/Window.hpp>

namespace sask
{
  class Application
  {
   public:
    Window *window;

    virtual void Setup() = 0;

    virtual void Update(){};

    virtual void Render(sask::Renderer render) = 0;
  };
}  // namespace sask