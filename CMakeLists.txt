cmake_minimum_required(VERSION 3.1...3.26)

set (CMAKE_CXX_STANDARD 20)

project (Sask)
find_package(SDL2 REQUIRED)

add_library(Sask 
          "Sources/Sask/Engine.cc"
          "Sources/Core/Graphics/Display.cc"

          "Include/Core/Graphics/Display.hpp"
          "Include/Sask/Engine.hpp")

set_target_properties(Sask PROPERTIES CXX_STANDARD 20)
target_link_libraries(Sask PRIVATE ${SDL2_LIBRARIES})
target_include_directories(Sask PRIVATE ${SDL2_INCLUDE_DIRS})
target_include_directories(Sask PUBLIC Include)
add_subdirectory(Examples/Hello)
