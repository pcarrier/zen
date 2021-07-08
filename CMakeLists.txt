# Preamble
cmake_minimum_required(VERSION 3.19.2)
project(ZEN)

add_compile_options(-Wall -Wextra -pedantic -Werror)
include_directories(lib/incbin)

add_executable(zen src/zen.c)

include(FindPkgConfig)
pkg_search_module(SDL2 REQUIRED sdl2)
pkg_search_module(SDL2TTF REQUIRED SDL2_ttf)

link_directories(
        ${SDL2_LIBRARY_DIRS}
        ${SDL2TTF_LIBRARY_DIRS})

include_directories(
        ${SDL2_INCLUDE_DIRS}
        ${SDL2TTF_INCLUDE_DIRS})

target_link_libraries(zen
        ${SDL2_STATIC_LIBRARIES}
        ${SDL2TTF_STATIC_LIBRARIES})
