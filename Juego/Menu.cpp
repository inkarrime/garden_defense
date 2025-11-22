#include "Menu.h"
#include <limits>

void Menu::limpiarPantalla() {
    // Multiplataforma básico
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void Menu::mostrarTitulo() {
    cout << "\n===========================================\n";
    cout << "    DEFENSA DEL JARDIN\n";
    cout << "===========================================\n\n";
}

void Menu::mostrarOpciones() {
    cout << "1. Jugar\n";
    cout << "2. Ver Estadisticas\n";
    cout << "3. Salir\n\n";
}

int Menu::leerOpcion() {
    int opcion;
    cout << "Seleccione una opcion: ";
    cin >> opcion;

    // Validar entrada
    while (cin.fail() || opcion < 1 || opcion > 3) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Opcion invalida. Intente nuevamente: ";
        cin >> opcion;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return opcion;
}

void Menu::mostrar() {
    limpiarPantalla();
    mostrarTitulo();
    mostrarOpciones();
}

int Menu::obtenerSeleccion() {
    mostrar();
    return leerOpcion();
}