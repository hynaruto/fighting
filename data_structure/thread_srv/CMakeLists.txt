cmake_minimum_required(VERSION 3.15)
project(thread_srv)

set(CMAKE_CXX_STANDARD 14)

add_executable(thread_srv main.cpp tcpsocket.hpp)