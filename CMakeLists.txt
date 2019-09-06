cmake_minimum_required(VERSION 3.14)
project(can_bus C)

set(CMAKE_C_STANDARD 99)

add_executable(can_bus main.c func.h func.c)