#include "Juego/Juego.h"
#include <iostream>

#ifdef _WIN32
    #include <windows.h>
#endif

using namespace std;

int main() {
#ifdef _WIN32
    // Configurar consola para UTF-8 en Windows
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif

    Juego juego;
    juego.iniciar();
    return 0;
}