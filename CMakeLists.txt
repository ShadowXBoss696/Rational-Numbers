cmake_minimum_required(VERSION 3.20)
project(Rational_Numbers C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

FILE(GLOB SRCS *.c)

add_executable(Rational_Numbers ${SRCS})
