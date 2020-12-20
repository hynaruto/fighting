cmake_minimum_required(VERSION 3.15)
project(new_contact C)

set(CMAKE_C_STANDARD 99)

add_executable(new_contact main.c new_contact.h new_contact.c)