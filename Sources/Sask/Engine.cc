#include "Core/Graphics/Window.hpp"
#include "Sask/Window.hpp"
#include <GLFW/glfw3.h>
#include <Sask/Engine.hpp>
#include <stdexcept>

using sask::Engine;
using sask::Window;

Engine::Engine() {
  if (!glfwInit()) {
    glfwTerminate();
    throw new std::runtime_error("Failed to initialize glfw!");
  }
}

Engine::~Engine() { glfwTerminate(); }

Window *Engine::CreateWindow(const std::string_view title, const uint32_t width,
                             const uint32_t height) {
  return new Window(title, width, height);
}

void Engine::PollEvents() { glfwPollEvents(); }