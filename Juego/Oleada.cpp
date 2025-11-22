#include "Oleada.h"
#include <iostream>
#include <iomanip>

Oleada::Oleada(int numeroOleada) : numeroOleada(numeroOleada), cantidadZombies(0) {
    // Calcular cantidad de zombies segun la oleada
    // Formula: 2 + (numeroOleada * 2)
    // Oleada 1: 4 zombies
    // Oleada 2: 6 zombies
    // Oleada 3: 8 zombies
    // ...
    // Oleada 10: 22 zombies
    cantidadZombies = 2 + (numeroOleada * 2);
}

Oleada::~Oleada() {
    // Los zombies se liberan en el Mapa, no aqui
    zombiesGenerados.clear();
}

Zombie* Oleada::crearZombieAleatorio(int fila) {
    // Probabilidad de aparicion segun oleada
    int tipoZombie;

    if (numeroOleada <= 2) {
        // Oleadas 1-2: Solo zombies basicos y rapidos
        tipoZombie = rand() % 3; // 0-2
    } else if (numeroOleada <= 5) {
        // Oleadas 3-5: Incluye zombies con casco
        tipoZombie = rand() % 4; // 0-3
    } else if (numeroOleada <= 7) {
        // Oleadas 6-7: Incluye todos menos toxico
        tipoZombie = rand() % 5; // 0-4
    } else {
        // Oleadas 8-10: Todos los tipos
        tipoZombie = rand() % 6; // 0-5
    }

    // Columna inicial (aparecen en la ultima columna)
    int columna = 8;

    switch(tipoZombie) {
        case 0:
            return new ZombieRapido(fila, columna);
        case 1:
            return new ZombieCongelado(fila, columna);
        case 2:
            return new ZombieCasco(fila, columna);
        case 3:
            return new ZombieArdiente(fila, columna);
        case 4:
            return new ZombieGordo(fila, columna);
        case 5:
            return new ZombieToxico(fila, columna);
        default:
            return new ZombieRapido(fila, columna);
    }
}

void Oleada::generarZombiesAleatorios() {
    zombiesGenerados.clear();

    for (int i = 0; i < cantidadZombies; i++) {
        int filaAleatoria = rand() % 5; // 0-4 (5 filas)
        Zombie* zombie = crearZombieAleatorio(filaAleatoria);
        zombiesGenerados.push_back(zombie);
    }
}

void Oleada::generar() {
    cout << "\n";
    cout << "╔════════════════════════════════════════════════════════╗" << endl;
    cout << "║           🧟 OLEADA " << setw(2) << numeroOleada << " SE APROXIMA! 🧟          ║" << endl;
    cout << "╚════════════════════════════════════════════════════════╝" << endl;

    generarZombiesAleatorios();
    mostrarInformacion();
}

vector<Zombie*> Oleada::obtenerZombies() {
    return zombiesGenerados;
}

int Oleada::obtenerNumero() const {
    return numeroOleada;
}

int Oleada::obtenerCantidadZombies() const {
    return cantidadZombies;
}

void Oleada::mostrarInformacion() const {
    cout << "\n📊 Informacion de la oleada:" << endl;
    cout << "   Numero de oleada: " << numeroOleada << "/10" << endl;
    cout << "   Zombies totales: " << cantidadZombies << endl;

    // Contar tipos de zombies
    int casco = 0, rapido = 0, ardiente = 0, congelado = 0, gordo = 0, toxico = 0;

    for (size_t i = 0; i < zombiesGenerados.size(); i++) {
        if (dynamic_cast<ZombieCasco*>(zombiesGenerados[i])) casco++;
        else if (dynamic_cast<ZombieRapido*>(zombiesGenerados[i])) rapido++;
        else if (dynamic_cast<ZombieArdiente*>(zombiesGenerados[i])) ardiente++;
        else if (dynamic_cast<ZombieCongelado*>(zombiesGenerados[i])) congelado++;
        else if (dynamic_cast<ZombieGordo*>(zombiesGenerados[i])) gordo++;
        else if (dynamic_cast<ZombieToxico*>(zombiesGenerados[i])) toxico++;
    }

    cout << "\n   Composicion:" << endl;
    if (rapido > 0) cout << "   ⚡ Zombies Rapidos: " << rapido << endl;
    if (congelado > 0) cout << "   🧊 Zombies Congelados: " << congelado << endl;
    if (casco > 0) cout << "   🧱 Zombies con Casco: " << casco << endl;
    if (ardiente > 0) cout << "   🔥 Zombies Ardientes: " << ardiente << endl;
    if (gordo > 0) cout << "   🍔 Zombies Gordos: " << gordo << endl;
    if (toxico > 0) cout << "   💀 Zombies Toxicos: " << toxico << endl;

    cout << "\n⚠️  Preparate para defender el jardin!" << endl;
}