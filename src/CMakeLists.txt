cmake_minimum_required(VERSION 3.10)

include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_SOURCE_DIR}/include/${CMAKE_SYSTEM_NAME})
include_directories(${PROJECT_SOURCE_DIR}/dependencies/rtmidi)

file(GLOB COMMON_SRC *.cpp)
file(GLOB PLATFORM_SRC ${CMAKE_SYSTEM_NAME}/*.cpp)

add_executable(Etwahl ${COMMON_SRC} ${PLATFORM_SRC})

target_link_libraries(Etwahl PRIVATE rtmidi)

