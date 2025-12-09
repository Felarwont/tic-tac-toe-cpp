cmake_minimum_required(VERSION 3.10)

project(TicTacToe)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(TicTacToe
    src/Board.cpp
    src/main.cpp
    src/Game.cpp)