#ifndef PLANTA_H
#define PLANTA_H

#include "Entidad.h"

class Planta : public Entidad {
protected:
    int danio;
    int costo;

public:
    // Constructor
    Planta(string nombre, int hp, int danio, int costo, int fila, int columna, string simbolo);

    // Destructor virtual
    virtual ~Planta();

    // Getters
    int getDanio() const;
    int getCosto() const;

    // Método virtual puro
    virtual void atacar() = 0;

    // Override de mostrarInfo
    void mostrarInfo() const override;
};

// GIRASOL
class Girasol : public Planta {
private:
    int solesGenerados;

public:
    Girasol(int fila, int columna);
    ~Girasol();

    int getSolesGenerados() const;
    void atacar() override;
};

// LANZAGUISANTES
class Lanzaguisantes : public Planta {
public:
    Lanzaguisantes(int fila, int columna);
    ~Lanzaguisantes();

    void atacar() override;
};

#endif