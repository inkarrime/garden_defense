#ifndef FLORAURA_H
#define FLORAURA_H

#include "../Entidades/Planta.h"

class FlorAura : public Planta {
private:
    int bonoAtaque; // Porcentaje de bono
    int radioAura;

public:
    FlorAura(int fila, int columna);
    ~FlorAura();

    void atacar() override;
    void habilidadPasiva() override;
    string obtenerSimbolo() const override;
    void mostrarInfo() const override;

    int obtenerBonoAtaque() const;
    int obtenerRadioAura() const;
};

#endif