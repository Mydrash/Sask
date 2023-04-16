#pragma once
#include <SaskGL/GL.hpp>
#include <cstdint>
#include <string>

namespace sask::core
{
  class Window
  {
   private:
    glfw::GLFWwindow *glfwHandle;

   public:
    std::string title;
    std::uint32_t width, height;
    Window(std::string title, std::uint32_t width, std::uint32_t height)
        : title(title), width(width), height(height)
    {
    }

    void Open();
    void Close();
  };
}  // namespace sask::core