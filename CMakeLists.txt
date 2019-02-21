cmake_minimum_required(VERSION 3.7)
project(union_find)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c unFind.c handy_list.c test.h)
add_executable(union_find ${SOURCE_FILES})