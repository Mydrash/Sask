#include <Core/Graphics/Window.hpp>
#include <cstdint>
#include <stdexcept>
#include <string_view>

using core::graphics::Window;

Window::Window(const std::string_view title, const uint32_t width,
               const uint32_t height)
{
  this->window = glfwCreateWindow(width, height, title.data(), 0, 0);

  if (this->window == nullptr)
  {
    throw std::runtime_error("unable to create glfw window!");
  }
}

Window::~Window()
{
  glfwDestroyWindow(window);
}