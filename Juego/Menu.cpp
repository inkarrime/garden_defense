#include "Menu.h"

// Constructor
Menu::Menu() {}

// Destructor
Menu::~Menu() {}

int Menu::mostrarMenu() {
    int opcion;
    cout << "===== DEFENSA DEL JARDÍN =====\n\n";
    cout<<"Menú principal:\n";
    cout<<"1. Jugar\n";
    cout<<"2. Ver estadísticas\n";
    cout<<"3. Salir\n\n";
    cout<<"Selecciona una opcion: ";
    cin >> opcion;

    return opcion;
}