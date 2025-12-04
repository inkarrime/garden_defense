#ifndef PARTIDA_H
#define PARTIDA_H

#include "Mapa.h"
#include <string>
using namespace std;

// Gestiona una sesión completa de juego
class Partida {
private:
    Mapa mapa;

    // Datos de la partida
    string nombreJugador;
    int oleadaActual;
    int soles;
    int hpCasa;
    int zombisEliminados;
    bool gano;

    // Metodos privados
    void solicitarNombre();
    void fasePreparacion();
    void faseOleada();
    void mostrarEstado();
    void guardarEstadisticas();

public:
    // Constructor
    Partida();

    // Destructor
    ~Partida();

    // Ejecutar la partida completa
    void jugar();
};

#endif