cmake_minimum_required(VERSION 3.1)

set (CMAKE_CXX_STANDARD 20)
set (GLFW_VERSION 3.3.8)
set (GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set (GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set (GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

find_package(glfw3 ${GLFW_VERSION} QUIET)

if (NOT glfw3_FOUND)
  include(FetchContent)
  FetchContent_Declare(
    glfw3
    URL https://github.com/glfw/glfw/releases/download/${GLFW_VERSION}/glfw-${GLFW_VERSION}.zip
  )
  FetchContent_GetProperties(raylib)

   if (NOT raylib_POPULATED)
    set(FETCHCONTENT_QUIET NO)
    FetchContent_Populate(glfw3)
    add_subdirectory(${glfw3_SOURCE_DIR} ${glfw3_BINARY_DIR})
  endif()
endif() 

project (Sask)

add_library(Sask
          "Sources/Sask/Engine.cc"
          "Sources/Sask/Window.cc"
          "Sources/Sask/Renderer.cc"
          "Sources/Sask/Shader.cc"
          "Sources/Sask/ShaderContainer.cc"

          "Sources/Sask/VertexArray.cc"
          "Sources/Sask/Utils/Shader.cc"

          "Sources/Core/Graphics/Window.cc"
          "Include/Core/Graphics/Window.hpp"
          "Include/Core/Graphics/OpenGL.hpp"

          "Include/Sask/Engine.hpp"
          "Include/Sask/Renderer.hpp"
          "Include/Sask/VertexArray.hpp"
          "Include/Sask/Window.hpp")

set_target_properties(Sask PROPERTIES CXX_STANDARD 20)
target_compile_options(Sask PRIVATE -g -Wall)
target_link_libraries(Sask PRIVATE glfw)
target_link_libraries(Sask PRIVATE glad)

target_include_directories(Sask PRIVATE ${GLFW3_INCLUDE_DIRS})

target_include_directories(Sask PUBLIC Include)
target_include_directories(Sask PUBLIC External)

add_subdirectory(External/glad)
add_subdirectory(Examples/Hello)
