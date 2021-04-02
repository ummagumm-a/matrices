cmake_minimum_required(VERSION 3.19)
project(AGLA_II)

set(CMAKE_CXX_STANDARD 20)

add_executable(AGLA_II main.cpp
        Matrix.cpp Matrix.h
        SquareMatrix.cpp SquareMatrix.h
        Identity.cpp Identity.h
        EliminationMatrix.cpp EliminationMatrix.h
        )