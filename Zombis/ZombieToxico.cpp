#include "ZombieToxico.h"
#include <iomanip>

ZombieToxico::ZombieToxico(int fila, int columna)
    : Zombie("Zombi Toxico", 90, 10, 1, fila, columna),
      danioVeneno(2), turnosVeneno(3), plantasEnvenenadas(0) {}

ZombieToxico::~ZombieToxico() {}

void ZombieToxico::atacar(Entidad* objetivo) {
    if (!viva || !objetivo || !objetivo->estaViva()) return;

    Zombie::atacar(objetivo);
    cout << "💀 " << nombre << " envenena a " << objetivo->obtenerNombre()
         << " (" << danioVeneno << " danio x " << turnosVeneno << " turnos)!" << endl;
    plantasEnvenenadas++;
}

void ZombieToxico::habilidadPasiva() {
    if (!viva) return;
    // El veneno se aplica al atacar
}

string ZombieToxico::obtenerSimbolo() const {
    return "💀";
}

void ZombieToxico::mostrarInfo() const {
    cout << left << setw(20) << nombre
         << " | Danio: " << right << setw(3) << danio
         << " | Veneno: " << danioVeneno << " x " << turnosVeneno << " turnos"
         << " | HP: " << setw(3) << hp << "/" << setw(3) << hpMaximo << endl;
}

int ZombieToxico::obtenerDanioVeneno() const {
    return danioVeneno;
}

int ZombieToxico::obtenerTurnosVeneno() const {
    return turnosVeneno;
}