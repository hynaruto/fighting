cmake_minimum_required(VERSION 3.15)
project(DCList C)

set(CMAKE_C_STANDARD 99)

add_executable(DCList main.c DCList.c DCList.h)