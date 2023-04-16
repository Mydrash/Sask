# Single library to manage OpenGL Contexts
add_library(SaskGL INTERFACE "Include/SaskGL/GL.hpp")

target_link_libraries(SaskGL INTERFACE glfw)
target_include_directories(SaskGL INTERFACE "Include")
target_include_directories(SaskGL INTERFACE "Glad")
target_include_directories(SaskGL INTERFACE ${GLFW_INCLUDE_DIRS})