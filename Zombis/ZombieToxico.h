#ifndef ZOMBIETOXICO_H
#define ZOMBIETOXICO_H

#include "../Entidades/Zombie.h"

class ZombieToxico : public Zombie {
private:
    int danioVeneno;
    int turnosVeneno;
    int plantasEnvenenadas;

public:
    ZombieToxico(int fila, int columna);
    ~ZombieToxico();

    void atacar(Entidad* objetivo) override;
    void habilidadPasiva() override;
    string obtenerSimbolo() const override;
    void mostrarInfo() const override;

    int obtenerDanioVeneno() const;
    int obtenerTurnosVeneno() const;
};

#endif