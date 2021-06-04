cmake_minimum_required(VERSION 3.15)
project(tcp)

set(CMAKE_CXX_STANDARD 14)

add_executable(tcp tcp_srv.cpp tcpsocket.hpp tcp_cli.cpp)