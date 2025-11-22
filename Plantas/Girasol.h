#ifndef GIRASOL_H
#define GIRASOL_H

#include "../Entidades/Planta.h"

class Girasol : public Planta {
private:
    int solesGenerados;
    int turnosParaGenerar;
    int contadorGeneracion;

public:
    Girasol(int fila, int columna);
    ~Girasol();

    void atacar() override; // No ataca, genera soles
    void habilidadPasiva() override;
    string obtenerSimbolo() const override;
    void mostrarInfo() const override;

    int obtenerSolesGenerados() const;
};


#endif //GIRASOL_H