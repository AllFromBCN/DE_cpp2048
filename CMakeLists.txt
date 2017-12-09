cmake_minimum_required(VERSION 3.6)
project(headerTest)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp block.cpp map.cpp visual.cpp score.cpp)
add_executable(headerTest ${SOURCE_FILES})