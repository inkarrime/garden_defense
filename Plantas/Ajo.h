#ifndef AJO_H
#define AJO_H

#include "../Entidades/Planta.h"

class Ajo : public Planta {
private:
    int zombiesDesviados;
    bool activado;

public:
    Ajo(int fila, int columna);
    ~Ajo();

    void atacar() override;
    void habilidadPasiva() override;
    string obtenerSimbolo() const override;
    void mostrarInfo() const override;

    void desviarZombie();
    bool estaActivado() const;
};

#endif