cmake_minimum_required(VERSION 3.1)

set (CMAKE_CXX_STANDARD 20)
find_package(PkgConfig REQUIRED)

pkg_check_modules(GL REQUIRED IMPORTED_TARGET gl)
pkg_check_modules(GLFW REQUIRED IMPORTED_TARGET glfw3)
pkg_check_modules(GLEW REQUIRED IMPORTED_TARGET glew)

project (Sask)

add_library(Sask
          "Sources/Sask/Engine.cc"
          "Sources/Sask/Window.cc"
          "Sources/Sask/Renderer.cc"
          "Sources/Sask/Shader.cc"
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
target_link_libraries(Sask PRIVATE PkgConfig::GLFW)
target_link_libraries(Sask PRIVATE PkgConfig::GL)
target_link_libraries(Sask PRIVATE PkgConfig::GLEW)

target_include_directories(Sask PRIVATE ${GLFW3_INCLUDE_DIRS})
target_include_directories(Sask PRIVATE ${GLEW_INCLUDE_DIRS})

target_include_directories(Sask PUBLIC Include)
add_subdirectory(Examples/Hello)
