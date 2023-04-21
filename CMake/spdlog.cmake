
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
include(FetchContent)
FetchContent_Declare(
  spdlog
  URL https://github.com/gabime/spdlog/archive/refs/tags/v${SPDLOG_VERSION}.zip
)

FetchContent_GetProperties(spdlog)

if (NOT spdlog_POPULATED)
  set(FETCHCONTENT_QUIET NO)
  FetchContent_Populate(spdlog)
  add_subdirectory(${spdlog_SOURCE_DIR})
endif()