cmake_minimum_required(VERSION 3.10)

file(GLOB COMMON_SRC *.cpp)
file(GLOB PLATFORM_SRC ${CMAKE_SYSTEM_NAME}/*.cpp)

add_executable(Etwahl ${COMMON_SRC} ${PLATFORM_SRC})
target_link_libraries(Etwahl ${LINK_LIBRARIES})

