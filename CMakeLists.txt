cmake_minimum_required(VERSION 3.27)
project(ai_test_coverage C)

set(CMAKE_C_STANDARD 11)

add_executable(ai_test_coverage main.c calculator.c)
