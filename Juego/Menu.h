#ifndef MENU_H
#define MENU_H
#include <iostream>
#include <string>
using namespace std;

class Menu {
private:
    void limpiarPantalla();
    void mostrarTitulo();
    void mostrarOpciones();
    int leerOpcion();

public:
    void mostrar();
    int obtenerSeleccion();
};


#endif //MENU_H