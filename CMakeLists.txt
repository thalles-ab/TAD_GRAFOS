cmake_minimum_required(VERSION 3.6)
project(TAD_Grafos)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.c src/headers/graph.h src/graph.c src/headers/list.h src/list.c)
add_executable(TAD_Grafos ${SOURCE_FILES})