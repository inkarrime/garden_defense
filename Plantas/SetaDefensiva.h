#ifndef SETADEFENSIVA_H
#define SETADEFENSIVA_H

#include "../Entidades/Planta.h"

class SetaDefensiva : public Planta {
private:
    int regeneracion;
    int turnosRegeneracion;

public:
    SetaDefensiva(int fila, int columna);
    ~SetaDefensiva();

    void atacar() override;
    void habilidadPasiva() override;
    string obtenerSimbolo() const override;
    void mostrarInfo() const override;
};

#endif