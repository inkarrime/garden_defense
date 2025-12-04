#ifndef ZOMBI_H
#define ZOMBI_H

#include "Entidad.h"

class Zombi : public Entidad {
protected:
    int danio;
    int velocidad;
    int posicionInterna;

public:
    // Constructor
    Zombi(string nombre, int hp, int danio, int velocidad, int fila, int columna, char simbolo);

    // Destructor virtual
    virtual ~Zombi();

    // Getters
    int getDanio() const;
    int getVelocidad() const;
    int getPosicionInterna() const;

    // Métodos virtuales
    virtual void mover();
    virtual void atacar(Entidad* objetivo);

    // Override de mostrarInfo
    void mostrarInfo() const override;
};

// ZOMBI BASICO
class ZombiBasico : public Zombi {
public:
    ZombiBasico(int fila, int columna);
    ~ZombiBasico();
};

// ZOMBI CON CASCO
class ZombiCasco : public Zombi {
private:
    int armadura;
    bool tieneArmadura;

public:
    ZombiCasco(int fila, int columna);
    ~ZombiCasco();

    // Override para aplicar reducción de daño por armadura
    void recibirDanio(int danio);

    int getArmadura() const;
    bool tieneArmaduraActiva() const;
};

#endif