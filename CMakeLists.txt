cmake_minimum_required (VERSION 3.27.0)

set (PROJECT_NAME Sask)
set (SRC src/app.c
	 src/draw.c
	 src/engine.c)
project (${PROJECT_NAME})

find_package(SDL2 REQUIRED)

add_library(${PROJECT_NAME}_SDL2 src/drivers/sdl2/video.c)
target_link_libraries(${PROJECT_NAME}_SDL2 SDL2)
target_include_directories(${PROJECT_NAME}_SDL2 PUBLIC ${SDL2_INCLUDE_DIRS})
target_include_directories(${PROJECT_NAME}_SDL2 PUBLIC inc)

add_library (${PROJECT_NAME} SHARED ${SRC})
target_include_directories(${PROJECT_NAME} PUBLIC inc)
target_link_libraries(${PROJECT_NAME} ${PROJECT_NAME}_SDL2)

add_subdirectory(examples/hello)