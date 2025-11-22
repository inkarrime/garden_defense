#include "Estadisticas.h"
#include <iostream>
#include <iomanip>
#include <sstream>

Estadisticas::Estadisticas()
    : nombreJugador(""), fecha(""), victoria(false),
      oleadasCompletadas(0), oleadasTotales(10), zombiesEliminados(0),
      solesFinales(0), hpCasaFinal(0), puntosTotales(0) {}

Estadisticas::Estadisticas(string nombreJugador, bool victoria, int oleadasCompletadas,
                           int oleadasTotales, int zombiesEliminados, int solesFinales, int hpCasaFinal)
    : nombreJugador(nombreJugador), victoria(victoria), oleadasCompletadas(oleadasCompletadas),
      oleadasTotales(oleadasTotales), zombiesEliminados(zombiesEliminados),
      solesFinales(solesFinales), hpCasaFinal(hpCasaFinal) {
    fecha = obtenerFechaActual();
    calcularPuntos();
}

Estadisticas::~Estadisticas() {}

string Estadisticas::obtenerFechaActual() {
    time_t ahora = time(0);
    tm* tiempoLocal = localtime(&ahora);

    stringstream ss;
    ss << setfill('0') << setw(2) << tiempoLocal->tm_mday << "/"
       << setfill('0') << setw(2) << (tiempoLocal->tm_mon + 1) << "/"
       << (tiempoLocal->tm_year + 1900) << " "
       << setfill('0') << setw(2) << tiempoLocal->tm_hour << ":"
       << setfill('0') << setw(2) << tiempoLocal->tm_min;

    return ss.str();
}

void Estadisticas::calcularPuntos() {
    puntosTotales = 0;

    // Puntos por oleadas completadas
    puntosTotales += oleadasCompletadas * 100;

    // Puntos por zombies eliminados
    puntosTotales += zombiesEliminados * 10;

    // Puntos por soles restantes
    puntosTotales += solesFinales;

    // Puntos por HP de casa restante
    puntosTotales += hpCasaFinal;

    // Bonus por victoria
    if (victoria) {
        puntosTotales += 1000;
    }
}

// Getters
string Estadisticas::obtenerNombreJugador() const { return nombreJugador; }
string Estadisticas::obtenerFecha() const { return fecha; }
bool Estadisticas::esVictoria() const { return victoria; }
int Estadisticas::obtenerOleadasCompletadas() const { return oleadasCompletadas; }
int Estadisticas::obtenerOleadasTotales() const { return oleadasTotales; }
int Estadisticas::obtenerZombiesEliminados() const { return zombiesEliminados; }
int Estadisticas::obtenerSolesFinales() const { return solesFinales; }
int Estadisticas::obtenerHPCasaFinal() const { return hpCasaFinal; }
int Estadisticas::obtenerPuntosTotales() const { return puntosTotales; }

void Estadisticas::mostrar() const {
    cout << "===========================================\n";
    cout << left << setw(20) << "Jugador:" << nombreJugador << "\n";
    cout << left << setw(20) << "Fecha:" << fecha << "\n";
    cout << left << setw(20) << "Resultado:" << (victoria ? "✅ VICTORIA" : "❌ DERROTA") << "\n";
    cout << left << setw(20) << "Oleadas:" << oleadasCompletadas << "/" << oleadasTotales << "\n";
    cout << left << setw(20) << "Zombies eliminados:" << zombiesEliminados << "\n";
    cout << left << setw(20) << "Soles finales:" << solesFinales << "\n";
    cout << left << setw(20) << "HP Casa final:" << hpCasaFinal << "\n";
    cout << left << setw(20) << "Puntos totales:" << puntosTotales << "\n";
    cout << "===========================================\n";
}

string Estadisticas::convertirATexto() const {
    stringstream ss;
    ss << "===========================================\n";
    ss << "Jugador: " << nombreJugador << "\n";
    ss << "Fecha: " << fecha << "\n";
    ss << "Resultado: " << (victoria ? "VICTORIA" : "DERROTA") << "\n";
    ss << "Oleadas completadas: " << oleadasCompletadas << "/" << oleadasTotales << "\n";
    ss << "Zombies eliminados: " << zombiesEliminados << "\n";
    ss << "Soles finales: " << solesFinales << "\n";
    ss << "HP Casa final: " << hpCasaFinal << "\n";
    ss << "Puntos totales: " << puntosTotales << "\n";
    ss << "===========================================\n";
    return ss.str();
}

// Sobrecarga de operadores
ostream& operator<<(ostream& os, const Estadisticas& stats) {
    os << stats.convertirATexto();
    return os;
}

bool Estadisticas::operator>(const Estadisticas& otra) const {
    return puntosTotales > otra.puntosTotales;
}