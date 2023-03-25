#include <GLFW/glfw3.h>
#include <Sask/Window.hpp>

using sask::Window;

void Window::MakeCurrent() {
  glfwMakeContextCurrent(this->wrappedWindow.window);
}

void Window::Flush() { glfwSwapBuffers(this->wrappedWindow.window); }

void Window::UpdateViewport() {
  int width, height;
  glfwGetFramebufferSize(this->wrappedWindow.window, &width, &height);
  glViewport(0, 0, width, height);
  glClear(GL_COLOR_BUFFER_BIT);
}

bool Window::IsKeyDown(int key) {
  return glfwGetKey(this->wrappedWindow.window, key) == GLFW_PRESS;
}