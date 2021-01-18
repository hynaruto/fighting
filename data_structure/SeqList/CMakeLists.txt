cmake_minimum_required(VERSION 3.15)
project(SeqList C)

set(CMAKE_C_STANDARD 99)

add_executable(SeqList main.c SeqList.h SeqList.c)