cmake_minimum_required(VERSION 3.25)
project(Cube_3)

set(CMAKE_C_STANDARD 11)

file(GLOB ALL_SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/*.c
)

add_executable(Cube_3 ${ALL_SOURCES})
