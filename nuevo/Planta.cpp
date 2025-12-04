#include "../Planta.h"

// Constructor
Planta::Planta(string nombre, int hp, int danio, int costo, int fila, int columna, char simbolo)
    : Entidad(nombre, hp, fila, columna, simbolo), danio(danio), costo(costo) {}

// Destructor
Planta::~Planta() {}

// Getters
int Planta::getDanio() const {
    return danio;
}

int Planta::getCosto() const {
    return costo;
}

// Override de mostrarInfo
void Planta::mostrarInfo() const {
    Entidad::mostrarInfo();
    cout << " | Danio: " << danio << " | Costo: " << costo;
}

// ==================== IMPLEMENTACIÓN GIRASOL ====================

Girasol::Girasol(int fila, int columna)
    : Planta("Girasol", 80, 0, 50, fila, columna, '🌻'), solesGenerados(25) {}

Girasol::~Girasol() {}

int Girasol::getSolesGenerados() const {
    return solesGenerados;
}

void Girasol::atacar() {
    cout << nombre << " genera " << solesGenerados << " soles!" << endl;
}

// ==================== IMPLEMENTACIÓN LANZAGUISANTES ====================

Lanzaguisantes::Lanzaguisantes(int fila, int columna)
    : Planta("Lanzaguisantes", 100, 20, 100, fila, columna, "🌿") {}

Lanzaguisantes::~Lanzaguisantes() {}

void Lanzaguisantes::atacar() {
    cout << nombre << " dispara! Danio: " << danio << endl;
}