#include "Ajo.h"
#include <iomanip>

Ajo::Ajo(int fila, int columna)
    : Planta("Ajo", 200, 50, 0, 0, fila, columna),
      zombiesDesviados(0), activado(false) {
    turnosParaAtacar = 0; // No ataca
}

Ajo::~Ajo() {}

void Ajo::atacar() {
    // El ajo no ataca, solo desvía
}

void Ajo::habilidadPasiva() {
    if (!viva) return;
    // La desviacion se activa cuando un zombie toca al ajo
}

void Ajo::desviarZombie() {
    cout << "🧄 " << nombre << " desvia a un zombie a otra fila!" << endl;
    zombiesDesviados++;
    activado = true;
}

string Ajo::obtenerSimbolo() const {
    return "🧄";
}

void Ajo::mostrarInfo() const {
    cout << left << setw(20) << nombre
         << " | Costo: " << right << setw(3) << costo
         << " soles | Efecto: Desvia zombies"
         << " | HP: " << setw(3) << hp << "/" << setw(3) << hpMaximo
         << " | Desviados: " << zombiesDesviados << endl;
}

bool Ajo::estaActivado() const {
    return activado;
}