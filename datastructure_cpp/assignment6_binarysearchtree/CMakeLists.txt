cmake_minimum_required(VERSION 3.13)
project(assignment6_binarysearchtree)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(assignment6_binarysearchtree
        assignment5.cc
        assignment5.h
        assignment6.cc
        assignment6.h
        assignment6main.cc)
