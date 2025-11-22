cmake_minimum_required(VERSION 4.0)
project(garden_defense)

set(CMAKE_CXX_STANDARD 14)

add_executable(garden_defense main.cpp
        Juego/Menu.cpp
        Juego/Menu.h
        Juego/Juego.cpp
        Juego/Juego.h
        Entidades/Entidad.cpp
        Entidades/Entidad.h
        Entidades/Planta.cpp
        Entidades/Planta.h
        Entidades/Zombi.cpp
        Entidades/Zombi.h
        Plantas/Girasol.cpp
        Plantas/Girasol.h
        Plantas/Cactus.cpp
        Plantas/Cactus.h)
