#pragma once
#include <Core/Utils/Alias.hpp>
#include <Sask/Application.hpp>
#include <Sask/Engine.hpp>
#include <Sask/Keys.hpp>
#include <Sask/Renderer.hpp>
#include <Sask/ShaderContainer.hpp>
#include <Sask/VertexArray.hpp>
#include <Sask/Window.hpp>
#include <cstdint>
#include <functional>
#include <string>
#include <string_view>

namespace sask
{

  class Engine
  {
   public:
    Engine();
    ~Engine();
    sask::Renderer Renderer;

    Window *CreateWindow(std::string_view title, uint32_t width,
                         uint32_t height);
    void PollEvents();

    void Run(Application *app);
  };
}  // namespace sask