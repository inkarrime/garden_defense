#ifndef CACTUS_H
#define CACTUS_H

#include "../Entidades/Planta.h"

class Cactus : public Planta {
private:
    int danioContacto;
    int zombisEliminados;

public:
    Cactus(int fila, int columna);
    ~Cactus();

    void atacar() override;
    void habilidadPasiva() override;
    string obtenerSimbolo() const override;
    void mostrarInfo() const override;
    void aplicarDanioContacto(Entidad* zombi);
};

#endif