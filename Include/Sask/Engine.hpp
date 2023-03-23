#pragma once
#include <Sask/Window.hpp>
#include <string_view>

namespace sask {
class Engine {
public:
  Engine();
  ~Engine();

  Window CreateWindow(std::string_view Title, uint width, uint height);
};
} // namespace sask