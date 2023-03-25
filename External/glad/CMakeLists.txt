project (glad)


add_library(glad "src/gl.c" "include/glad/gl.h")

target_include_directories(glad PRIVATE "include")