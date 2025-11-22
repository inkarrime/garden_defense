#ifndef ZOMBIECONGELADO_H
#define ZOMBIECONGELADO_H

#include "../Entidades/Zombie.h"

class ZombieCongelado : public Zombie {
private:
    bool inmunidadHielo;

public:
    ZombieCongelado(int fila, int columna);
    ~ZombieCongelado();

    void habilidadPasiva() override;
    string obtenerSimbolo() const override;
    void mostrarInfo() const override;

    bool tieneInmunidadHielo() const;
};

#endif