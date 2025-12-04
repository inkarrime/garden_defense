#include "../Entidad.h"

// ==================== IMPLEMENTACIÓN ENTIDAD ====================

// Constructor
Entidad::Entidad(string nombre, int hp, int fila, int columna, string simbolo)
    : nombre(nombre), hp(hp), fila(fila), columna(columna), simbolo(simbolo) {}

// Destructor
Entidad::~Entidad() {}

// Getters
string Entidad::obtenerNombre() const {
    return nombre;
}

int Entidad::obtenerHP() const {
    return hp;
}

int Entidad::obtenerFila() const {
    return fila;
}

int Entidad::obtenerColumna() const {
    return columna;
}

char Entidad::obtenerSimbolo() const {
    return simbolo;
}

// Métodos
void Entidad::recibirDanio(int danio) {
    hp -= danio;  // RESTAR, no asignar
    if(hp < 0) hp = 0;
}

bool Entidad::estaVivo() const {
    return hp > 0;
}

void Entidad::mostrarInfo() const {
    cout << nombre << " - HP: " << hp << " Pos: [" << fila << "," << columna << "]";
}