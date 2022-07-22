cmake_minimum_required(VERSION 3.21)

include(lib/pico-sdk/pico_sdk_init.cmake)
project(MPKeypad C CXX ASM)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 14)

pico_sdk_init()

add_subdirectory(src)