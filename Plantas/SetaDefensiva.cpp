#include "SetaDefensiva.h"
#include <iomanip>

SetaDefensiva::SetaDefensiva(int fila, int columna)
    : Planta("Seta Defensiva", 180, 75, 5, 1, fila, columna),
      regeneracion(1), turnosRegeneracion(0) {
    turnosParaAtacar = 3;
}

SetaDefensiva::~SetaDefensiva() {}

void SetaDefensiva::atacar() {
    if (!viva) return;
    cout << "🍄 " << nombre << " lanza esporas toxicas!" << endl;
}

void SetaDefensiva::habilidadPasiva() {
    if (!viva || hp >= hpMaximo) return;

    turnosRegeneracion++;
    if (turnosRegeneracion >= 1) {
        curar(regeneracion);
        cout << "🍄 " << nombre << " se regenera +" << regeneracion << " HP" << endl;
        turnosRegeneracion = 0;
    }
}

string SetaDefensiva::obtenerSimbolo() const {
    return "🍄";
}

void SetaDefensiva::mostrarInfo() const {
    cout << left << setw(20) << nombre
         << " | Costo: " << right << setw(3) << costo
         << " soles | Regen: +" << regeneracion << " HP/turno"
         << " | HP: " << setw(3) << hp << "/" << setw(3) << hpMaximo << endl;
}