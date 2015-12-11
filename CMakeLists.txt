cmake_minimum_required(VERSION 3.3)
project(Exercise_4)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
include_directories(headers)
set(HEADER_FILES headers)


set(SOURCE_FILES src/main.cpp src/Cinema.cpp src/Actor.cpp src/AgeCompare.cpp
        src/CntrCompare.cpp src/Director.cpp src/IDCompare.cpp src/Inputs.cpp
        src/Movie.cpp src/Producer.cpp src/Professionals.cpp src/Screenwriter.cpp)

add_executable(Exercise_4 ${SOURCE_FILES})