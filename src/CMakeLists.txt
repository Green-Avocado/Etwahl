cmake_minimum_required(VERSION 3.10)

add_executable(Etwahl etwahl.cpp)

include_directories(${Etwahl_SOURCE_DIR}/include)
include_directories(${Etwahl_SOURCE_DIR}/dependencies/rtmidi)

target_link_libraries(Etwahl PRIVATE rtmidi)

