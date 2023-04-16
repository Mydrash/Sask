add_library(SaskCore SHARED
  "Sources/Sask/Core/Window.cc"
  "Include/Sask/Core/Window.hpp")

target_include_directories(SaskCore PUBLIC "Include")
set_target_properties(SaskCore PROPERTIES CXX_STANDARD 20)
target_compile_options(SaskCore PRIVATE -Wall)
target_link_libraries(SaskCore SaskGL spdlog)