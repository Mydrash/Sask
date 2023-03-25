#include <Core/Graphics/Window.hpp>
#include <GLFW/glfw3.h>
#include <Sask/Application.hpp>
#include <Sask/Engine.hpp>
#include <Sask/Window.hpp>
#include <cstddef>
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
  auto window = new Window(title, width, height);
  window->MakeCurrent();

  return window;
}

void Engine::PollEvents() { glfwPollEvents(); }

void Engine::Run(Application *app) {
  app->Setup();
  if (app->window == nullptr) {
    throw std::runtime_error("window must be not null!");
  }

  while (!app->window->shouldClose) {
    app->Update();
    app->window->UpdateViewport();

    app->Render(this->Renderer);

    app->window->Flush();
    this->PollEvents();
  }
}