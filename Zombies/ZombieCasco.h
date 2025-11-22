#ifndef ZOMBIECASCO_H
#define ZOMBIECASCO_H

#include "../Entidades/Zombie.h"

class ZombieCasco : public Zombie {
private:
    int armadura;
    int ataquesSoportados;
    int maxAtaquesSoportados;

public:
    ZombieCasco(int fila, int columna);
    ~ZombieCasco();

    void recibirDanio(int danio); // Sobrescribe para aplicar armadura
    void habilidadPasiva() override;
    string obtenerSimbolo() const override;
    void mostrarInfo() const override;
};

#endif