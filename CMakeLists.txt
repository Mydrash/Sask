cmake_minimum_required(VERSION 3.1)

set (CMAKE_CXX_STANDARD 20)
project (Sask)

set (GLFW_VERSION 3.3.8)
set (SPDLOG_VERSION 1.11.0)

include ("CMake/GLFW3.cmake")
include ("CMake/spdlog.cmake")

add_subdirectory("Core")
add_subdirectory("GL")
add_subdirectory("Examples/CoreSimpleWindow")