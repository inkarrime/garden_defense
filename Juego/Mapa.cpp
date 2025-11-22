#include "Mapa.h"
#include <iostream>
#include <iomanip>

Mapa::Mapa() : hpCasa(300), hpMaxCasa(300) {
    // Inicializar matriz de plantas en nullptr
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            plantas[i][j] = nullptr;
        }
    }
}

Mapa::~Mapa() {
    // Liberar memoria de plantas
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            if (plantas[i][j] != nullptr) {
                delete plantas[i][j];
                plantas[i][j] = nullptr;
            }
        }
    }

    // Liberar memoria de zombies
    for (size_t i = 0; i < zombies.size(); i++) {
        delete zombies[i];
    }
    zombies.clear();
}

void Mapa::limpiarPantalla() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void Mapa::mostrarBorde() {
    cout << "================================================================" << endl;
}

void Mapa::mostrarEncabezado(int oleada, int soles) {
    cout << left << setw(25) << "  DEFENSA DEL JARDIN"
         << " | Oleada: " << right << setw(2) << oleada << "/10"
         << " | Soles: " << setw(4) << soles << " ☀️"
         << " | HP Casa: ";

    // Mostrar corazones segun HP
    int corazones = (hpCasa * 5) / hpMaxCasa; // De 0 a 5 corazones
    for (int i = 0; i < corazones; i++) {
        cout << "❤️";
    }
    for (int i = corazones; i < 5; i++) {
        cout << "🖤";
    }
    cout << " (" << hpCasa << ")" << endl;
}

void Mapa::mostrarCuadricula() {
    // Encabezado de columnas
    cout << "\n    ";
    for (int j = 0; j < COLUMNAS; j++) {
        cout << "  " << j << " ";
    }
    cout << endl;

    // Borde superior
    cout << "  ┌";
    for (int j = 0; j < COLUMNAS; j++) {
        cout << "───";
        if (j < COLUMNAS - 1) cout << "┬";
    }
    cout << "┐" << endl;

    // Filas con contenido
    for (int i = 0; i < FILAS; i++) {
        cout << i + 1 << " │";

        for (int j = 0; j < COLUMNAS; j++) {
            // Verificar si hay planta
            if (plantas[i][j] != nullptr) {
                cout << " " << plantas[i][j]->obtenerSimbolo() << " ";
            }
            // Verificar si hay zombi
            else {
                bool hayZombie = false;
                for (size_t z = 0; z < zombies.size(); z++) {
                    if (zombies[z]->obtenerFila() == i &&
                        zombies[z]->obtenerColumna() == j &&
                        zombies[z]->estaViva()) {
                        cout << " " << zombies[z]->obtenerSimbolo() << " ";
                        hayZombie = true;
                        break;
                    }
                }
                if (!hayZombie) {
                    cout << "   ";
                }
            }

            if (j < COLUMNAS - 1) cout << "│";
        }

        // Casa al final de cada fila
        cout << "│🏠│" << endl;

        // Borde entre filas
        if (i < FILAS - 1) {
            cout << "  ├";
            for (int j = 0; j < COLUMNAS; j++) {
                cout << "───";
                if (j < COLUMNAS - 1) cout << "┼";
            }
            cout << "┤" << endl;
        }
    }

    // Borde inferior
    cout << "  └";
    for (int j = 0; j < COLUMNAS; j++) {
        cout << "───";
        if (j < COLUMNAS - 1) cout << "┴";
    }
    cout << "┘" << endl;
}

void Mapa::mostrarAcciones() {
    cout << "\n[1] Plantar  [2] Eliminar  [3] Siguiente Turno  [4] Menu Principal" << endl;
}

void Mapa::mostrar(int oleada, int soles) {
    limpiarPantalla();
    mostrarBorde();
    mostrarEncabezado(oleada, soles);
    mostrarBorde();
    mostrarCuadricula();
    mostrarAcciones();
}

bool Mapa::posicionValida(int fila, int columna) const {
    return (fila >= 0 && fila < FILAS && columna >= 0 && columna < COLUMNAS);
}

bool Mapa::casillaVacia(int fila, int columna) const {
    if (!posicionValida(fila, columna)) return false;
    return plantas[fila][columna] == nullptr;
}

bool Mapa::colocarPlanta(Planta* planta, int fila, int columna) {
    if (!posicionValida(fila, columna)) {
        cout << "❌ Posicion invalida!" << endl;
        return false;
    }

    if (!casillaVacia(fila, columna)) {
        cout << "❌ Ya hay una planta en esa posicion!" << endl;
        return false;
    }

    plantas[fila][columna] = planta;
    planta->establecerPosicion(fila, columna);
    cout << "✅ " << planta->obtenerNombre() << " plantado en (" << fila + 1 << "," << columna << ")" << endl;
    return true;
}

bool Mapa::eliminarPlanta(int fila, int columna) {
    if (!posicionValida(fila, columna)) {
        cout << "❌ Posicion invalida!" << endl;
        return false;
    }

    if (plantas[fila][columna] == nullptr) {
        cout << "❌ No hay planta en esa posicion!" << endl;
        return false;
    }

    cout << "🗑️  " << plantas[fila][columna]->obtenerNombre() << " eliminado" << endl;
    delete plantas[fila][columna];
    plantas[fila][columna] = nullptr;
    return true;
}

void Mapa::agregarZombie(Zombie* zombie) {
    zombies.push_back(zombie);
    cout << "🧟 " << zombie->obtenerNombre() << " aparece en fila " << zombie->obtenerFila() + 1 << "!" << endl;
}

Planta* Mapa::obtenerPlanta(int fila, int columna) const {
    if (!posicionValida(fila, columna)) return nullptr;
    return plantas[fila][columna];
}

void Mapa::turnosPlantas(int& soles) {
    cout << "\n--- TURNO DE PLANTAS ---" << endl;

    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            if (plantas[i][j] != nullptr && plantas[i][j]->estaViva()) {
                plantas[i][j]->turno();

                // Si es girasol, generar soles
                Girasol* girasol = dynamic_cast<Girasol*>(plantas[i][j]);
                if (girasol != nullptr) {
                    soles += girasol->obtenerSolesGenerados();
                }
            }
        }
    }
}

void Mapa::turnosZombies() {
    cout << "\n--- TURNO DE ZOMBIS ---" << endl;

    for (size_t i = 0; i < zombies.size(); i++) {
        if (zombies[i]->estaViva()) {
            zombies[i]->turno();
        }
    }
}

void Mapa::procesarColisiones() {
    cout << "\n--- PROCESANDO COLISIONES ---" << endl;

    for (size_t z = 0; z < zombies.size(); z++) {
        if (!zombies[z]->estaViva()) continue;

        int filaZ = zombies[z]->obtenerFila();
        int colZ = zombies[z]->obtenerColumna();

        // Si el zombi llega a la columna -1, ataca la casa
        if (colZ < 0) {
            int danio = zombies[z]->obtenerDanio();
            daniarCasa(danio);
            zombies[z]->recibirDanio(999); // Eliminar zombi
            continue;
        }

        // Verificar colision con planta
        if (posicionValida(filaZ, colZ) && plantas[filaZ][colZ] != nullptr) {
            Planta* planta = plantas[filaZ][colZ];

            if (planta->estaViva()) {
                cout << "💥 Colision: " << zombies[z]->obtenerNombre()
                     << " ataca a " << planta->obtenerNombre() << endl;
                zombies[z]->atacar(planta);

                // Verificar si es cactus para aplicar daño por contacto
                Cactus* cactus = dynamic_cast<Cactus*>(planta);
                if (cactus != nullptr && cactus->estaViva()) {
                    cactus->aplicarDanioContacto(zombies[z]);
                }

                // Verificar si es ajo para desviar
                Ajo* ajo = dynamic_cast<Ajo*>(planta);
                if (ajo != nullptr && ajo->estaViva()) {
                    ajo->desviarZombie();
                    // Cambiar fila del zombi (arriba o abajo aleatoriamente)
                    int nuevaFila = filaZ + (rand() % 2 == 0 ? 1 : -1);
                    if (nuevaFila >= 0 && nuevaFila < FILAS) {
                        zombies[z]->establecerPosicion(nuevaFila, colZ);
                    }
                }
            }
        }
    }
}

void Mapa::limpiarMuertos() {
    // Eliminar plantas muertas
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            if (plantas[i][j] != nullptr && !plantas[i][j]->estaViva()) {
                cout << "💀 " << plantas[i][j]->obtenerNombre() << " ha muerto" << endl;
                delete plantas[i][j];
                plantas[i][j] = nullptr;
            }
        }
    }

    // Eliminar zombies muertos
    for (int i = zombies.size() - 1; i >= 0; i--) {
        if (!zombies[i]->estaViva()) {
            cout << "💀 " << zombies[i]->obtenerNombre() << " ha sido eliminado" << endl;
            delete zombies[i];
            zombies.erase(zombies.begin() + i);
        }
    }
}

int Mapa::obtenerHPCasa() const {
    return hpCasa;
}

bool Mapa::casaDestruida() const {
    return hpCasa <= 0;
}

bool Mapa::todosZombiesMuertos() const {
    return zombies.empty();
}

int Mapa::contarZombiesVivos() const {
    int count = 0;
    for (size_t i = 0; i < zombies.size(); i++) {
        if (zombies[i]->estaViva()) {
            count++;
        }
    }
    return count;
}

void Mapa::daniarCasa(int danio) {
    hpCasa -= danio;
    if (hpCasa < 0) hpCasa = 0;

    cout << "🏠 LA CASA RECIBE " << danio << " DE DAÑO! HP: " << hpCasa << "/" << hpMaxCasa << endl;

    if (casaDestruida()) {
        cout << "\n💥💥💥 LA CASA HA SIDO DESTRUIDA! 💥💥💥" << endl;
    }
}