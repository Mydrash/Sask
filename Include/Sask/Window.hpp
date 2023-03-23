#pragma once

#include <Core/Graphics/Window.hpp>
#include <cstdint>
#include <string_view>
namespace sask {
class Window {
private:
  core::graphics::Window wrappedWindow;

public:
  Window(std::string_view title, uint32_t width, uint32_t height)
      : wrappedWindow(title, width, height) {}
  ~Window();

  void MakeCurrent();
  bool ShouldClose();
};
} // namespace sask