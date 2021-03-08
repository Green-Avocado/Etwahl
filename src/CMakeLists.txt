cmake_minimum_required(VERSION 3.10)

include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_SOURCE_DIR}/dependencies/rtmidi)

file(GLOB COMMON_SRC *.cpp)
file(GLOB PLATFORM_SRC ${CMAKE_SYSTEM_NAME}/*.cpp)

add_executable(Etwahl ${COMMON_SRC} ${PLATFORM_SRC})

set(LINK_LIBRARIES rtmidi)

if(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    message(STATUS "Compiling for Linux...")
    set(LINK_LIBRARIES ${LINK_LIBRARIES} -lX11 -lXtst)
elseif(${CMAKE_SYSTEM_NAME} MATCHES "Windows")
    message(STATUS "Compiling for Windows...")
else()
    message(FATAL_ERROR "Unsupported operating system.")
endif()

target_link_libraries(${CMAKE_PROJECT_NAME} ${LINK_LIBRARIES})

