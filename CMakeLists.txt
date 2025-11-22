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
        Entidades/Zombie.cpp
        Entidades/Zombie.h
        Plantas/Girasol.cpp
        Plantas/Girasol.h
        Plantas/Cactus.cpp
        Plantas/Cactus.h
        Zombies/ZombieCasco.cpp
        Zombies/ZombieCasco.h
        Zombies/ZombieRapido.cpp
        Zombies/ZombieRapido.h
        Plantas/PlantaHielo.cpp
        Plantas/PlantaHielo.h
        Plantas/Ajo.cpp
        Plantas/Ajo.h
        Plantas/SetaDefensiva.cpp
        Plantas/SetaDefensiva.h
        Plantas/FlorAura.cpp
        Plantas/FlorAura.h
        Zombies/ZombieArdiente.cpp
        Zombies/ZombieArdiente.h
        Zombies/ZombieCongelado.cpp
        Zombies/ZombieCongelado.h
        Zombies/ZombieGordo.cpp
        Zombies/ZombieGordo.h
        Zombies/ZombieToxico.cpp
        Zombies/ZombieToxico.h
        Juego/Mapa.cpp
        Juego/Mapa.h
        Sistema/Estadisticas.cpp
        Sistema/Estadisticas.h
        Sistema/Archivo.cpp
        Sistema/Archivo.h
        Juego/Oleada.cpp
        Juego/Oleada.h)
