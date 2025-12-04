cmake_minimum_required(VERSION 4.0)
project(garden_defense)

set(CMAKE_CXX_STANDARD 14)

add_executable(garden_defense main.cpp
        Juego/Juego.h
        Juego/Juego.cpp
        Juego/Menu.h
        Juego/Menu.cpp
        Juego/Partida.h
        Juego/Partida.cpp
        Juego/Mapa.h
        Juego/Mapa.cpp
)
