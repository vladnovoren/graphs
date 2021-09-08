cmake_minimum_required(VERSION 3.16.3 FATAL_ERROR)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${project_SOURCE_DIR}/cmake")

project(graphs VERSION 1.0)


set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

add_executable(graphs src/main.cpp src/geometry.cpp src/plotter.cpp src/app.cpp)


target_include_directories(graphs PUBLIC include/)

find_package(SDL2 REQUIRED)

find_package(SDL2_gfx REQUIRED)

include_directories(${SDL2_INCLUDE_DIR})

target_link_libraries(graphs ${SDL2_LIBRARIES} ${SDL2_GFX_LIBRARY})
