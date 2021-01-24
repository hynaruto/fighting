cmake_minimum_required(VERSION 3.15)
project(SList C)

set(CMAKE_C_STANDARD 99)

add_executable(SList main.c SList.h SList.c)