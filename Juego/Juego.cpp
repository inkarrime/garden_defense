#include "Juego.h"
#include <iostream>

Juego::Juego() : ejecutando(true), nombreJugador("") {}

void Juego::pedirNombreJugador() {
    cout << "\nIngrese su nombre: ";
    getline(cin, nombreJugador);
    cout << "\nBienvenido, " << nombreJugador << "!\n";
    cout << "\nPresione Enter para continuar...";
    cin.get();
}

void Juego::jugar() {
    pedirNombreJugador();
    cout << "\n[Iniciando partida...]\n";
    cout << "\n(Funcionalidad en desarrollo)\n";
    cout << "\nPresione Enter para volver al menu...";
    cin.get();
}

void Juego::verEstadisticas() {
    cout << "\n===========================================\n";
    cout << "    ESTADISTICAS\n";
    cout << "===========================================\n\n";
    cout << "(Sin partidas registradas)\n";
    cout << "\nPresione Enter para volver al menu...";
    cin.get();
}

void Juego::salir() {
    cout << "\nGracias por jugar. Hasta pronto!\n\n";
    ejecutando = false;
}

void Juego::iniciar() {
    while (ejecutando) {
        int opcion = menu.obtenerSeleccion();

        switch (opcion) {
            case 1:
                jugar();
                break;
            case 2:
                verEstadisticas();
                break;
            case 3:
                salir();
                break;
        }
    }
}