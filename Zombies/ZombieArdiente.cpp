#include "ZombieArdiente.h"
#include <iomanip>

ZombieArdiente::ZombieArdiente(int fila, int columna)
    : Zombie("Zombie Ardiente", 120, 12, 1, fila, columna),
      danioFuego(1), plantasDaniadas(0) {}

ZombieArdiente::~ZombieArdiente() {}

void ZombieArdiente::habilidadPasiva() {
    if (!viva) return;
    cout << "🔥 " << nombre << " emite un aura de fuego (danio a plantas adyacentes)" << endl;
    // El danio se aplicara en el Mapa
}

string ZombieArdiente::obtenerSimbolo() const {
    return "🔥";
}

void ZombieArdiente::mostrarInfo() const {
    cout << left << setw(20) << nombre
         << " | Danio: " << right << setw(3) << danio
         << " | Fuego: " << danioFuego << " HP/turno"
         << " | HP: " << setw(3) << hp << "/" << setw(3) << hpMaximo << endl;
}

int ZombieArdiente::obtenerDanioFuego() const {
    return danioFuego;
}

void ZombieArdiente::incrementarPlantasDaniadas() {
    plantasDaniadas++;
}