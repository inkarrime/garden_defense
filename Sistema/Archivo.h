#ifndef ARCHIVO_H
#define ARCHIVO_H

#include "Estadisticas.h"
#include <string>
#include <vector>

using namespace std;

class Archivo {
private:
    string nombreArchivo;

public:
    Archivo(string nombreArchivo = "historial.txt");
    ~Archivo();

    // Métodos principales
    bool guardarEstadistica(const Estadisticas& stats);
    vector<Estadisticas> cargarEstadisticas();
    bool archivoExiste() const;
    bool limpiarArchivo();

    // Utilidades
    void mostrarHistorial() const;
    void mostrarTop10() const;
    int contarPartidas() const;
    Estadisticas obtenerMejorPuntuacion() const;
};

#endif