#ifndef ZOMBI_H
#define ZOMBI_H

#include "Entidad.h"

class Zombi : public Entidad {
protected:
    int danio;
    int velocidad; // Turnos necesarios para avanzar
    int contadorMovimiento;

public:
    Zombi(string nombre, int hp, int danio, int velocidad, int fila, int columna);
    virtual ~Zombi();

    // Metodos virtuales
    virtual void mover();
    virtual void atacar(Entidad* objetivo);
    virtual void habilidadPasiva();
    void turno() override;
    void mostrarInfo() const override;

    // Getters
    int obtenerDanio() const;
    int obtenerVelocidad() const;
};

#endif