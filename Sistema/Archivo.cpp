#include "Archivo.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <algorithm>

Archivo::Archivo(string nombreArchivo) : nombreArchivo(nombreArchivo) {}

Archivo::~Archivo() {}

bool Archivo::archivoExiste() const {
    ifstream archivo(nombreArchivo);
    return archivo.good();
}

bool Archivo::guardarEstadistica(const Estadisticas& stats) {
    ofstream archivo(nombreArchivo, ios::app);

    if (!archivo.is_open()) {
        cerr << "❌ Error: No se pudo abrir el archivo " << nombreArchivo << endl;
        return false;
    }

    archivo << stats.convertirATexto() << endl;
    archivo.close();

    cout << "✅ Estadisticas guardadas correctamente" << endl;
    return true;
}

vector<Estadisticas> Archivo::cargarEstadisticas() {
    vector<Estadisticas> estadisticas;
    ifstream archivo(nombreArchivo);

    if (!archivo.is_open()) {
        return estadisticas; // Retorna vector vacio
    }

    string linea;
    string nombreJugador, fecha, resultado;
    int oleadasCompletadas, oleadasTotales, zombiesEliminados, solesFinales, hpCasaFinal;
    bool victoria;

    while (getline(archivo, linea)) {
        if (linea.find("Jugador:") != string::npos) {
            nombreJugador = linea.substr(9); // Despues de "Jugador: "

            getline(archivo, linea); // Fecha
            fecha = linea.substr(7);

            getline(archivo, linea); // Resultado
            resultado = linea.substr(11);
            victoria = (resultado == "VICTORIA");

            getline(archivo, linea); // Oleadas
            size_t pos = linea.find(": ");
            string oleadas = linea.substr(pos + 2);
            size_t barraPos = oleadas.find("/");
            oleadasCompletadas = stoi(oleadas.substr(0, barraPos));
            oleadasTotales = stoi(oleadas.substr(barraPos + 1));

            getline(archivo, linea); // Zombies
            pos = linea.find(": ");
            zombiesEliminados = stoi(linea.substr(pos + 2));

            getline(archivo, linea); // Soles
            pos = linea.find(": ");
            solesFinales = stoi(linea.substr(pos + 2));

            getline(archivo, linea); // HP Casa
            pos = linea.find(": ");
            hpCasaFinal = stoi(linea.substr(pos + 2));

            // Crear objeto Estadisticas y agregarlo al vector
            Estadisticas stats(nombreJugador, victoria, oleadasCompletadas,
                             oleadasTotales, zombiesEliminados, solesFinales, hpCasaFinal);
            estadisticas.push_back(stats);
        }
    }

    archivo.close();
    return estadisticas;
}

bool Archivo::limpiarArchivo() {
    ofstream archivo(nombreArchivo, ios::trunc);

    if (!archivo.is_open()) {
        cerr << "❌ Error: No se pudo limpiar el archivo" << endl;
        return false;
    }

    archivo.close();
    cout << "✅ Historial limpiado correctamente" << endl;
    return true;
}

void Archivo::mostrarHistorial() const {
    ifstream archivo(nombreArchivo);

    if (!archivo.is_open()) {
        cout << "\n(No hay partidas registradas)\n" << endl;
        return;
    }

    cout << "\n╔════════════════════════════════════════════════════════╗" << endl;
    cout << "║              📊 HISTORIAL DE PARTIDAS 📊               ║" << endl;
    cout << "╚════════════════════════════════════════════════════════╝\n" << endl;

    string linea;
    while (getline(archivo, linea)) {
        cout << linea << endl;
    }

    archivo.close();
}

void Archivo::mostrarTop10() const {
    vector<Estadisticas> stats = const_cast<Archivo*>(this)->cargarEstadisticas();

    if (stats.empty()) {
        cout << "\n(No hay partidas registradas)\n" << endl;
        return;
    }

    // Ordenar por puntos (mayor a menor)
    sort(stats.begin(), stats.end(), [](const Estadisticas& a, const Estadisticas& b) {
        return a.obtenerPuntosTotales() > b.obtenerPuntosTotales();
    });

    cout << "\n╔════════════════════════════════════════════════════════╗" << endl;
    cout << "║                🏆 TOP 10 JUGADORES 🏆                  ║" << endl;
    cout << "╚════════════════════════════════════════════════════════╝\n" << endl;

    int limite = (stats.size() < 10) ? stats.size() : 10;

    cout << left << setw(5) << "#"
         << setw(20) << "Jugador"
         << setw(15) << "Puntos"
         << setw(12) << "Oleadas"
         << setw(10) << "Resultado" << endl;
    cout << "------------------------------------------------------------" << endl;

    for (int i = 0; i < limite; i++) {
        cout << left << setw(5) << (i + 1)
             << setw(20) << stats[i].obtenerNombreJugador()
             << setw(15) << stats[i].obtenerPuntosTotales()
             << setw(12) << (to_string(stats[i].obtenerOleadasCompletadas()) + "/" +
                            to_string(stats[i].obtenerOleadasTotales()))
             << setw(10) << (stats[i].esVictoria() ? "✅" : "❌") << endl;
    }
    cout << endl;
}

int Archivo::contarPartidas() const {
    ifstream archivo(nombreArchivo);

    if (!archivo.is_open()) {
        return 0;
    }

    int count = 0;
    string linea;

    while (getline(archivo, linea)) {
        if (linea.find("Jugador:") != string::npos) {
            count++;
        }
    }

    archivo.close();
    return count;
}

Estadisticas Archivo::obtenerMejorPuntuacion() const {
    vector<Estadisticas> stats = const_cast<Archivo*>(this)->cargarEstadisticas();

    if (stats.empty()) {
        return Estadisticas(); // Retorna estadistica vacia
    }

    Estadisticas mejor = stats[0];
    for (size_t i = 1; i < stats.size(); i++) {
        if (stats[i] > mejor) {
            mejor = stats[i];
        }
    }

    return mejor;
}