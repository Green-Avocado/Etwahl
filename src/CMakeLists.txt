cmake_minimum_required(VERSION 3.10)

file(GLOB COMMON_SRC *.cpp)
file(GLOB PLATFORM_SRC ${CMAKE_SYSTEM_NAME}/*.cpp)

add_executable(Etwahl ${COMMON_SRC} ${PLATFORM_SRC} ${DEPENDS_SRC})

set(LINK_LIBRARIES)

if(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    message(STATUS "Compiling for Linux...")
    add_compile_options(-Wall -Wextra -pedantic -Werror)

    add_definitions(-D__LINUX_ALSA__)
    set(LINK_LIBRARIES ${LINK_LIBRARIES} -lX11 -lXtst)
    set(LINK_LIBRARIES ${LINK_LIBRARIES} -lasound -lpthread)

elseif(${CMAKE_SYSTEM_NAME} MATCHES "Windows")
    message(STATUS "Compiling for Windows...")

else()
    message(FATAL_ERROR "Unsupported operating system.")

endif()

target_link_libraries(${CMAKE_PROJECT_NAME} ${LINK_LIBRARIES})

