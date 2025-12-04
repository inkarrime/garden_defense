#include "ZombieGordo.h"
#include <iomanip>

ZombieGordo::ZombieGordo(int fila, int columna)
    : Zombie("Zombie Gordo", 200, 8, 2, fila, columna),
      regeneracion(1) {}

ZombieGordo::~ZombieGordo() {}

void ZombieGordo::habilidadPasiva() {
    if (!viva || hp >= hpMaximo) return;

    hp += regeneracion;
    if (hp > hpMaximo) {
        hp = hpMaximo;
    }
    cout << "🍔 " << nombre << " se regenera +" << regeneracion << " HP (HP: "
         << hp << "/" << hpMaximo << ")" << endl;
}

string ZombieGordo::obtenerSimbolo() const {
    return "🍔";
}

void ZombieGordo::mostrarInfo() const {
    cout << left << setw(20) << nombre
         << " | Danio: " << right << setw(3) << danio
         << " | Regen: +" << regeneracion << " HP/turno"
         << " | HP: " << setw(3) << hp << "/" << setw(3) << hpMaximo << endl;
}