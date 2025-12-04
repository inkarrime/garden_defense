#ifndef ZOMBIERAPIDO_H
#define ZOMBIERAPIDO_H

#include "../Entidades/Zombie.h"

class ZombieRapido : public Zombie {
private:
    int turnosExtra;
    int contadorTurnosExtra;

public:
    ZombieRapido(int fila, int columna);
    ~ZombieRapido();

    void turno() override;
    void habilidadPasiva() override;
    string obtenerSimbolo() const override;
    void mostrarInfo() const override;
};

#endif