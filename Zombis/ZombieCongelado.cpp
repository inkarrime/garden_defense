#include "ZombieCongelado.h"
#include <iomanip>

ZombieCongelado::ZombieCongelado(int fila, int columna)
    : Zombie("Zombi Congelado", 110, 11, 1, fila, columna),
      inmunidadHielo(true) {}

ZombieCongelado::~ZombieCongelado() {}

void ZombieCongelado::habilidadPasiva() {
    // La inmunidad es pasiva
}

string ZombieCongelado::obtenerSimbolo() const {
    return "🧊";
}

void ZombieCongelado::mostrarInfo() const {
    cout << left << setw(20) << nombre
         << " | Danio: " << right << setw(3) << danio
         << " | Inmune: HIELO"
         << " | HP: " << setw(3) << hp << "/" << setw(3) << hpMaximo << endl;
}

bool ZombieCongelado::tieneInmunidadHielo() const {
    return inmunidadHielo;
}