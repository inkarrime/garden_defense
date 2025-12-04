#ifndef JUEGO_H
#define JUEGO_H

#include "Menu.h"
#include "Partida.h"

using namespace std;

class Juego {
private:
    Menu menu;
    Partida partida;

    // Metodos privados
    void iniciarPartida();
    void mostrarEstadisticas();
    void salir();

public:
    // Constructor
    Juego();

    // Destructor
    ~Juego();

    // Metodo
    void ejecutar();
};

#endif