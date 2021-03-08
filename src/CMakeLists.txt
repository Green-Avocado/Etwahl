cmake_minimum_required(VERSION 3.10)

include_directories(${Etwahl_SOURCE_DIR}/include)
include_directories(${Etwahl_SOURCE_DIR}/dependencies/rtmidi)
add_executable(Etwahl etwahl.cpp)
target_link_libraries(Etwahl rtmidi)

