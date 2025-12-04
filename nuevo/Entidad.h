#ifndef ENTIDAD_H
#define ENTIDAD_H

#include <iostream>
#include <string>
using namespace std;

class Entidad {
protected:
    string nombre;
    int hp;
    int fila;
    int columna;
    string simbolo;

public:
    // Constructor
    Entidad(string nombre, int hp, int fila, int columna, string simbolo);

    // Destructor virtual
    virtual ~Entidad();

    // Metodos virtuales
    virtual void mostrarInfo() const;

    // Getters
    string obtenerNombre() const;
    int obtenerHP() const;
    int obtenerFila() const;
    int obtenerColumna() const;
    char obtenerSimbolo() const;

    // Setters
    virtual void recibirDanio(int danio);

    bool estaVivo() const;
};

#endif