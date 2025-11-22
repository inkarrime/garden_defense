#ifndef PLANTAHIELO_H
#define PLANTAHIELO_H

#include "../Entidades/Planta.h"

class PlantaHielo : public Planta {
private:
    int ralentizacion; // Turnos adicionales para zombies
    int radioEfecto;

public:
    PlantaHielo(int fila, int columna);
    ~PlantaHielo();

    void atacar() override;
    void habilidadPasiva() override;
    string obtenerSimbolo() const override;
    void mostrarInfo() const override;

    int obtenerRalentizacion() const;
    int obtenerRadioEfecto() const;
};

#endif