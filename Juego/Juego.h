#ifndef JUEGO_H
#define JUEGO_H

#include "Menu.h"
#include "Partida.h"

using namespace std;

class Juego {
private:
    Menu menu;
    Partida partida;

    // Métodos privados
    void iniciarPartida();
    void mostrarStats();
    void salirDelJuego() ;

public:
    // Constructor
    Juego();

    // Destructor
    ~Juego();

    // Método
    void ejecutar() ;
};

#endif