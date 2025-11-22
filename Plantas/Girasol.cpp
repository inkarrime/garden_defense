#include "Girasol.h"
#include <iomanip>

Girasol::Girasol(int fila, int columna)
    : Planta("Girasol", 80, 50, 0, 0, fila, columna),
      solesGenerados(25), turnosParaGenerar(2), contadorGeneracion(0) {}

Girasol::~Girasol() {}

void Girasol::atacar() {
    // El girasol no ataca
}

void Girasol::habilidadPasiva() {
    if (!viva) return;

    contadorGeneracion++;
    if (contadorGeneracion >= turnosParaGenerar) {
        cout << "☀️  " << nombre << " genera " << solesGenerados << " soles!" << endl;
        // Los soles se agregaran al total en el Juego
        contadorGeneracion = 0;
    }
}

string Girasol::obtenerSimbolo() const {
    return "🌻";
}

void Girasol::mostrarInfo() const {
    cout << left << setw(20) << nombre
         << " | Costo: " << right << setw(3) << costo
         << " soles | Genera: " << setw(3) << solesGenerados
         << " | HP: " << setw(3) << hp << "/" << setw(3) << hpMaximo << endl;
}

int Girasol::obtenerSolesGenerados() const {
    return solesGenerados;
}