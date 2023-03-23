#include "Core/Graphics/Window.hpp"
#include <GLFW/glfw3.h>
#include <Sask/Engine.hpp>
#include <stdexcept>

using core::graphics::Window;
using sask::Engine;
Engine::Engine() {
  if (!glfwInit()) {
    glfwTerminate();
    throw new std::runtime_error("Failed to initialize glfw!");
  }
}

Engine::~Engine() { glfwTerminate(); }

Window *Engine::CreateWindow(std::string_view title, int32_t width,
                             int32_t height) {
  return new Window(title, width, height);
}