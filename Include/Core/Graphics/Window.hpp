#pragma once

#include <GLFW/glfw3.h>
#include <cstdint>
#include <numbers>
#include <string_view>

namespace core::graphics {
class Window {
private:
  GLFWwindow *window;

public:
  Window(std::string_view title, uint32_t width, uint32_t height);
  ~Window();
};
} // namespace core::graphics