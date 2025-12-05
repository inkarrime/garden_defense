#ifndef NIVEL_H
#define NIVEL_H

class Nivel {
private:
    int numeroNivel;
    int filas;
    int columnas;
    int zombisPorOleada;
    int solesIniciales;

public:
    // Constructor
    Nivel(int nivel);

    // Getters
    int getNumeroNivel() const;
    int getFilas() const;
    int getColumnas() const;
    int getZombisPorOleada() const;
    int getSolesIniciales() const;
};

#endif