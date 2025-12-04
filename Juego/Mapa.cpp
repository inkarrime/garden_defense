#include "Mapa.h"
#include <iostream>
using namespace std;

// Constructor
Mapa::Mapa() {
    inicializarMapa();
}

// Destructor
Mapa::~Mapa() {}

// Inicializar el mapa vacío
void Mapa::inicializarMapa() {
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            if (j == 0) {
                tablero[i][j] = "🏠"; // Casa en la primera columna
            } else {
                tablero[i][j] = " · "; // Casilla vacía
            }
        }
    }
}

// Mostrar el mapa en consola
void Mapa::mostrarMapa() const {
    cout << "\n╔════════════════════════════════════════╗\n";
    cout << "║         CAMPO DE BATALLA               ║\n";
    cout << "╚════════════════════════════════════════╝\n\n";

    // Encabezado de columnas
    cout << "    ";
    for (int j = 0; j < COLUMNAS; j++) {
        cout << "  " << j << " ";
    }
    cout << "\n    ";
    for (int j = 0; j < COLUMNAS; j++) {
        cout << "----";
    }
    cout << "\n";

    // Mostrar cada fila
    for (int i = 0; i < FILAS; i++) {
        cout << " " << i << " |";
        for (int j = 0; j < COLUMNAS; j++) {
            cout << " " << tablero[i][j];
        }
        cout << "\n";
    }
    cout << "\n";
}

// Getters
int Mapa::getFilas() const {
    return FILAS;
}

int Mapa::getColumnas() const {
    return COLUMNAS;
}