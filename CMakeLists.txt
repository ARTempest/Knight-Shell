cmake_minimum_required(VERSION 3.10)
project(Knight-Shell)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(knight_shell
src/main.cpp
src/shell.cpp
src/lexer.cpp
)


