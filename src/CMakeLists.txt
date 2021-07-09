# Preamble
cmake_minimum_required(VERSION 3.19.2)
project(ZEN)

add_compile_options(-Wall -Wextra -pedantic -Werror)
include_directories(../lib/incbin)

add_executable(zen zen.c)
