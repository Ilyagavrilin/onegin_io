cmake_minimum_required(VERSION 3.20)
project(onegin)

set(CMAKE_CXX_STANDARD 14)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")

add_executable(onegin main.cpp main.h globals.h  io_files_funcs.cpp io_files_funcs.h wrapper.cpp wrapper.h qsort_cmp.cpp qsort_cmp.h)
