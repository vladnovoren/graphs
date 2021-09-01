cmake_minimum_required(VERSION 3.16.3 FATAL_ERROR)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${project_SOURCE_DIR}/cmake")

project(graphs VERSION 1.0)

add_executable(graphs src/main.cpp)

target_include_directories(graphs PUBLIC include/)

find_package(SDL2 REQUIRED)

include_directories(${SDL2_INCLUDE_DIR})

target_link_libraries(graphs ${SDL2_LIBRARIES})
