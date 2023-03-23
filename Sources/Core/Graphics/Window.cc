#include <Core/Graphics/Window.hpp>
#include <GLFW/glfw3.h>
#include <cstdint>
#include <string_view>

using core::graphics::Window;

Window::Window(const std::string_view title, const uint32_t width,
               const uint32_t height) {
  this->window = glfwCreateWindow(width, height, title.data(), 0, 0);
}

Window::~Window() { glfwDestroyWindow(window); }