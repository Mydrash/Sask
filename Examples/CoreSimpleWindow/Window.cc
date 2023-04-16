
#include <spdlog/spdlog.h>

#include <Sask/Core/Window.hpp>

int main(void)
{
  glfw::glfwInit();
  spdlog::set_level(spdlog::level::debug);

  spdlog::info("Starting Example");

  sask::core::Window handle("bom dia", 800, 600);

  handle.Open();
  handle.Close();

  glfw::glfwTerminate();

  return 0;
}
