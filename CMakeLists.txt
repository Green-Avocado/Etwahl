cmake_minimum_required(VERSION 3.10)

project(Etwahl)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

include_directories(include)
include_directories(third_party/rtmidi)

file(GLOB RTMIDI_SRC third_party/rtmidi/RtMidi.cpp)
set(DEPENDS_SRC ${RTMIDI_SRC})

add_subdirectory(src)

