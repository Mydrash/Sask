cmake_minimum_required(VERSION 3.1...3.26)


configure_file(VertexShader.glsl VertexShader.glsl COPYONLY)
configure_file(FragmentShader.glsl FragmentShader.glsl COPYONLY)

add_executable(Game Game.cpp)
target_link_libraries(Game Sask) 