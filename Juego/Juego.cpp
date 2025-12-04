#include "Juego.h"
#include <iostream>
#include <fstream>

// Constructor
Juego::Juego() {}

// Destructor
Juego::~Juego() {}

// Iniciar una partida
void Juego::iniciarPartida() {
    Partida partida;
    Partida.jugar();
}

// Mostrar estadisticas guardadas
void Juego::mostrarEstadisticas() {
    ifstream archivo("estadisticas.txt");

    cout << "\n======== ESTADISTICAS ========\n\n";

    if (!archivo.is_open()) {
        cout << "No hay partidas registradas aun.\n";
        cout << "¡Juega una partida para crear tu historial!\n\n";
    } else {
        string linea;
        while (getline(archivo, linea)) {
            cout << linea << "\n";
        }
        archivo.close();
    }
}

// Metodo principal
void Juego::ejecutar() {
    int opcion;

    do {
        opcion = menu.mostrarMenu();

        switch (opcion) {
            case 1:
                iniciarPartida();
                break;

            case 2:
                mostrarEstadisticas();
                break;

            case 3:
                cout << "Gracias por jugar Defensa del Jardín\n";
                cout << "Hasta pronto...\n";
                break;

            default:
                cout << "\nOpcion invalida. Intente nuevamente.\n";
                cout << "\nPresione Enter para continuar...";
                break;
        }

    } while (opcion != 3);
}