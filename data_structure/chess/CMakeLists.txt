cmake_minimum_required(VERSION 3.15)
project(chess)

set(CMAKE_CXX_STANDARD 98)

add_executable(chess main.cpp chess.cpp chess.h)