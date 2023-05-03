project(keyboard-ninja)

cmake_minimum_required(VERSION 3.5.1)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror -Iinclude -I3rdparty -Icw-ip-211_keyboardninja")

include_directories(include)
include_directories(3rdparty)

set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build/lib)
add_library(game source/game.c source/lexer.c source/record.c source/menu.c)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build)
add_executable(${PROJECT_NAME} source/main.c)
target_link_libraries(${PROJECT_NAME} game)

add_executable(mytests test/main.c test/test.c)
target_link_libraries(mytests game)
