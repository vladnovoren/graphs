cmake_minimum_required(VERSION 3.16.3 FATAL_ERROR)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${project_SOURCE_DIR}/cmake")

project(graphs VERSION 1.0)

add_executable(graphs src/main.cpp src/graph.cpp src/geometry.cpp src/app.cpp src/list.cpp src/common.cpp)

add_executable(test src/test.cpp)

target_include_directories(graphs PUBLIC include/)

find_package(SDL2 REQUIRED)

include_directories(${SDL2_INCLUDE_DIR})

target_link_libraries(graphs ${SDL2_LIBRARIES})
target_link_libraries(test ${SDL2_LIBRARIES})
