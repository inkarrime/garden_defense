#ifndef PARTIDA_H
#define PARTIDA_H

#include "Mapa.h"
#include "Nivel.h"
#include <string>
#include <vector>
using namespace std;

// Estructura para representar un zombi
struct Zombi {
    int fila;
    int columna;
    char simbolo;
    int hp;
    int danio;     // NUEVO: Daño que hace por turno
    bool vivo;

    Zombi(int f, int c) : fila(f), columna(c), simbolo('Z'), hp(100), danio(25), vivo(true) {}
};

// Estructura para representar una planta
struct Planta {
    int fila;
    int columna;
    char simbolo;
    int turnoPlantado;
    int hp;        // NUEVO: Puntos de vida
    int hpMax;     // NUEVO: Vida máxima

    Planta(int f, int c, char s, int turno)
        : fila(f), columna(c), simbolo(s), turnoPlantado(turno), hp(100), hpMax(100) {}
};

class Partida {
private:
    Mapa mapa;
    Nivel* nivelActual;
    vector<Zombi> zombis;
    vector<Planta> plantas;
    int zombisRestantes;
    int turnoActual;

    string nombreJugador;
    int nivelNumero;
    int soles;
    int zombisEliminados;
    bool gano;
    bool casaInvadida;

    // Métodos privados
    void solicitarNombre();
    void inicializarNivel(int numeroNivel);
    void mostrarHeader();
    void mostrarEstadoCompleto();
    void mostrarInformacionEntidades(); // NUEVO: Mostrar info de plantas y zombis
    void faseAcciones();
    void plantarPlanta();
    void desplantarPlanta();
    void faseOleada();
    void generarNuevosZombis();
    void zombisAtacan();               // NUEVO: Zombis atacan plantas
    void moverZombis();
    void actualizarMapaZombis();
    void ejecutarHabilidadesPlantas();
    void habilidadGirasol(const Planta& planta);
    void habilidadLanzaguisantes(Planta& planta);
    void guardarEstadisticas();

public:
    Partida();
    ~Partida();
    void jugar();
};

#endif