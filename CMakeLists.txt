cmake_minimum_required(VERSION 3.10)

project(Etwahl)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

add_subdirectory(src)
add_subdirectory(dependencies/rtmidi)

