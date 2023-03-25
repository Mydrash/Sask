#include "Core/Graphics/Window.hpp"
#include "Sask/Window.hpp"
#include <GLFW/glfw3.h>
#include <Sask/Engine.hpp>
#include <stdexcept>

using sask::Engine;
using sask::Window;

void GLFWErrorHandler(int error, const char *description) {
  fprintf(stderr, "GLFW Error: %s\n", description);
}

Engine::Engine() {
  if (!glfwInit()) {
    glfwTerminate();
    throw new std::runtime_error("Failed to initialize glfw!");
  }

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwSetErrorCallback(GLFWErrorHandler);
}

Engine::~Engine() { glfwTerminate(); }

Window *Engine::CreateWindow(const std::string_view title, const uint32_t width,
                             const uint32_t height) {
  return new Window(title, width, height);
}

void Engine::PollEvents() { glfwPollEvents(); }