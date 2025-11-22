#ifndef JUEGO_H
#define JUEGO_H

#include "Menu.h"
#include <string>

class Juego {
private:
    Menu menu;
    string nombreJugador;
    bool ejecutando;

    void jugar();
    void verEstadisticas();
    void salir();
    void pedirNombreJugador();

public:
    Juego();
    void iniciar();
};

#endif