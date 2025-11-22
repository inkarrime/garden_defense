#ifndef ZOMBIEARDIENTE_H
#define ZOMBIEARDIENTE_H

#include "../Entidades/Zombie.h"

class ZombieArdiente : public Zombie {
private:
    int danioFuego;
    int plantasDaniadas;

public:
    ZombieArdiente(int fila, int columna);
    ~ZombieArdiente();

    void habilidadPasiva() override;
    string obtenerSimbolo() const override;
    void mostrarInfo() const override;

    int obtenerDanioFuego() const;
    void incrementarPlantasDaniadas();
};

#endif