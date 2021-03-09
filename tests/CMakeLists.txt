cmake_minimum_required(VERSION 3.10)

set(CONFIG_TEST configTest.cpp ${PROJECT_SOURCE_DIR}/src/config.cpp)

set(ALL_TESTS ${CONFIG_TEST})

add_executable(tests tests.cpp ${ALL_TESTS})
target_link_libraries(tests ${LINK_LIBRARIES})

