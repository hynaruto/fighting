cmake_minimum_required(VERSION 3.15)
project(udp)

set(CMAKE_CXX_STANDARD 14)

add_executable(udp udp_srv.cpp udpsocket.hpp udp_cli.cpp)