cmake_minimum_required(VERSION 3.28)
project(prj_trabalho)

set(CMAKE_CXX_STANDARD 17)

add_executable(prj_trabalho main.cpp
        Grafo.cpp
        Grafo.h
        Utils.cpp
        Utils.h
        Matriz.cpp
        Matriz.h
)
