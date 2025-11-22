#include "ZombieCasco.h"
#include <iomanip>

ZombieCasco::ZombieCasco(int fila, int columna)
    : Zombie("Zombie Casco", 150, 15, 1, fila, columna),
      armadura(50), ataquesSoportados(0), maxAtaquesSoportados(3) {}

ZombieCasco::~ZombieCasco() {}

void ZombieCasco::recibirDanio(int danio) {
    if (ataquesSoportados < maxAtaquesSoportados) {
        int danioReducido = danio / 2; // Reduce 50% del daño
        ataquesSoportados++;
        cout << "🧱 " << nombre << " reduce el danio con su armadura! ("
             << danio << " -> " << danioReducido << ")" << endl;
        Entidad::recibirDanio(danioReducido);

        if (ataquesSoportados >= maxAtaquesSoportados) {
            cout << "🧱 La armadura de " << nombre << " se ha roto!" << endl;
        }
    } else {
        Entidad::recibirDanio(danio);
    }
}

void ZombieCasco::habilidadPasiva() {
    // La armadura es pasiva
}

string ZombieCasco::obtenerSimbolo() const {
    return "🧱";
}

void ZombieCasco::mostrarInfo() const {
    cout << left << setw(20) << nombre
         << " | Danio: " << right << setw(3) << danio
         << " | Armadura: " << (ataquesSoportados < maxAtaquesSoportados ? "SI" : "NO")
         << " | HP: " << setw(3) << hp << "/" << setw(3) << hpMaximo << endl;
}