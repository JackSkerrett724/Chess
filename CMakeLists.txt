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
        src/cpp/Bishop.h
        src/cpp/Knight.cpp
        src/cpp/Knight.h
        src/cpp/Rook.cpp
        src/cpp/Rook.h
        src/cpp/Queen.cpp
        src/cpp/Queen.h
        src/cpp/King.cpp
        src/cpp/King.h
        src/cpp/Empty.cpp
        src/cpp/Empty.h
        src/cpp/Game.cpp
        src/cpp/Game.h
        src/cpp/Player.cpp
        src/cpp/Player.h)
