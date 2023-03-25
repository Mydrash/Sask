#pragma once

#include <Core/Graphics/Window.hpp>
#include <cstdint>
#include <memory>
#include <string_view>

namespace sask {
class Window {
private:
  core::graphics::Window wrappedWindow;

public:
  bool shouldClose = false;

  Window(std::string_view title, uint32_t width, uint32_t height)
      : wrappedWindow(title, width, height) {}
  ~Window();

  void MakeCurrent();
  void Flush();
  void UpdateViewport();
  bool IsKeyDown(int key);

  std::unique_ptr<std::string> GetRenderer();
  std::unique_ptr<std::string> GetOpenGLVersion();
};
} // namespace sask