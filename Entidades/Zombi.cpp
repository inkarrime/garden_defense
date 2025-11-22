#include "Zombi.h"
#include <iomanip>

Zombi::Zombi(string nombre, int hp, int danio, int velocidad, int fila, int columna)
    : Entidad(nombre, hp, fila, columna), danio(danio),
      velocidad(velocidad), contadorMovimiento(0) {}

Zombi::~Zombi() {}

void Zombi::mover() {
    if (!viva) return;

    if (columna > 0) {
        columna--;
        cout << nombre << " avanza a la columna " << columna << endl;
    }
}

void Zombi::atacar(Entidad* objetivo) {
    if (!viva || !objetivo || !objetivo->estaViva()) return;

    cout << nombre << " ataca a " << objetivo->obtenerNombre() << " causando " << danio << " de danio!" << endl;
    *objetivo -= danio; // Usa sobrecarga de operador
}

void Zombi::habilidadPasiva() {
    // Por defecto no hace nada
}

void Zombi::turno() {
    if (!viva) return;

    habilidadPasiva();
    contadorMovimiento++;

    if (contadorMovimiento >= velocidad) {
        mover();
        contadorMovimiento = 0;
    }
}

void Zombi::mostrarInfo() const {
    cout << left << setw(20) << nombre
         << " | Danio: " << right << setw(3) << danio
         << " | Velocidad: " << setw(2) << velocidad
         << " | HP: " << setw(3) << hp << "/" << setw(3) << hpMaximo << endl;
}

int Zombi::obtenerDanio() const { return danio; }
int Zombi::obtenerVelocidad() const { return velocidad; }