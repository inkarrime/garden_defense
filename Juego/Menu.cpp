#include "Menu.h"

// Constructor
Menu::Menu() = default;

// Destructor
Menu::~Menu() = default;

int Menu::mostrarMenu() {
    int inputDelUsuario;
    cout << "===== DEFENSA DEL JARDÍN =====\n\n";
    cout<<"Menú principal:\n";
    cout<<"1. Jugar\n";
    cout<<"2. Ver estadísticas\n";
    cout<<"3. Salir\n\n";
    cout<<"Selecciona una opción: ";
    cin >> inputDelUsuario;

    return inputDelUsuario;
}
int Menu::mostrarMenuParaSalir() {
    int inputDelUsuario;
    cout << "\n======== SALIR DEL JUEGO ========\n\n";
    cout << "¿Estas seguro que quieres salir del juego?\n\n";
    cout<<"1. Sí, quiero salir\n";
    cout<<"2. No, quiero regresar al Menú\n\n";
    cout<<"Selecciona una opción: ";
    cin>>inputDelUsuario;
    return inputDelUsuario;
}
