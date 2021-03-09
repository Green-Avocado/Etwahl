cmake_minimum_required(VERSION 3.10)

project(Etwahl)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

include_directories(include)
include_directories(dependencies/rtmidi)

file(GLOB RTMIDI_SRC dependencies/rtmidi/RtMidi.cpp)
set(DEPENDS_SRC ${RTMIDI_SRC})

add_subdirectory(src)

