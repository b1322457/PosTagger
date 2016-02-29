cmake_minimum_required(VERSION 3.3)
project(PosTagger)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    README.md)

add_executable(PosTagger ${SOURCE_FILES})