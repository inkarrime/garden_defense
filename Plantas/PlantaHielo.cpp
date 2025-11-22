#include "PlantaHielo.h"
#include <iomanip>

PlantaHielo::PlantaHielo(int fila, int columna)
    : Planta("Planta de Hielo", 120, 150, 15, 3, fila, columna),
      ralentizacion(1), radioEfecto(1) {
    turnosParaAtacar = 2;
}

PlantaHielo::~PlantaHielo() {}

void PlantaHielo::atacar() {
    if (!viva) return;
    cout << "❄️  " << nombre << " lanza un ataque congelante!" << endl;
}

void PlantaHielo::habilidadPasiva() {
    if (!viva) return;
    cout << "❄️  " << nombre << " emite un aura de congelacion (ralentiza zombies cercanos)" << endl;
    // La ralentizacion se aplicara en el Mapa
}

string PlantaHielo::obtenerSimbolo() const {
    return "❄️";
}

void PlantaHielo::mostrarInfo() const {
    cout << left << setw(20) << nombre
         << " | Costo: " << right << setw(3) << costo
         << " soles | Danio: " << setw(3) << danio
         << " | Ralentiza: +" << ralentizacion << " turno"
         << " | HP: " << setw(3) << hp << "/" << setw(3) << hpMaximo << endl;
}

int PlantaHielo::obtenerRalentizacion() const {
    return ralentizacion;
}

int PlantaHielo::obtenerRadioEfecto() const {
    return radioEfecto;
}