#include "ZombieRapido.h"
#include <iomanip>

ZombieRapido::ZombieRapido(int fila, int columna)
    : Zombie("Zombie Rapido", 75, 8, 1, fila, columna),
      turnosExtra(3), contadorTurnosExtra(0) {}

ZombieRapido::~ZombieRapido() {}

void ZombieRapido::turno() {
    if (!viva) return;

    Zombie::turno(); // Turno normal

    // Cada 3 turnos, obtiene un turno extra
    contadorTurnosExtra++;
    if (contadorTurnosExtra >= turnosExtra) {
        cout << "⚡ " << nombre << " obtiene un turno extra!" << endl;
        mover(); // Se mueve una casilla adicional
        contadorTurnosExtra = 0;
    }
}

void ZombieRapido::habilidadPasiva() {
    // La velocidad extra es su habilidad pasiva
}

string ZombieRapido::obtenerSimbolo() const {
    return "⚡";
}

void ZombieRapido::mostrarInfo() const {
    cout << left << setw(20) << nombre
         << " | Danio: " << right << setw(3) << danio
         << " | Velocidad: RAPIDO"
         << " | HP: " << setw(3) << hp << "/" << setw(3) << hpMaximo << endl;
}