#include <spdlog/spdlog.h>
#include <Sask/Core/Window.hpp>

using sask::core::Window;

void Window::Open()
{
  spdlog::debug("Creating window {} ({}x{})", this->title, this->width,
                this->height);


  this->glfwHandle = glfw::glfwCreateWindow(width, height, title.c_str(), 0, 0);
  glfw::glfwMakeContextCurrent(glfwHandle);
}

void Window::Close()
{
  glfw::glfwDestroyWindow(glfwHandle);
}