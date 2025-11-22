#ifndef ESTADISTICAS_H
#define ESTADISTICAS_H

#include <string>
#include <ctime>

using namespace std;

class Estadisticas {
private:
    string nombreJugador;
    string fecha;
    bool victoria;
    int oleadasCompletadas;
    int oleadasTotales;
    int zombiesEliminados;
    int solesFinales;
    int hpCasaFinal;
    int puntosTotales;

    void calcularPuntos();
    string obtenerFechaActual();

public:
    Estadisticas();
    Estadisticas(string nombreJugador, bool victoria, int oleadasCompletadas,
                 int oleadasTotales, int zombiesEliminados, int solesFinales, int hpCasaFinal);
    ~Estadisticas();

    // Getters
    string obtenerNombreJugador() const;
    string obtenerFecha() const;
    bool esVictoria() const;
    int obtenerOleadasCompletadas() const;
    int obtenerOleadasTotales() const;
    int obtenerZombiesEliminados() const;
    int obtenerSolesFinales() const;
    int obtenerHPCasaFinal() const;
    int obtenerPuntosTotales() const;

    // Métodos
    void mostrar() const;
    string convertirATexto() const;

    // Sobrecarga de operadores
    friend ostream& operator<<(ostream& os, const Estadisticas& stats);
    bool operator>(const Estadisticas& otra) const; // Comparar por puntos
};

#endif