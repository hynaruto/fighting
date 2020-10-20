cmake_minimum_required(VERSION 3.15)
project(Contact)

set(CMAKE_CXX_STANDARD 14)

add_executable(Contact test.cpp Contact.h Contact.cpp)