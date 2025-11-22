#include "Planta.h"
#include <iomanip>

Planta::Planta(string nombre, int hp, int costo, int danio, int alcance, int fila, int columna)
    : Entidad(nombre, hp, fila, columna), costo(costo), danio(danio),
      alcance(alcance), turnosParaAtacar(1), contadorTurnos(0) {}

Planta::~Planta() {}

void Planta::habilidadPasiva() {
    // Por defecto no hace nada, las subclases pueden sobrescribir
}

void Planta::turno() {
    if (!viva) return;

    contadorTurnos++;
    habilidadPasiva();

    if (contadorTurnos >= turnosParaAtacar) {
        atacar();
        contadorTurnos = 0;
    }
}

void Planta::mostrarInfo() const {
    cout << left << setw(20) << nombre
         << " | Costo: " << right << setw(3) << costo
         << " | Danio: " << setw(3) << danio
         << " | HP: " << setw(3) << hp << "/" << setw(3) << hpMaximo << endl;
}

int Planta::obtenerCosto() const { return costo; }
int Planta::obtenerDanio() const { return danio; }
int Planta::obtenerAlcance() const { return alcance; }