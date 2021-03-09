cmake_minimum_required(VERSION 3.10)

file(GLOB COMMON_TESTS *.cpp)
file(GLOB PLATFORM_TESTS *.cpp)

add_executable(tests ${COMMON_TESTS} ${PLATFORM_TESTS})
target_link_libraries(tests ${LINK_LIBRARIES})

