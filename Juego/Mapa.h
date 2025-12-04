#ifndef MAPA_H
#define MAPA_H

#include <iostream>
using namespace std;

class Mapa {
private:
    static const int FILAS = 5;
    static const int COLUMNAS = 9;
    string tablero[5][9];

    void inicializarMapa();

public:
    // Constructor
    Mapa();

    // Destructor
    ~Mapa();

    // Mostrar el mapa en consola
    void mostrarMapa() const;

    // Getters para las dimensiones
    int getFilas() const;
    int getColumnas() const;
};

#endif // MAPA_H