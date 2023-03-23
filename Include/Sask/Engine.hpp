#pragma once
#include <Sask/Window.hpp>
#include <cstdint>
#include <string>
#include <string_view>

namespace sask {
class Engine {
public:
  Engine();
  ~Engine();

  Window *CreateWindow(std::string_view title, uint32_t width, uint32_t height);
  void PollEvents();
};
} // namespace sask