#ifndef PLANTA_H
#define PLANTA_H

#include "Entidad.h"

class Planta : public Entidad {
protected:
    int costo;
    int danio;
    int alcance;
    int turnosParaAtacar;
    int contadorTurnos;

public:
    Planta(string nombre, int hp, int costo, int danio, int alcance, int fila, int columna);
    virtual ~Planta();

    // Metodos virtuales
    virtual void atacar() = 0;
    virtual void habilidadPasiva();
    void turno() override;
    void mostrarInfo() const override;

    // Getters
    int obtenerCosto() const;
    int obtenerDanio() const;
    int obtenerAlcance() const;
};

#endif