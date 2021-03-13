cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(Etwahl)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)



include_directories(include)
include_directories(third_party/rtmidi)
include_directories(third_party/catch2)



add_library(RtMidi third_party/rtmidi/RtMidi.cpp)



set(LINK_LIBRARIES RtMidi)

add_compile_options(-Wall -Wextra -pedantic -Werror)
add_compile_options(-static)



if(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    message(STATUS "Compiling for Linux...")

    add_definitions(-D__LINUX_ALSA__)
    set(LINK_LIBRARIES ${LINK_LIBRARIES} -lX11 -lXtst)
    set(LINK_LIBRARIES ${LINK_LIBRARIES} -lasound -lpthread)

elseif(${CMAKE_SYSTEM_NAME} MATCHES "Windows")
    message(STATUS "Compiling for Windows...")
    set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++ -static")
    set(CMAKE_CXX_STANDARD_LIBRARIES "-static-libgcc -static-libstd++ ${CMAKE_CXX_STANDARD_LIBRARIES}")

    if(MINGW)
        set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} 
            -Wl,-Bstatic,--whole-archive -lwinpthread -Wl,--no-whole-archive")
    endif()


    add_definitions(-D__WINDOWS_MM__)
    set(LINK_LIBRARIES ${LINK_LIBRARIES} -lwinmm)

else()
    message(FATAL_ERROR "Unsupported operating system.")

endif()



add_subdirectory(src)
add_subdirectory(tests)

