cmake_minimum_required(VERSION 3.12)
set(TARGET_NAME boilerplate)
project(${TARGET_NAME})

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")

find_package(SDL2 REQUIRED)

add_executable(${TARGET_NAME} src/main.cpp)

target_include_directories(${TARGET_NAME} SYSTEM PRIVATE ${SDL2_INCLUDE_DIR})
target_link_libraries(${TARGET_NAME} PRIVATE ${SDL2_LIBRARY})
