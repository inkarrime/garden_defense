#include "Juego.h"
#include <iostream>
#include <fstream>

// Constructor
Juego::Juego() = default;

// Destructor
Juego::~Juego() = default;

// Iniciar una partida
void Juego::iniciarPartida() {
    partida.jugar();
}

// Mostrar estadísticas guardadas
void Juego::mostrarStats() {
    ifstream archivo("stats.txt");

    cout << "\n======== ESTADÍSTICAS ========\n\n";

    if (!archivo.is_open()) {
        cout << "No hay partidas registradas aún.\n";
        cout << "¡Juega una partida para crear tu historial!\n\n";
    } else {
        string linea;
        while (getline(archivo, linea)) {
            cout << linea << "\n";
        }
        archivo.close();
    }
    cout << "Presiona Enter para volver al menu...\n";
    cin.ignore();
    cin.get();
}

void Juego::salirDelJuego() {
    int inputDelUsuario2;
    do {
        inputDelUsuario2 = menu.mostrarMenuParaSalir();
        switch (inputDelUsuario2) {
            case 1:
                cout << "\n¡Gracias por jugar Defensa del Jardin!\n";
                cout << "Hasta pronto...\n";
                exit(0);
            case 2:
                cout<<"Regresando al menu...\n";
                return;
            default:
                cout << "\nOpción inválida. Intente nuevamente.\n\n";
                cout << "Presione Enter para continuar...";
                cin.ignore();
                cin.get();
                break;
        }
    } while (inputDelUsuario2 != 1 && inputDelUsuario2 != 2);
}

// Método principal
void Juego::ejecutar() {
    int inputUsuario;

    do {
        inputUsuario = menu.mostrarMenu();

        switch (inputUsuario) {
            case 1:
                iniciarPartida();
                break;

            case 2:
                mostrarStats();
                break;

            case 3:
                salirDelJuego();
                inputUsuario = 0;
                break;

            default:
                cout << "\nOpción inválida. Intente nuevamente.\n";
                cout << "\nPresione Enter para continuar...";
                break;
        }
    } while (inputUsuario != 3);
}