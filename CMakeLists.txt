cmake_minimum_required(VERSION 3.1...3.26)

set (CMAKE_CXX_STANDARD 20)

find_package(glfw3 REQUIRED)

project (Sask)

add_library(Sask
          "Sources/Sask/Engine.cc"
          "Sources/Sask/Window.cc"

          "Sources/Core/Graphics/Window.cc"
          "Include/Core/Graphics/Window.hpp"

          "Include/Sask/Engine.hpp"
          "Include/Sask/Window.hpp")

set_target_properties(Sask PROPERTIES CXX_STANDARD 20)
target_link_libraries(Sask PRIVATE glfw)
target_include_directories(Sask PRIVATE ${GLFW3_INCLUDE_DIRS})
target_include_directories(Sask PUBLIC Include)
add_subdirectory(Examples/Hello)
