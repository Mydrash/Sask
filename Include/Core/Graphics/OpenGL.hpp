#pragma once

#define GLFW_INCLUDE_NONE
#include <glad/include/glad/gl.h>

#if defined(BUILDING_LIB)
#include <GLFW/glfw3.h>
#else
#define GLFWwindow int*
#endif
