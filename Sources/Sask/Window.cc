#include <GLFW/glfw3.h>
#include <Sask/Window.hpp>

using sask::Window;

void Window::MakeCurrent() {
  glfwMakeContextCurrent(this->wrappedWindow.window);
}

bool Window::ShouldClose() {
  return glfwWindowShouldClose(this->wrappedWindow.window);
}