#include "Entidad.h"
#include <iomanip>

Entidad::Entidad(string nombre, int hp, int fila, int columna) 
    : nombre(nombre), hp(hp), hpMaximo(hp), fila(fila), columna(columna), viva(true) {}

Entidad::~Entidad() {}

string Entidad::obtenerNombre() const { return nombre; }
int Entidad::obtenerHP() const { return hp; }
int Entidad::obtenerHPMaximo() const { return hpMaximo; }
int Entidad::obtenerFila() const { return fila; }
int Entidad::obtenerColumna() const { return columna; }
bool Entidad::estaViva() const { return viva; }

void Entidad::establecerPosicion(int fila, int columna) {
    this->fila = fila;
    this->columna = columna;
}

void Entidad::recibirDanio(int danio) {
    hp -= danio;
    if (hp <= 0) {
        hp = 0;
        viva = false;
    }
    cout << nombre << " recibe " << danio << " de danio. HP: " << hp << "/" << hpMaximo << endl;
}

void Entidad::curar(int cantidad) {
    hp += cantidad;
    if (hp > hpMaximo) {
        hp = hpMaximo;
    }
    cout << nombre << " se cura " << cantidad << " HP. HP: " << hp << "/" << hpMaximo << endl;
}

// Sobrecarga operator
ostream& operator<<(ostream& os, const Entidad& entidad) {
    os << left << setw(15) << entidad.nombre 
       << " | HP: " << right << setw(3) << entidad.hp << "/" << setw(3) << entidad.hpMaximo
       << " | Pos: (" << entidad.fila << "," << entidad.columna << ")";
    return os;
}

// Sobrecarga operator-=
Entidad& Entidad::operator-=(int danio) {
    recibirDanio(danio);
    return *this;
}