cmake_minimum_required(VERSION 3.10)
project(sb123456)

set(CMAKE_CXX_STANDARD 14)


include_directories(${PROJECT_SOURCE_DIR}}/libs)

add_subdirectory(main)
add_subdirectory(test)