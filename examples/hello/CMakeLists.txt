cmake_minimum_required (VERSION 3.27.0)

project(SaskHelloExample)


add_executable(SaskHello hello.c)
target_link_libraries(SaskHello Sask)