#include "FlorAura.h"
#include <iomanip>

FlorAura::FlorAura(int fila, int columna)
    : Planta("Flor de Aura", 90, 100, 0, 0, fila, columna),
      bonoAtaque(10), radioAura(1) {
    turnosParaAtacar = 0; // No ataca directamente
}

FlorAura::~FlorAura() {}

void FlorAura::atacar() {
    // La flor no ataca, da bono a otras plantas
}

void FlorAura::habilidadPasiva() {
    if (!viva) return;
    cout << "🌺 " << nombre << " emite un aura de poder (+10% danio a plantas cercanas)" << endl;
    // El bono se aplicara en el Mapa
}

string FlorAura::obtenerSimbolo() const {
    return "🌺";
}

void FlorAura::mostrarInfo() const {
    cout << left << setw(20) << nombre
         << " | Costo: " << right << setw(3) << costo
         << " soles | Bono: +" << bonoAtaque << "% danio"
         << " | Radio: " << radioAura
         << " | HP: " << setw(3) << hp << "/" << setw(3) << hpMaximo << endl;
}

int FlorAura::obtenerBonoAtaque() const {
    return bonoAtaque;
}

int FlorAura::obtenerRadioAura() const {
    return radioAura;
}