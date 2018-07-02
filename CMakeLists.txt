cmake_minimum_required(VERSION 3.10)
project(sb123456)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS_RELEASE  "${CMAKE_CXX_FLAGS} -pthread -fPIC -O2 -DLINUX -Wall -fsigned-char -DOPT_TIMER")
set(CMAKE_CXX_FLAGS_DEBUG   "${CMAKE_CXX_FLAGS} -pthread -fPIC -O2 -Wall -fsigned-char -lgtest")


include_directories(${PROJECT_SOURCE_DIR}/libs)

add_subdirectory(main)
add_subdirectory(test)