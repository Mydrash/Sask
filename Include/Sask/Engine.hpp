#pragma once

#include <Core/Graphics/Window.hpp>
#include <cstdint>
#include <string>
#include <string_view>
namespace sask {
class Engine {
public:
  Engine();
  ~Engine();

  core::graphics::Window *CreateWindow(std::string_view title, int32_t width,
                                       int32_t height);
};
} // namespace sask