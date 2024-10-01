cmake_minimum_required(VERSION 3.23)
project(fuac VERSION 0.0.1)
set(VENDOR "Arseny802")

set(CMAKE_CXX_STANDARD 20)

add_executable(fuac src/main.cpp)

add_subdirectory(deps)