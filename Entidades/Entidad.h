#ifndef ENTIDAD_H
#define ENTIDAD_H

#include <string>
#include <iostream>
using namespace std;

class Entidad {
protected:
    string nombre;
    int hp;
    int hpMaximo;
    int fila;
    int columna;
    bool viva;

public:
    Entidad(string nombre, int hp, int fila, int columna);
    virtual ~Entidad();

    // Metodos virtuales puros (polimorfismo)
    virtual void mostrarInfo() const = 0;
    virtual string obtenerSimbolo() const = 0;
    virtual void turno() = 0;

    // Getters
    string obtenerNombre() const;
    int obtenerHP() const;
    int obtenerHPMaximo() const;
    int obtenerFila() const;
    int obtenerColumna() const;
    bool estaViva() const;

    // Setters
    void establecerPosicion(int fila, int columna);
    void recibirDanio(int danio);
    void curar(int cantidad);

    // Sobrecarga de operadores
    friend ostream& operator<<(ostream& os, const Entidad& entidad);
    Entidad& operator-=(int danio); // Aplicar daño
};

#endif