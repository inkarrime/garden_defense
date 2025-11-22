#ifndef ZOMBIE_H
#define ZOMBIE_H

#include "Entidad.h"

class Zombie : public Entidad {
protected:
    int danio;
    int velocidad; // Turnos necesarios para avanzar
    int contadorMovimiento;

public:
    Zombie(string nombre, int hp, int danio, int velocidad, int fila, int columna);
    virtual ~Zombie();

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