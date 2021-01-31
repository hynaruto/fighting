cmake_minimum_required(VERSION 3.15)
project(Heap C)

set(CMAKE_C_STANDARD 99)

add_executable(Heap main.c Heap.h Heap.c)