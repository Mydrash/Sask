#pragma once
#include <cstdint>

namespace glfw
{
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
}  // namespace glfw

namespace gl
{
  using std::uint32_t;
#include <GL.h>
}  // namespace gl