cmake_minimum_required(VERSION 4.1)
project(untitled9 C)

set(CMAKE_C_STANDARD 11)

add_executable(untitled9 main.c)

find_package(SDL2 REQUIRED)
target_link_libraries(untitled9 ${SDL2_LIBRARIES} m)
#target_link_libraries(untitled9 ${math.h} m)