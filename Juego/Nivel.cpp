#include "Nivel.h"

Nivel::Nivel(int nivel) : numeroNivel(nivel), columnas(9) {
    // Configuración progresiva según el nivel
    if (nivel == 1) {
        filas = 1;
        zombisPorOleada = 5;  // Máximo 5 zombis en nivel 1
        solesIniciales = 150;
    } else if (nivel == 2) {
        filas = 3;
        zombisPorOleada = 7;
        solesIniciales = 200;
    } else { // Nivel 3 en adelante
        filas = 5;
        zombisPorOleada = 8 + (nivel - 3) * 2; // Incrementa dificultad
        solesIniciales = 250;
    }
}

int Nivel::getNumeroNivel() const { return numeroNivel; }
int Nivel::getFilas() const { return filas; }
int Nivel::getColumnas() const { return columnas; }
int Nivel::getZombisPorOleada() const { return zombisPorOleada; }
int Nivel::getSolesIniciales() const { return solesIniciales; }