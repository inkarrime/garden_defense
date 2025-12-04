#ifndef ZOMBIEGORDO_H
#define ZOMBIEGORDO_H

#include "../Entidades/Zombie.h"

class ZombieGordo : public Zombie {
private:
    int regeneracion;

public:
    ZombieGordo(int fila, int columna);
    ~ZombieGordo();

    void habilidadPasiva() override;
    string obtenerSimbolo() const override;
    void mostrarInfo() const override;
};

#endif