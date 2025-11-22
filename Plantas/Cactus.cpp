#include "Cactus.h"
#include <iomanip>

Cactus::Cactus(int fila, int columna)
    : Planta("Cactus", 150, 125, 10, 1, fila, columna),
      danioContacto(15), zombiesEliminados(0) {
    turnosParaAtacar = 2; // Ataca cada 2 turnos
}

Cactus::~Cactus() {}

void Cactus::atacar() {
    if (!viva) return;
    cout << "🌵 " << nombre << " lanza espinas!" << endl;
}

void Cactus::habilidadPasiva() {
    // El daño por contacto se maneja cuando un zombie toca al cactus
}

void Cactus::aplicarDanioContacto(Entidad* zombie) {
    if (!viva || !zombie || !zombie->estaViva()) return;

    cout << "🌵 " << nombre << " daña al zombie por contacto (" << danioContacto << " danio)!" << endl;
    *zombie -= danioContacto;

    if (!zombie->estaViva()) {
        zombiesEliminados++;
    }
}

string Cactus::obtenerSimbolo() const {
    return "🌵";
}

void Cactus::mostrarInfo() const {
    cout << left << setw(20) << nombre
         << " | Costo: " << right << setw(3) << costo
         << " soles | Danio: " << setw(3) << danio
         << " | HP: " << setw(3) << hp << "/" << setw(3) << hpMaximo
         << " | Eliminados: " << zombiesEliminados << endl;
}