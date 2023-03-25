#pragma once

#include <Core/Graphics/OpenGL.hpp>
#include <cstdint>
#include <numbers>
#include <string_view>

namespace core::graphics {
class Window {
public:
  GLFWwindow *window;

  Window(const std::string_view title, const uint32_t width,
         const uint32_t height);
  ~Window();
};
} // namespace core::graphics