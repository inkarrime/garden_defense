#ifndef JUEGO_H
#define JUEGO_H

#include "Menu.h"
#include "Mapa.h"
#include "Oleada.h"
#include "../Sistema/Estadisticas.h"
#include "../Sistema/Archivo.h"
#include <string>

class Juego {
private:
    Menu menu;
    Mapa* mapa;
    Archivo* archivo;
    string nombreJugador;
    bool ejecutando;

    // Estado del juego
    int oleadaActual;
    int oleadasTotales;
    int soles;
    int zombiesEliminados;
    bool enPartida;

    // Metodos privados
    void jugar();
    void verEstadisticas();
    void salir();
    void pedirNombreJugador();

    // Fase de preparacion
    void fasePreparacion();
    void menuPreparacion();
    void mostrarTiendasPlantas();
    void plantarPlanta();
    void eliminarPlantaMapa();

    // Fase de combate
    void faseCombate();
    void iniciarOleada();
    void ejecutarTurno();
    void verificarEstadoJuego();

    // Utilidades
    void limpiarPantalla();
    void pausar();
    void mostrarVictoria();
    void mostrarDerrota();
    void guardarEstadisticas(bool victoria);

public:
    Juego();
    ~Juego();
    void iniciar();
};

#endif