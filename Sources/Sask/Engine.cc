#include <Core/Graphics/OpenGL.hpp>
#include <Core/Graphics/Window.hpp>

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
  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LESS);
}

Engine::~Engine() { glfwTerminate(); }

Window *Engine::CreateWindow(const std::string_view title, const uint32_t width,
                             const uint32_t height) {
  auto window = new Window(title, width, height);
  window->MakeCurrent();

  GLenum glewStatus = glewInit();
  if (glewStatus != GLEW_OK) {
    throw std::runtime_error(
        "unable to initialize glew: " +
        (std::string((char *)glewGetErrorString(glewStatus))));
  }

  return window;
}

void Engine::PollEvents() { glfwPollEvents(); }

void Engine::Run(Application *app) {
  app->shaders = glCreateProgram();

  app->Setup();
  glLinkProgram(app->shaders);

  if (app->window == nullptr) {
    throw std::runtime_error("window must be not null!");
  }

  while (!app->window->shouldClose) {
    app->Update();
    app->window->UpdateViewport();

    glUseProgram(app->shaders);
    app->Render(this->Renderer);

    app->window->Flush();
    this->PollEvents();
  }
}