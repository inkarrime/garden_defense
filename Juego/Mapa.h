#ifndef MAPA_H
#define MAPA_H

#include <vector>
#include <string>
using namespace std;

class Mapa {
private:
    int filas;
    int columnas;
    vector<vector<char>> casillas;

    void inicializarCasillas();
    void dibujarBordeSuperior() const;
    void dibujarBordeInferior() const;
    void dibujarFila(int numFila) const;

public:
    Mapa();
    Mapa(int f, int c);
    ~Mapa();

    void mostrarMapa() const;
    void reiniciar(int f, int c);
    void limpiar();

    bool colocarPlanta(int fila, int col, char simbolo);
    bool eliminarPlanta(int fila, int col);
    bool colocarZombi(int fila, int col, char simbolo);
    bool eliminarZombi(int fila, int col);

    int getFilas() const;
    int getColumnas() const;
    char getCasilla(int fila, int col) const;
    bool casillaVacia(int fila, int col) const;
    bool tienePlantas() const; // NUEVO: verificar si hay plantas
};

#endif