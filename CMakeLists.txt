cmake_minimum_required(VERSION 3.29)
project(Chess)

set(CMAKE_CXX_STANDARD 14)

include_directories(src/cpp)

add_executable(Chess
    src/cpp/Board.cpp
    src/cpp/Board.h
    src/cpp/Chess.cpp
        src/cpp/Piece.cpp
        src/cpp/Piece.h
        src/cpp/Pawn.cpp
        src/cpp/Pawn.h
        src/cpp/Bishop.cpp
        src/cpp/Bishop.h)
