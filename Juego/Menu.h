#ifndef MENU_H
#define MENU_H

#include <iostream>
using namespace std;

class Menu {
public:
    // Constructor
    Menu();

    // Destructor
    ~Menu();

    // Método principal
    static int mostrarMenu();
    static int mostrarMenuParaSalir();
};

#endif // MENU_H