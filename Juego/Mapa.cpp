#include "Mapa.h"
#include <iostream>
#include <iomanip>

using namespace std;

// Constructor por defecto (5x9)
Mapa::Mapa() : filas(5), columnas(9) {
    inicializarCasillas();
}

// Constructor con dimensiones específicas
Mapa::Mapa(int f, int c) : filas(f), columnas(c) {
    inicializarCasillas();
}

// Destructor
Mapa::~Mapa() {
    // vector se encarga de liberar memoria automáticamente
}

// Inicializar matriz de casillas vacías
void Mapa::inicializarCasillas() {
    casillas.clear();
    casillas.resize(filas, vector<char>(columnas, ' '));
}

// Reiniciar el mapa con nuevas dimensiones
void Mapa::reiniciar(int f, int c) {
    filas = f;
    columnas = c;
    inicializarCasillas();
}

// Limpiar todas las casillas
void Mapa::limpiar() {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            casillas[i][j] = ' ';
        }
    }
}

// Dibujar borde superior del mapa
void Mapa::dibujarBordeSuperior() const {
    cout << "   "; // Espaciado para números de fila
    for (int j = 0; j < columnas; j++) {
        cout << "  " << j + 1 << " ";
    }
    cout << "\n   ";

    cout << "┌";
    for (int j = 0; j < columnas - 1; j++) {
        cout << "───┬";
    }
    cout << "───┐\n";
}

// Dibujar borde inferior del mapa
void Mapa::dibujarBordeInferior() const {
    cout << "   └";
    for (int j = 0; j < columnas - 1; j++) {
        cout << "───┴";
    }
    cout << "───┘\n";
}

// Dibujar una fila específica del mapa
void Mapa::dibujarFila(int numFila) const {
    // Número de fila
    cout << " " << numFila + 1 << " │";

    // Contenido de las casillas
    for (int j = 0; j < columnas; j++) {
        cout << " ";

        // Mostrar contenido de la casilla
        if (casillas[numFila][j] == ' ') {
            cout << "·"; // Casilla vacía con punto central
        } else {
            cout << casillas[numFila][j];
        }

        cout << " │";
    }
    cout << "\n";

    // Línea separadora entre filas (excepto la última)
    if (numFila < filas - 1) {
        cout << "   ├";
        for (int j = 0; j < columnas - 1; j++) {
            cout << "───┼";
        }
        cout << "───┤\n";
    }
}

// Mostrar el mapa completo en consola
void Mapa::mostrarMapa() const {
    cout << "\n";
    dibujarBordeSuperior();

    for (int i = 0; i < filas; i++) {
        dibujarFila(i);
    }

    dibujarBordeInferior();
    cout << "\n";
}

// Colocar una planta en una casilla
bool Mapa::colocarPlanta(int fila, int col, char simbolo) {
    // Validar coordenadas
    if (fila < 0 || fila >= filas || col < 0 || col >= columnas) {
        return false;
    }

    // Verificar que la casilla esté vacía
    if (casillas[fila][col] != ' ') {
        return false;
    }

    casillas[fila][col] = simbolo;
    return true;
}

// Eliminar una planta de una casilla
bool Mapa::eliminarPlanta(int fila, int col) {
    // Validar coordenadas
    if (fila < 0 || fila >= filas || col < 0 || col >= columnas) {
        return false;
    }

    // Solo eliminar si hay algo
    if (casillas[fila][col] == ' ') {
        return false;
    }

    casillas[fila][col] = ' ';
    return true;
}

// Colocar un zombi en una casilla
bool Mapa::colocarZombi(int fila, int col, char simbolo) {
    // Validar coordenadas
    if (fila < 0 || fila >= filas || col < 0 || col >= columnas) {
        return false;
    }

    // Los zombis pueden superponerse con plantas (combate)
    casillas[fila][col] = simbolo;
    return true;
}

// Eliminar un zombi de una casilla
bool Mapa::eliminarZombi(int fila, int col) {
    return eliminarPlanta(fila, col); // Misma lógica
}

// Getters
int Mapa::getFilas() const {
    return filas;
}

int Mapa::getColumnas() const {
    return columnas;
}

char Mapa::getCasilla(int fila, int col) const {
    if (fila < 0 || fila >= filas || col < 0 || col >= columnas) {
        return '\0'; // Caracter nulo si está fuera de rango
    }
    return casillas[fila][col];
}

bool Mapa::casillaVacia(int fila, int col) const {
    if (fila < 0 || fila >= filas || col < 0 || col >= columnas) {
        return false;
    }
    return casillas[fila][col] == ' ';
}

bool Mapa::tienePlantas() const {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            if (casillas[i][j] != ' ') {
                return true; // Hay al menos una planta
            }
        }
    }
    return false; // No hay plantas
}